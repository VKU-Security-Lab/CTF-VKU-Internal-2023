#!/bin/sh

BINARY=/ret2win/ret2win

while :; do
    socat -dd -T60 tcp-l:1339,reuseaddr,fork,keepalive,su=nobody exec:$BINARY,stderr
done