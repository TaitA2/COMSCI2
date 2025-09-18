#!/bin/sh
while test -f "$1"
do
shift
done
! test -n "$1"
