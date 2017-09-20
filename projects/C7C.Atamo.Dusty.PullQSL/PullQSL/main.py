import os
import shutil
import distutils.dir_util
import pkg_resources
import configparser
from tempfile import mkstemp

def replace_inline(file_path, pattern, subst):
    #Create temp file
    fh, abs_path = mkstemp()
    with os.fdopen(fh,'w') as new_file:
        with open(file_path) as old_file:
            for line in old_file:
                new_file.write(line.replace(pattern, subst))
    #Remove original file
    os.remove(file_path)
    #Move new file
    shutil.move(abs_path, file_path)

def main():

    ini_file = pkg_resources.resource_string('PullQSL.resources', 'paths.ini')

    config = configparser.ConfigParser(interpolation=configparser.ExtendedInterpolation())
    config.read_string(ini_file.decode('ascii'))

    source_base_dir = os.path.normpath(config['paths']['source'])
    assert(os.path.isdir(source_base_dir))

    dest_base_dir_list = [os.path.normpath(x) for k,x in config['destinations'].items()]
    for x in dest_base_dir_list:
        assert(os.path.isdir(x))

    target_dirs = ['sm_qsl', 'sm_clib\sm_clib']
    output_dirs = ['sm_qsl', 'sm_clib']

    for dest_base_dir in dest_base_dir_list:
        for target, output in zip(target_dirs, output_dirs):
            source_full = os.path.join(source_base_dir, target)
            dest_full = os.path.join(dest_base_dir, output)

            if os.path.exists(dest_full):
                shutil.rmtree(dest_full)
            os.makedirs(dest_full)

            distutils.dir_util.copy_tree(source_full, dest_full)

    update_files('.')

def update_files(base_dir):

    ini_file = pkg_resources.resource_string('PullQSL.resources', 'updates.ini')

    config = configparser.ConfigParser()
    config.read_string(ini_file.decode('ascii'))

    for sect in config:
        if sect == 'DEFAULT':
            continue

        file = config[sect]['file'].strip()
        file_path = os.path.join(base_dir, file)
        assert(os.path.exists(file_path))

        find = config[sect]['find'].strip()
        replace = config[sect]['replace'].strip()

        replace_inline(file_path, find, replace)

if __name__ == '__main__':
    main()
