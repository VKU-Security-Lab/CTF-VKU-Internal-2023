#!/bin/sh

BINARY=/inter/overload

while :; do
    socat -dd -T60 tcp-l:1340,reuseaddr,fork,keepalive,su=nobody exec:$BINARY,stderr
done