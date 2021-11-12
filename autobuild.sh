#!/bin/bash

set -e

mkdir build
cd `pwd`/build &&
    cmake .. &&
    make
cd ..

cp -r `pwd`/src/include `pwd`/lib