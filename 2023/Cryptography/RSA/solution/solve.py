from Crypto.Util.number import long_to_bytes
import math

n = 148415912934398595973584524642410725287
c = 41746678175375382631128927535955680708
e = 17

p = 9708851719756433627 
q =  15286659763521644581

phi = (p-1)*(q-1)
print(math.gcd(e,phi))

d = pow(e,-1,phi)
flag = pow(c,d,n)
print(long_to_bytes(flag))