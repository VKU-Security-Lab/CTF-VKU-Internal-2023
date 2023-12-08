FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y socat && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /store

COPY ./src/flag.txt /store/
COPY ./src/store /store/
COPY run.sh /

RUN chown -R root:root /store && \
    chmod 500 /run.sh

EXPOSE 1338

ENTRYPOINT ["/run.sh"]