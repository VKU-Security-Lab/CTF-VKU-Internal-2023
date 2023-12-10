# Convert encrypted flag to array of hex values
encryptFlag = "70 91 69 107 98 35 102 117 98 99 35 79 115 32 125 114 33 126 35 79 103 33 100 120 79 115 98 105 96 100 32 109".split(" ")

flag = ""

for i in encryptFlag:
    flag += chr(int(i) ^ 0x10)

print(flag)