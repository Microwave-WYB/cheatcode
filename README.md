# CheatCode: The Craziest LeetCode Solutions Ever

## The Idea

Python is **slow**, perhaps the slowest language you can submit to LeetCode. But with `ctypes`, you can call C functions from Python. This is a common practice when building performance-critical parts of Python libraries. But we can also use it to cheat on LeetCode.

## The Plan

1. Write a C function that solves the problem.
2. Generate a shared library from the C code.
3. Convert the shared library into a Python `bytes` literal.
4. Write a Python wrapper:
    - Load the shared library from the `bytes` literal into `/proc/self/fd/lib.so`.
    - Call the C function.
    - Convert the result back to Python objects.

## The Result

It worked!

![leetcode screenshot](/assets/leetcode.png)
