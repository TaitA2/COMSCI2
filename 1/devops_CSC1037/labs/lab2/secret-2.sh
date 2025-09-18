#!/bin/sh

n=500

seq -f "%04.0f" $n |
   while read number
   do
      print $number | sha1sum | cut -d" " -f 1 > $number.txt
   done

