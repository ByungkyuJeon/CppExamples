#pragma once

#include <stack>

#define TRACK_MEMORY_SWITCH false

#if TRACK_MEMORY_SWITCH
#ifndef TRACK_MEMORY
#define TRACK_MEMORY
#endif // TRACK_MEMORY
#endif

#ifdef TRACK_MEMORY
struct AllocationMatrix
{
	uint32_t allocated = 0;
	uint32_t freed = 0;

	uint32_t CurrentUsage() { return allocated - freed; }
};

static AllocationMatrix allocationMatrix;

static void PrintMemState()
{
	// printing
	std::cout << "current memory usage : " << allocationMatrix.CurrentUsage() << " bytes" << std::endl;
}

// 메모리 트래킹 클래스
struct MemoryTrackClass
{
public:
	MemoryTrackClass() : x(0.f), y(0.f), z(0.f) {};

private:
	float x, y, z;
};

void* operator new(size_t size)
{
	allocationMatrix.allocated += size;

	return malloc(size);
}

void operator delete(void* mem, size_t size)
{
	allocationMatrix.freed += size;

	free(mem);
}
#endif // TRACK_MEMORY

void executeMemoryTracking()
{
#ifdef TRACK_MEMORY
	std::cout << "mem class size : " << sizeof(MemoryTrackClass) << " bytes" << std::endl;

	// printing
	PrintMemState();
	{
		std::stack<MemoryTrackClass*> temp;
		for (int cnt = 0; cnt < 10; cnt++)
		{
			temp.emplace(new MemoryTrackClass());
			
			// printing
			PrintMemState();
		}

		while(!temp.empty())
		{
			delete(temp.top());
			temp.pop();

			// printing
			PrintMemState();
		}
	}

	// printing
	PrintMemState();
#endif
}