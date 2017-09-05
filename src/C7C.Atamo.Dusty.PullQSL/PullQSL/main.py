import os
import shutil
import distutils.dir_util
import pkg_resources
import configparser

def main():


    ini_file = pkg_resources.resource_string('PullQSL.resources', 'settings.ini')

    config = configparser.ConfigParser(interpolation=configparser.ExtendedInterpolation())
    config.read_string(ini_file.decode('ascii'))

    source_base_dir = os.path.normpath(config['paths']['source'])
    assert(os.path.isdir(source_base_dir))

    dest_base_dir = os.path.normpath(config['paths']['dest'])
    assert(os.path.isdir(dest_base_dir))

    target_dirs = ['sm_qsl', 'sm_clib/sm_clib/']
    for target in target_dirs:
        source_full = os.path.join(source_base_dir, target)
        dest_full = os.path.join(dest_base_dir, target)

        if os.path.exists(dest_full):
            shutil.rmtree(dest_full)
        os.makedirs(dest_full)

        distutils.dir_util.copy_tree(source_full, dest_full)

if __name__ == '__main__':
    main()
