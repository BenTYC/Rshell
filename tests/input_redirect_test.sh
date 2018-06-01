#!/bin/sh
../bin/rshell << 'EOF'
# requires working output_redirect
# test command, print to screen all finding of a
ls > list.out
grep a < list.out
# error test, taking in nothing
## grep a <
# multi commands, should only print to screen rightmost
grep a < list.out < list.out

rm list.out
exit
EOF
