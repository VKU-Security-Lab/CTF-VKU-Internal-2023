FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y socat && \
    apt-get clean && \
    apt-get install -y libc6-i386 && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /ret2win

COPY ./src/flag.txt /
COPY ./src/ret2win /ret2win/
COPY run.sh /

RUN chown -R root:root /ret2win && \
    chmod 500 /run.sh

EXPOSE 1339

ENTRYPOINT ["/run.sh"]