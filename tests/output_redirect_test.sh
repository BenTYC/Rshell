#!/bin/sh
../bin/rshell << 'EOF'
# testing file yet to be created
ls > list.out
cat list.out
# testing already existing file with contents
ls > list.out
cat list.out
# create new empty file with nothing left
> aFile
test -e aFile
## multi connected command
# ls > first > second
# cat first
# cat second

# rm first second
rm list.out aFile
exit
EOF
