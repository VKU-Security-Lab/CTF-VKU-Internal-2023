FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y socat && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /inter

COPY ./src/flag.txt /inter/
COPY ./src/overload /inter/
COPY ./run.sh /run.sh

RUN chown -R root:root /inter && \
    chmod 500 /run.sh

EXPOSE 1340

ENTRYPOINT ["/run.sh"]