#!/bin/bash
BINARY=/challenge/ret2win
socat -dd -T60 tcp-l:1339,reuseaddr,fork,keepalive,su=nobody exec:$BINARY,stderr