#!/usr/bin/env python2

flag = raw_input('flag: ')
nums = [str(ord(c)) for c in flag]
encoded = ', '.join(nums)

print 'FLAG_LEN: ' + str(len(nums))
print 'flag: ' + encoded
