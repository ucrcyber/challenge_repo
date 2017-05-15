#!/usr/bin/env python2

key = 'BACON' * 16

def xor(s1, s2):
    return ''.join(map(lambda t: chr(ord(t[0]) ^ ord(t[1])), zip(s1, s2)))

def main():
    secret_key = raw_input('secret key: ')
    flag = raw_input('flag: ')

    if len(flag) > 80:
        print 'flag should be 80 characters or less, or the `BACON` constant in rev1.c must be modified'
        return

    print 'secret key: ' + secret_key.encode('base64')
    print 'flag: ' + xor(flag, key).encode('hex').upper()

if __name__ == '__main__':
    main()
