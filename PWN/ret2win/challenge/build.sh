#!/bin/bash

# Build docker image
docker build -t ret2win .

# Run docker container
docker run -d -p 10004:1337 --name ret2win ret2win
