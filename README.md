# Memory Allocator

This is a simple C++ program that simulates a memory allocator. The program initializes a memory space with partitions of varying sizes and allows users to allocate and deallocate memory blocks using different allocation strategies.

## Table of Contents

- [Introduction](#introduction)
- [How to Use](#how-to-use)
- [Allocation Strategies](#allocation-strategies)
- [Sample Run](#sample-run)

## Introduction

The program defines a `MemoryAllocator` class that manages memory blocks. Each memory block has an identifier, size, and allocation status. The program supports three allocation strategies: First-fit (default), Best-fit, and Worst-fit.


## Allocation Strategies

- First-fit (F): Allocates the first available memory block that is large enough for the process.

- Best-fit (B): Allocates the smallest available memory block that is large enough for the process.

- Worst-fit (W): Allocates the largest available memory block that is large enough for the process.

  

## How to Use

To use the program, follow these steps:

1. Compile the program using a C++ compiler.
   ```bash
   g++ memory_allocator.cpp -o memory_allocator
  
2. Run the executable.
   ```bash
   ./memory_allocator

3. Enter the memory allocation strategy when prompted (F for First-fit, B for Best-fit, W for Worst-fit).
4. Enter the size of the process when prompted. Repeat this step until all memory partitions are allocated.
5. The program will print the status of memory after each allocation.
6. To exit the program, enter 0 when prompted for the size of the process.


### Sample Run

```bash
Enter memory allocation strategy (F for First-fit, B for Best-fit, W for Worst-fit): F
Memory Status:
Block 1: Size=150, Allocated=No
Block 2: Size=250, Allocated=No
Block 3: Size=200, Allocated=No
------------------------
Enter the size of the process (0 to exit): 100
Allocated Memory Block 1 for process of size 100
Memory Status:
Block 1: Size=150, Allocated=Yes
Block 2: Size=250, Allocated=No
Block 3: Size=200, Allocated=No
------------------------
Enter the size of the process (0 to exit): 200
Allocated Memory Block 2 for process of size 200
Memory Status:
Block 1: Size=150, Allocated=Yes
Block 2: Size=250, Allocated=Yes
Block 3: Size=200, Allocated=No
------------------------
...

All memory partitions have been allocated. Exiting program.

