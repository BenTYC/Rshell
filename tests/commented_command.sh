#!/bin/sh
../bin/rshell << 'EOF'
echo Bye # ; ls -al && echo ll
echo We # are testing rshell
test -e test_test.sh && echo B
echo # baakdjna afnaklnf
echo # A || (echo B && echo C) 
echo "The following should output an error message"
test # -e test_test.sh
exit
EOF
