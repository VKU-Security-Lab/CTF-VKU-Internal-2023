FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y socat && \
    apt-get clean && \
    apt-get install -y libc6-i386 && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /bof

COPY ./src/flag.txt /
COPY ./src/bofbegin /bof/
COPY run.sh /

RUN chown -R root:root /bof && \
    chmod 500 /run.sh

EXPOSE 1337

ENTRYPOINT ["/run.sh"]