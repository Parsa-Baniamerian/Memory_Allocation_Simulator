#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

struct MemoryBlock
{
    int id;
    int size;
    bool allocated;
};

class MemoryAllocator
{
private:
    vector<MemoryBlock> memory;

public:
    MemoryAllocator(vector<int> partitionSizes)
    {
        for (int i = 0; i < partitionSizes.size(); ++i)
        {
            MemoryBlock block = {i + 1, partitionSizes[i], false};
            memory.push_back(block);
        }
    }

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

    void printMemoryStatus() const
    {
        cout << "Memory Status:\n";
        for (const MemoryBlock &block : memory)
        {
            cout << "Block " << block.id << ": Size=" << block.size << ", Allocated=" << (block.allocated ? "Yes" : "No") << "\n";
        }
        cout << "------------------------\n";
    }

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

        for (MemoryBlock &block : memory)
        {
            if (!block.allocated && block.size >= processSize)
            {
                block.allocated = true;
                cout << "Allocated Memory Block " << block.id << " for process of size " << processSize << "\n";
                return;
            }
        }

        cout << "No suitable memory block found for process of size " << processSize << "\n";
    }

    void deallocateMemory(int blockId)
    {
        for (MemoryBlock &block : memory)
        {
            if (block.id == blockId)
            {
                if (block.allocated)
                {
                    block.allocated = false;
                    cout << "Deallocated Memory Block " << block.id << "\n";
                }
                else
                {
                    cout << "Memory Block " << block.id << " is not allocated\n";
                }
                return;
            }
        }

        cout << "Invalid Memory Block ID\n";
    }
};

int main()
{
    srand(time(0)); // Seed for random number generation

    // Generate random partition sizes that cover the entire memory space
    int totalMemorySize = 1000;
    int remainingMemorySize = totalMemorySize;
    vector<int> partitionSizes;

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

    cout << "All memory partitions have been allocated. Exiting program.\n";

    return 0;
}
