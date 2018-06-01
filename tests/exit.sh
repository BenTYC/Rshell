#!/bin/sh
../bin/rshell << 'EOF'
echo We are testing rshell
echo exit
(echo we shouldnt && echo exit here) || (echo doesnt print && exit)
echo test worked
exit && echo shouldnt print
EOF
