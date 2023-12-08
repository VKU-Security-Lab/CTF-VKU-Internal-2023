#!/bin/sh

BINARY=/store/store

while :; do
    socat -dd -T60 tcp-l:1338,reuseaddr,fork,keepalive,su=nobody exec:$BINARY,stderr
done