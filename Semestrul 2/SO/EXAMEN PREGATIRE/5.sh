#!/bin/bash

NR_FIS=$(find -type f -name "*\.txt" | wc -l)
NR_DIR=$(find -type d | wc -l)
MED=$(($NR_FIS/$((NR_DIR+1))))
echo Media de fisiere txt: $MED
