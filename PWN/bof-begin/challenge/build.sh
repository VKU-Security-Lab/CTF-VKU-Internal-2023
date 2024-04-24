#!/bin/bash

# Build docker image
docker build -t bof-begin .

# Run docker container
docker run -d -p 10037:1337 --name bof-begin bof-begin
