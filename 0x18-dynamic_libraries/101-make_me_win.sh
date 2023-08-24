#!/bin/bash
wget -P .. https://raw.github.com/maryagiamah/alx-low_level_programming/master/0x18-dynamic_libraries/hack.so
export LD_PRELOAD=../hack.so
