from Crypto.Util.number import long_to_bytes,bytes_to_long, getPrime

flag = b"VKU{fake_flag}"

p = getPrime(64)
q = getPrime(64)
n = p * q
e = 17
c = pow(bytes_to_long(flag),e,n)
print("n =",n)
print("c =",c)
print("e =",e)