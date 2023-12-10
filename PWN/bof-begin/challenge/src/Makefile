FLAGS = -m32 -fno-stack-protector -z execstack -no-pie -Wl,-z,norelro -Wl,-z,now -Wl,-z,relro -Wl,-z,separate-code -Wl,-z,separate-loadable-segments -Wl,-z,stack-size=0x1000

all: bofbegin

bofbegin: source.c
	gcc -o $@ $^ $(FLAGS)