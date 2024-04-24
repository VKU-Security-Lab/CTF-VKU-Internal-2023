#!/bin/bash

# Build docker image
docker build -t hacker-store .

# Run docker container
docker run -d -p 10002:1337 --name hacker-store hacker-store
