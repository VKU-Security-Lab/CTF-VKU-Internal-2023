FROM ubuntu:latest

RUN apt-get update && apt-get install socat libc6-i386 libc6 -y && apt-get clean && rm -rf /var/lib/apt/lists/*

WORKDIR /ret2win

COPY /src/ret2win .
COPY /src/flag.txt /
COPY entry.sh /

RUN chmod 444 /flag.txt
RUN chmod +x /entry.sh
RUN chmod +x /ret2win/ret2win

CMD ["/entry.sh"]