#!/bin/sh
for i in $(seq 1 $1); do
  mkdir $(printf "dir.%06d" $i)
done
