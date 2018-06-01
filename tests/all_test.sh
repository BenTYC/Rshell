#!/bin/sh
../bin/rshell << 'EOF'
touch existingInputFile
ls > existingInputFile
cat < existingInputFile | tr A-Z a-z | tee newOutputFile1 | tr a-z A-Z > newOutputFile2
echo inputfile
cat existingInputFile
echo inputfile1
cat newOutputFile1
echo inputfile2
cat newOutputFile2

rm existingInputFile newOutputFile1 newOutputFile2
exit
EOF
