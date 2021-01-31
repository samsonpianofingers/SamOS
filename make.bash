#!/bin/bash
cd gnu-efi
make
make bootloader
cd ..
cd kernel
make kernel
make buildimg