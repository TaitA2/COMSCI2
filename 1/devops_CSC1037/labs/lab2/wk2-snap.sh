#!/bin/sh
read prev
read cur
while ! test "$cur" = "$prev"; do
prev="$cur"
read cur
done
echo $cur
