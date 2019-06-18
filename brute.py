#!/usr/bin/python

from pwn import *
import struct
import subprocess
import sys


def run(payload):
    p = process('./bomb')
    addr = p.recv()
    p.sendline('Public speaking is very easy.\n')
    addr = p.recv()
    p.sendline('1 2 6 24 120 720\n')
    addr = p.recv()
    p.sendline('7 b 524\n')
    addr = p.recv()
    p.sendline('9\n')
    addr = p.recv()
    p.sendline('?05;=A\n')
    addr = p.recv()
    p.send(payload)
    addr = p.recv()
    if 'BOOM!!!' not in addr:
        with open('./found.txt','w') as found:
            found.write(payload)
        print payload
        sys.exit()
    p.close()
    return

for i1 in xrange(1,7):
    for i2 in [x for x in xrange(1,7) if x not in [i1]]:
        for i3 in [x for x in xrange(1,7) if x not in [i1,i2]]:
            for i4 in [x for x in xrange(1,7) if x not in [i1,i2,i3]]:
                for i5 in [x for x in xrange(1,7) if x not in [i1,i2,i3,i4]]:
                    for i6 in [x for x in xrange(1,7) if x not in [i1,i2,i3,i4,i5]]:
                        payload = str(i1) + ' ' +\
                        str(i2) + ' ' +\
                        str(i3) + ' ' +\
                        str(i4) + ' ' +\
                        str(i5) + ' ' +\
                        str(i6) + '\n'
                        run(payload)
