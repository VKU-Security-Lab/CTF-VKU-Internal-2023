FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y socat && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /integer

COPY ./src/flag.txt /integer/
COPY ./src/overload /integer/
COPY ./run.sh /run.sh

RUN chown -R root:root /integer && \
    chmod 500 /run.sh

EXPOSE 1340

ENTRYPOINT ["/run.sh"]