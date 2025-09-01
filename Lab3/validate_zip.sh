#!/bin/bash

EXPECTED_FILES=(
    "ALU.v"
    "ALUCtrl.v"
    "Adder.v"
    "BranchComp.v"
    "Control.v"
    "DataMemory.v"
    "ImmGen.v"
    "InstructionMemory.v"
    "Mux2to1.v"
    "Mux3to1.v"
    "PC.v"
    "Register.v"
    "ShiftLeftOne.v"
    "SingleCycleCPU.v"
)

if [ -z "$1" ]; then
    echo "Usage: $0 <zip_file>"
    exit 1
fi

ZIP_FILE=$1

if [ ! -f "$ZIP_FILE" ]; then
    echo "Error: File '$ZIP_FILE' does not exist."
    exit 1
fi

EXTRACT_DIR="/tmp/lab2_extract"

rm -rf "$EXTRACT_DIR"
mkdir -p "$EXTRACT_DIR"

unzip -q "$ZIP_FILE" -d "$EXTRACT_DIR"

STUDENT_ID=$(basename "$ZIP_FILE" .zip | sed 's/^lab2_//')

LAB_DIR="$EXTRACT_DIR/lab2_$STUDENT_ID"
if [ ! -d "$LAB_DIR" ]; then
    echo "Error: Directory lab2_$STUDENT_ID not found in the zip file."
    exit 1
fi

ALL_VALID=1
for FILE in "${EXPECTED_FILES[@]}"; do
    if [ ! -f "$LAB_DIR/$FILE" ]; then
        echo "Missing: $FILE"
        ALL_VALID=0
    fi
done

if [ $ALL_VALID -eq 1 ]; then
    echo "Validation successful: All required files are present."
    exit 0
else
    echo "Validation failed: Missing files in the structure."
    exit 1
fi
