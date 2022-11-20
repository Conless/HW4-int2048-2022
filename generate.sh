#!/bin/bash
cat ./include/BigInteger/int2048.h ./src/int2048.cc ./test/test.cpp > ./src/main.cpp
cat ./include/BigInteger/int2048.h ./src/int2048.cc ./test/test.cpp > ./test/test1.cpp
cat ./include/BigInteger/int2048.h ./src/int2048.cc > ./submit.h
sed -i '/#include "BigInteger\/int2048.h"/'d ./src/main.cpp
sed -i '/#include "BigInteger\/int2048.h"/'d ./test/test1.cpp
sed -i '/#include "BigInteger\/int2048.h"/'d ./submit.h
