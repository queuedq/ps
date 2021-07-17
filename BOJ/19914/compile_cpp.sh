#!/bin/bash

problem=shoes

g++ -std=gnu++14 -Wall -o "${problem}" "grader.cpp" "${problem}.cpp"
