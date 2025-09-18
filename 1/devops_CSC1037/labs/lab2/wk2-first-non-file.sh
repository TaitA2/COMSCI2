#!/bin/sh
read file
while test -f "$file"; do
read file
done
echo "$file"
