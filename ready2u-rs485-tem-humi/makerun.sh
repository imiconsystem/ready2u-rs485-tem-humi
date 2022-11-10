#!/bin/bash
_o="ready2u-rs485-tem-humi.o"
_out="ready2u-rs485-tem-humi.out"
cd "$(dirname "$0")"

rm -f "$_o"
rm -f "$_out"
make
./$_out