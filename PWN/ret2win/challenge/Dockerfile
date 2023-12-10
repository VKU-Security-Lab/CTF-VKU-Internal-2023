FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y socat && \
    apt-get clean && \
    apt-get install -y libc6-i386 && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /challenge

COPY ./src/flag.txt /
COPY ./src/ret2win /challenge
COPY run.sh /

RUN chmod 500 /run.sh

EXPOSE 1339

ENTRYPOINT ["/bin/bash", "/run.sh"]