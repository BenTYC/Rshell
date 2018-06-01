#!/bin/sh
../bin/rshell << 'EOF'
echo "The following should output: A\nB"
( echo A && echo B ) || ( echo C && echo D )
((echo A && false) || (echo B && echo C)) || (echo D && echo E)
( echo error message should be output
exit
EOF
