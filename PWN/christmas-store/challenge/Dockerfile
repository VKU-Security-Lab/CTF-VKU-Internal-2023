FROM ubuntu:20.04

RUN apt-get update && \
    apt-get install -y socat && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /challengeStore

COPY ./src/flag.txt /
COPY ./src/ChristmasStore /challengeStore
COPY ./run.sh /run.sh

RUN chown -R root:root /challengeStore && \
    chmod 777 /run.sh

EXPOSE 1338

ENTRYPOINT ["/run.sh"]