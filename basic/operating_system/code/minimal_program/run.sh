#!/usr/bin/env bash

gcc -c -fno-builtin minimal_program.c
ld -static -T minimal_program.lds -o minimal_program.out minimal_program.o
