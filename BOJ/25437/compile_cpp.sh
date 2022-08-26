#!/bin/bash

problem=towns
grader_name=stub

g++ -std=gnu++17 -O2 -Wall -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"
