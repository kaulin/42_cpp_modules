#!/bin/bash

# Function to generate a set of random numbers
generate_set() {
  local set_size=$1
  local -a set=()
  
  # Keep track of already generated numbers to avoid duplicates
  while [ ${#set[@]} -lt $set_size ]; do
    rand_num=$((RANDOM % 100000 + 1))  # Random number between 1 and 100
    if [[ ! " ${set[@]} " =~ " $rand_num " ]]; then
      set+=($rand_num)
    fi
  done
  
  ./PmergeMe ${set[@]} >> log.txt
  # Print the set
  # echo "${set[@]}"
}

# Main logic
if [ $# -lt 1 ]; then
  echo "Usage: $0 N"
  exit 1
fi

N=$1  # Number of sets
rm -rf log.txt

# Generate N sets with 2, 3, ..., N numbers

for i in $(seq 2 $N); do
  generate_set $i
done
