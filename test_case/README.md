# Description:
This folder contains program to generate test case and check output.
Test case will be in file with filename "input" and output should be written in file with filename "output".
Checker will check output, it will print line where output is wrong.

# Requirements:
- GCC 5.2.1 or newest.

# How to  build and run:
1. Run `g++ -o checker checker.cpp && g++ -o generator generator.cpp` in this project folder.
2. Run `./generator` to create test input.
3. Because main program read from standard input and write to standard output, you should run `cat input | ./sort > output`.
4. Run `./checker` to check output.
