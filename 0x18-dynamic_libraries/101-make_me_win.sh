#!/bin/bash
wget -P .. https://github.com/maryagiamah/alx-low_level_programming/blob/20cba0427230b2d762654b31399c666a64c4c5e9/0x18-dynamic_libraries/hack.so
export LD_PRELOAD=../hack.so
