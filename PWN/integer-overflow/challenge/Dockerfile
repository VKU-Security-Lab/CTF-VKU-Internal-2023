FROM ubuntu:latest

RUN apt-get update && apt-get install socat libc6-i386 libc6 -y && apt-get clean && rm -rf /var/lib/apt/lists/*

WORKDIR /overload

COPY src/overload /overload/overload
COPY src/flag.txt /flag.txt
COPY entry.sh /entry.sh

RUN chmod +x overload
RUN chmod 444 /flag.txt
RUN chmod +x /entry.sh

CMD ["/entry.sh"]