#!/bin/sh
for arg in "$@"; do
if test -d "$arg"; then
echo "$arg" directory
elif  test -f "$arg"; then
echo "$arg" file
else
echo "$arg" does not exist
fi
done
