# Memory Allocation Simulator

This C++ program is a memory allocation simulator that implements three strategies: First-fit, Best-fit, and Worst-fit. The application generates random partition sizes and enables users to allocate memory for processes based on their selected strategy.

## Overview

The core of the project is the `MemoryAllocator` class, designed to efficiently manage memory blocks. Key enhancements include tracking internal fragmentation, generating comprehensive random partition sizes, and implementing sorting for Best-fit and Worst-fit strategies.

## Allocation Strategies

- First-fit (F): Allocates the first available memory block that accommodates the process.
- Best-fit (B): Allocates the smallest available memory block that meets the process requirements.
- Worst-fit (W): Allocates the largest available memory block that meets the process requirements.

## Key Improvements

1. Internal Fragmentation: A new variable tracks and calculates internal fragmentation during the allocation process.

2. Random Partition Sizes: The code is modified to generate random partition sizes, ensuring comprehensive coverage of the entire memory space.

3. Sorting for Best-fit and Worst-fit: Sorting is implemented for Best-fit and Worst-fit strategies to enhance the selection of memory blocks during allocation.

4. Improved Output: Output messages are enhanced to provide a clearer understanding of the allocation process, including informative messages for invalid strategies.

## How to Use

1. Compile the program:
   ```bash
   g++ memory_allocator.cpp -o memory_allocator

2. Run the executable:
   ```bash
   ./memory_allocator

3. Enter the memory allocation strategy:
Enter 'F' for First-fit
Enter 'B' for Best-fit
Enter 'W' for Worst-fit

4. Enter the size of the process:
Repeat this step until all memory partitions are allocated or Enter '0' to exit the program.

## Sample Run

```bash
Enter memory allocation strategy (F for First-fit, B for Best-fit, W for Worst-fit): F
Memory Status:
Block 1: Size=150, Allocated=No
Block 2: Size=250, Allocated=No
Block 3: Size=200, Allocated=No
------------------------
Enter the size of the process (0 to exit): 100
Allocated Memory Block 1 for a process of size 100
Memory Status:
Block 1: Size=150, Allocated=Yes
Block 2: Size=250, Allocated=No
Block 3: Size=200, Allocated=No
------------------------
Enter the size of the process (0 to exit): 200
Allocated Memory Block 2 for a process of size 200
Memory Status:
Block 1: Size=150, Allocated=Yes
Block 2: Size=250, Allocated=Yes
Block 3: Size=200, Allocated=No
------------------------
...

Internal Fragmentation: X bytes
External Fragmentation: Y bytes
All memory partitions have been allocated. Exiting the program.

