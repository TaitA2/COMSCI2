#!/usr/bin/zsh

# This week's task is tricky; there's some shell logic for you to untangle.
#
# The solution, though, is simple.
#

n=500

seq -f "%04.0f" $n |
   while read number
   do
      print $number | sha1sum | cut -d" " -f 1 > $number.txt
   done

# The "read file" below works in zsh (because zsh runs the last command in a
# pipeline in the current process, if possible), but wouldn't work in bash or
# Bourne shell.  And look at the shebang above, this is a zsh script.
#
ls *.txt | shuf -n 1 | read file
content=$( < $file )

output=$(sh $TASK $content)

if [[ $output == $file ]]
then
   print "ok"
   true
else
   print "nope"
   print
   print "running your script again (so that you can see its output)...\n"
   sh $TASK $content
   false
fi
