#!/bin/bash

PUSH_SWAP=""
CHECKER=""
CHECKER_L=""

source ./files.sh
source ./sequences.sh

find_push_swap

SEQUENCES=()

> lists_and_moves.txt
for j in $(seq 2 501); do
	sequence=$(generate_sequence 4242 1 $j)
	echo "$sequence" >> lists_and_moves.txt
	"$PUSH_SWAP" "$sequence" | tr '\n' ' ' | sed 's/ *$//' | { cat; echo; } >> lists_and_moves.txt
done

