# hoalight

A light Higher Order Ambisonics external for Pure Data

Written for the ZKM | Hertz-Lab's Zirkonium spatialization environment:

<https://zkm.de/zirkonium>

Chikashi Miyama  
Copyright (c) 2021 ZKM | Hertz-Lab  
Simplified BSD License

## Description

This is a simplified HOA external which calculates output speaker gains based on a given soure position and is meant to compliment the [vbap] external.

The HOA calculations are provided by the CICM HoaLibrary-Light:

<https://github.com/CICM/HoaLibrary-Light>

## Build

1. download the submodules 
git submodule update --init --recursive

2. install Cmake
Currently this external requires CMake version 3.10 or higher to compile

3. compile the static library

> mkdir build
> cd build
> cmake ..
> cmake --build .

after this operation you will find libHOALightWrapper.a in lib folder

4. at the root of the project

> make

to create *hoalight.pd_darwin*


## Usage

see the test_hoalight.pd