#!/bin/sh
first=$1
shift
for arg in "$@"; do
printf "$arg "
done
echo $first
