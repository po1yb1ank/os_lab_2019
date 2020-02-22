#!/bin/bash
result=0
echo "Count params $#"
for param in "$@"
do
let "result = result + param"
done
echo "$(($result/$#))"
