#!/bin/sh
../bin/rshell << 'EOF'
# requires output redirection working
ls > list.out
# basic test
cat list.out | grep a
# no left, command should fail and error
| cat list.out
# multi command, should print to screen lines with BOTH a and l
cat list.out | grep l | grep a

rm list.out
exit
EOF
