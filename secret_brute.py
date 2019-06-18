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
    p.sendline('9 austinpowers\n')
    addr = p.recv()
    p.sendline('?05;=A\n')
    addr = p.recv()
    p.sendline('4 2 6 3 1 5\n' + payload + '\n')
    addr = p.recv()
    if 'BOOM!!!' not in addr:
        with open('./found.txt','w') as found:
            found.write(payload)
        print payload
        sys.exit()
    p.close()
    return

for i in xrange(900,1002):
    run(str(i))
