#!/bin/bash

set -xe

name=pixel
file=../src/pixel.c

cd build
gcc -Werror -std=c11 -ggdb -o $name $file -lSDL2 -lSDL2main -lSDL_ttf

