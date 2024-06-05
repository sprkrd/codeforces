#!/bin/bash

if [ -z "$1" ]; then
    echo "Specify problem name"
    exit 1
elif [ -d "$1" ]; then
    echo "Directory $1 already exists"
    exit 1
else
    echo "Creating folder for problem $1"
    cp -r `dirname $0`/template $1
fi


