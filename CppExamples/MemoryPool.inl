#include "MemoryPool.h"
#pragma once

// BY byungkyu.dev@gmail.com
// inline explicitly added while definitions and declarations are seperated.

template<typename PoolType>
inline PoolType* MemoryPool<PoolType>::Allocate(size_t InSize)
{
	PoolType* allocPtr = GetAllocatablePtr(InSize);
	
	if (!allocPtr)
		debugOut("no allocatable memory in pool");

	return allocPtr;
}

template<typename PoolType>
inline void MemoryPool<PoolType>::Free(PoolType* InMem, size_t InSize)
{
	FreeMemory(InMem);
}

template<typename PoolType>
inline size_t MemoryPool<PoolType>::GetPoolSize() const
{
	return m_PoolSize;
}

template<typename Pooltype>
inline size_t MemoryPool<Pooltype>::GetAllocatedSize() const
{
	return m_CurrentAllocatedCount;
}

template<typename PoolType>
PoolType* MemoryPool<PoolType>::GetAllocatablePtr(size_t InSize)
{
	size_t memIdx = -1;
	for (int idx = m_LastAllocatedIndex + 1; idx < m_PoolSize; idx++)
	{
		if (m_IsSlotUsing[idx])
			continue;

		memIdx = idx;
		break;
	}

	if (memIdx == -1)
	{
		for (int idx = 0; idx <= m_LastAllocatedIndex; idx++)
		{
			if (m_IsSlotUsing[idx])
				continue;

			memIdx = idx;
			break;
		}
	}

	if (memIdx == -1)
		return nullptr;

	m_IsSlotUsing[memIdx] = true;
	m_LastAllocatedIndex = memIdx;
	m_CurrentAllocatedCount += 1;
	m_MemoryMap[&m_Pool[memIdx]] = memIdx;

	return &m_Pool[memIdx];
}

template<typename PoolType>
void MemoryPool<PoolType>::FreeMemory(PoolType* InMem)
{
	if (m_MemoryMap.find(InMem) == m_MemoryMap.end())
		return;

	m_IsSlotUsing[m_MemoryMap[InMem]] = false;
	m_CurrentAllocatedCount -= 1;

	m_MemoryMap.erase(InMem);
}