#!/bin/sh
../bin/rshell << 'EOF'
git init directory/in_directory
touch file
echo "made a directory and a file: directory, file"

echo "TESTING -e"
echo "the following should output: (True)"
test -e directory
echo "the following should output: (False)"
[ -e doesnt_exist ]
echo "the following should output: (True)"
test directory
echo "the following should output: (False)"
[ doesnt_exist ]
echo "TESTING -d"
echo "the following should output: (True)"
[ -d directory ]
echo "the following should output: (False)"
test -d file.cpp

echo "TESTING -f"
echo "the following should output: (False)"
test -f directory
echo "the following should output: (False)"
[ -f directory ]
echo "the following should output: (True)"
test -f file
echo "the following should output: (False)"
[ -f doesnt_exist ]

echo "TESTING with connectors"
echo "the following should output: (True) \n path exists"
test -e directory && echo "path exists"
echo "the following should output: (True) \n path exists"
[ -e directory ] && echo "path exists"
echo "the following should output: (False)"
test -e doesnt_exist && echo "path exists"
echo "the following should output: (False)"
[ -e doesnt_exist ] && echo "path exists"

echo "TESTING directory paths"
echo "The following should output: (True)"
test -e /home/csmajs/nchri003/cs100-assignment-2-nc-tc/tests/directory
echo "The following should output: (True)"
test -e directory/in_directory
echo "TESTING incomplete"
echo "The following should output: (False)"
test
echo "The following should output: (False)"
test -e
rm file
rm -r directory

exit
EOF
