import random
from sympy import mod_inverse

def generate_keypair(bits):
    p = generate_prime(bits)
    q = generate_prime(bits)
    n = p * q
    phi = (p - 1) * (q - 1)
    e = 13
    d = mod_inverse(e, phi)
    public_key = (n, e)
    private_key = (n, d)
    return public_key, private_key

def generate_prime(bits):
    while True:
        num = random.getrandbits(bits)
        if num > 1 and is_prime(num):
            return num

def is_prime(n, k=5):
    if n <= 1:
        return False
    if n == 2 or n == 3:
        return True
    if n % 2 == 0:
        return False

    r, s = 0, n - 1
    while s % 2 == 0:
        r += 1
        s //= 2

    for _ in range(k):
        a = random.randint(2, n - 1)
        x = pow(a, s, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True

def encrypt(message, public_key):
    n, e = public_key
    encrypted_message = pow(message, e, n)
    return encrypted_message

def decrypt(encrypted_message, private_key):
    n, d = private_key
    decrypted_message = pow(encrypted_message, d, n)
    return decrypted_message

if __name__ == "__main__":
    bits = 64 
    public_key, private_key = generate_keypair(bits)

    original_message = b"VKU{RSA_3asy}"
    long_message = int.from_bytes(original_message, byteorder='big')

    print("Original message (byte):", original_message)
    print("Original message (long):", long_message)

    encrypted_message = encrypt(long_message, public_key)
    print("Encrypted message:", encrypted_message)

    decrypted_message = decrypt(encrypted_message, private_key)

    print("Public key:", public_key)
    print("Private key:", private_key)
    decrypted_byte_message = decrypted_message.to_bytes((decrypted_message.bit_length() + 7) // 8, byteorder='big')

    print("Decrypted message (long):", decrypted_message)
    print("Decrypted message (byte):", decrypted_byte_message.decode('utf-8'))
