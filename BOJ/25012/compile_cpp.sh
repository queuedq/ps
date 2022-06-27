#!/bin/bash

problem=dial

g++ -std=c++17 -O2 -Wall -o "${problem}" "grader.cpp" "${problem}.cpp"
