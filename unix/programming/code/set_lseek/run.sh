#!/usr/bin/env bash

gcc -O2 -Wall -o set_lseek.out set_lseek.c

seek() {
  echo "try to seek $1"
  ./set_lseek.out < $1
}

seek /etc/passwd
echo "try to seek pipe"
cat < /etc/passwd | ./set_lseek.out
# seek /var/spool/cron/FIFO
