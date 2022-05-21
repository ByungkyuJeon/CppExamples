#pragma once

#include <unordered_map>
#include "Defines.h"

template<typename PoolType>
class MemoryPool
{
public:
	PoolType* Allocate(size_t InSize);
	void Free(PoolType* InMem, size_t InSize);
	size_t GetAllocatedSize() const;
	size_t GetPoolSize() const;

private:
	PoolType* GetAllocatablePtr(size_t InSize);
	void FreeMemory(PoolType* InMem);

	PoolType m_Pool[DEFAULT_MEMORY_POOL_SIZE];
	bool m_IsSlotUsing[DEFAULT_MEMORY_POOL_SIZE] = { false };
	size_t m_LastAllocatedIndex = 0;
	size_t m_CurrentAllocatedCount = 0;
	size_t m_PoolSize = DEFAULT_MEMORY_POOL_SIZE;
	std::unordered_map<PoolType*, size_t> m_MemoryMap;
};

template<typename PoolType>
static MemoryPool<PoolType>* gMemoryPool;

template<typename PoolType>
static void CreateMemoryPool()
{
	if (gMemoryPool<PoolType>)
		return;

	gMemoryPool<PoolType> = new MemoryPool<PoolType>();
};

template<typename PoolType>
static PoolType* bknew()
{
	return gMemoryPool<PoolType>->Allocate(sizeof(PoolType));
}

template<typename PoolType>
static void bkfree(PoolType* InMem)
{
	gMemoryPool<PoolType>->Free(InMem, sizeof(PoolType));
}

template<typename PoolType>
inline const MemoryPool<PoolType>* GetMemoryPool()
{
	return gMemoryPool<PoolType>;
};

#include "MemoryPool.inl"