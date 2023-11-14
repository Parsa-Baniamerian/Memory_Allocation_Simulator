#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Represents a memory block with an ID, size, and allocation status
struct MemoryBlock
{
    int id;
    int size;
    bool allocated;
};

// MemoryAllocator class for managing memory blocks
class MemoryAllocator
{
private:
    vector<MemoryBlock> memory; // Vector to store memory blocks
    int internalFragmentation = 0;
    int externalFragmentation = 0;

public:
    // Constructor: Initializes memory blocks with specified partition sizes
    MemoryAllocator(vector<int> partitionSizes)
    {
        internalFragmentation = 0;

        for (int i = 0; i < partitionSizes.size(); ++i)
        {
            MemoryBlock block = {i + 1, partitionSizes[i], false};
            memory.push_back(block);
        }
    }

    // Getters
    int getInternalFragmentation() const
    {
        return internalFragmentation;
    }

    int getExternalFragmentation() const
    {
        return externalFragmentation;
    }

    int calculateExternalFragmentation() const
    {
        int exFrag = getExternalFragmentation();
        for (const MemoryBlock &block : memory)
        {
            if (!block.allocated)
            {
                exFrag += block.size;
            }
        }

        return exFrag;
    }

    // Allocates memory for a process based on the specified strategy (First-fit, Best-fit, Worst-fit)
    void allocateMemory(int processSize, char strategy)
    {
        auto comp = [](const MemoryBlock &a, const MemoryBlock &b)
        {
            return a.size < b.size;
        };

        if (strategy == 'B')
        {
            sort(memory.begin(), memory.end(), comp);
        }
        else if (strategy == 'W')
        {
            sort(memory.begin(), memory.end(), comp);
            reverse(memory.begin(), memory.end());
        }

        // Find the first available memory block that fits the process size
        for (MemoryBlock &block : memory)
        {
            if (!block.allocated && block.size >= processSize)
            {
                block.allocated = true;
                internalFragmentation += (block.size - processSize);
                cout << "Allocated Memory Block " << block.id << " for process of size " << processSize << "\n";
                return;
            }
        }

        cout << "No suitable memory block found for process of size " << processSize << "\n";
    }

    // Checks if all memory blocks are allocated
    bool allMemoryAllocated() const
    {
        for (const MemoryBlock &block : memory)
        {
            if (!block.allocated)
            {
                return false;
            }
        }
        return true;
    }

    // Prints the current status of memory blocks
    void printMemoryStatus() const
    {
        cout << "Memory Status:\n";
        for (const MemoryBlock &block : memory)
        {
            cout << "Block " << block.id << ": Size=" << block.size << ", Allocated=" << (block.allocated ? "Yes" : "No") << "\n";
        }
        cout << "------------------------\n";
    }
};

int main()
{
    srand(time(0));

    // Generate random partition sizes that cover the entire memory space
    int totalMemorySize = 1000;
    int remainingMemorySize = totalMemorySize;
    vector<int> partitionSizes;

    // Create random partition sizes until the entire memory space is covered
    while (remainingMemorySize > 0)
    {
        int size = rand() % 301 + 50;          // Random size (50 to 350)
        size = min(size, remainingMemorySize); // Ensure the remaining size is not exceeded
        partitionSizes.push_back(size);
        remainingMemorySize -= size;
    }

    MemoryAllocator allocator(partitionSizes);

    // Take memory allocation strategy as input
    char strategy;
    cout << "Enter memory allocation strategy (F for First-fit, B for Best-fit, W for Worst-fit): ";
    cin >> strategy;

    // Check if the entered strategy is valid
    if (strategy != 'B' && strategy != 'F' && strategy != 'W')
    {
        cout << "Invalid memory allocation strategy. Exiting program.\n";
        return 0;
    }

    allocator.printMemoryStatus();

    // Take process sizes as input and simulate allocation
    int processSize;

    while (!allocator.allMemoryAllocated())
    {
        cout << "Enter the size of the process (0 to exit): ";
        cin >> processSize;

        if (processSize == 0)
        {
            break;
        }

        allocator.allocateMemory(processSize, strategy);

        allocator.printMemoryStatus();
    }

    cout << "Internal Fragmentation: " << allocator.getInternalFragmentation() << " bytes\n";

    cout << "External Fragmentation: " << allocator.calculateExternalFragmentation() << " bytes\n";

    cout << "All memory partitions have been allocated. Exiting program.\n";

    return 0;
}
