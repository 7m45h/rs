#! /usr/bin/env bash

LENGTH=${1:-50}
COUNT=${2:-4}

for i in $(seq 1 ${COUNT});
do
  echo $(cat /dev/urandom | tr -dc [:print:] | head -c ${LENGTH});
done
