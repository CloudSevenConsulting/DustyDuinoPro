import binascii

def main():

    compare_flash('./Analysis02/Verified.bin', './Analysis02/Check.bin')

def formate_byte_n_addr(addr, *args):
    row_format = "{:>8}" * (len(args) + 1)
    formatted_addr = '0x%0.4X' % addr
    formatted_args = [x.hex() for x in args]
    return row_format.format(formatted_addr, *formatted_args)


def print_byte_n_addr(addr, *args):

    row_format = "{:>10}" * (len(args) + 1)
    formatted_addr = '0x%0.4X' % addr
    formatted_args = [str(x) for x in args]
    print(formate_byte_n_addr(addr, *args))

    #print('0x%0.4X\t%s' % (addr, byte))

def compare_flash(first, second):

    byte_counter = 0
    outStr = ''

    with open(first, "rb") as fdOne, open(second, "rb") as fdTwo:

        byteOne = fdOne.read(1)
        byteTwo = fdTwo.read(1)

        if byteOne != byteTwo:
            outStr += formate_byte_n_addr(byte_counter, byteOne, byteTwo)
            outStr += '\n'
        else:
            #outStr += formate_byte_n_addr(byte_counter, byteOne, byteTwo)
            #outStr += '\n'
            pass

        byte_counter += 1

        while byteOne and byteTwo:


            # Do stuff with byte.
            byteOne = fdOne.read(1)
            byteTwo = fdTwo.read(1)

            if byteOne != byteTwo:
                outStr += formate_byte_n_addr(byte_counter, byteOne, byteTwo)
                outStr += '\n'
            else:
                #outStr += formate_byte_n_addr(byte_counter, byteOne, byteTwo)
                #outStr += '\n'
                pass

            byte_counter += 1

    with open('output.txt', 'w') as fd:
        fd.write(outStr)

if __name__ == '__main__':
    main()
