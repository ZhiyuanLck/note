#!/usr/bin/env bash

if ! g++ -c $1.cpp; then exit 1; fi
readelf -S $1.o
readelf -s $1.o
nm $1.o
