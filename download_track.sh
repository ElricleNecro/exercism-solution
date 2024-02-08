#!/usr/bin/env sh

wget https://raw.githubusercontent.com/exercism/$1/main/config.json -O $1.json
mapfile exercises -t < <(jq -r '.exercises.concept[].slug' $1.json)
for exercise in "${exercises[@]}"; do
	echo Downloading "${exercise}"
	exercism download --track $1 --exercise "${exercise}" -v
done
