#!/bin/bash
source $HOME/.profile

sudo cp ./out/build/WSL-GCC-Debug/Target/PersonalLib/libPersonalLib* /usr/lib64
cp ./out/build/WSL-GCC-Debug/Target/PersonalLib/libPersonalLib* ~/lib

