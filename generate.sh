#!/bin/bash
cat ./include/int2048/int2048.h ./src/int2048.cc > ./submit.h
sed -i '/#include "int2048\/int2048.h"/'d ./submit.h
