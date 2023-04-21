#!/bin/bash

# Compile the project

# Run the tests
./dist/Debug/GNU-Linux/language3 > output.txt

# Check if each test passed
EXPECTED="PASSED"
while read -r line
do
  if [[ $line == *"$EXPECTED"* ]]; then
    echo "$line: OK"
  else
    echo "$line: FAIL"
  fi
done < "output.txt"

