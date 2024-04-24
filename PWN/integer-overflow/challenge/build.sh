#!/bin/bash

# Build docker image
docker build -t integer-overflow .

# Run docker container
docker run -d -p 10037:1337 --name integer-overflow integer-overflow
