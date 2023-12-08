#!/bin/sh

BINARY=/bof/bofbegin

while :; do
    socat -dd -T60 tcp-l:1337,reuseaddr,fork,keepalive,su=nobody exec:"$BINARY",stderr
    sleep 1  
    echo "Closing connection..."
done
