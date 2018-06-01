#!/bin/sh
../bin/rshell << 'EOF'
# testing on a file yet to exist
ls >> list.out
cat list.out
# testing already existing file with contents
ls >> list.out
cat list.out
# testing create an empty command with no left
>> aFile
test -e aFile
## testing multi commands
# ls >> first >> second
# cat first
# cat second

# rm first second
rm list.out aFile
exit
EOF
