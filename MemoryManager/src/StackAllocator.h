#ifndef MEMNGR_STACK_ALLOCATOR
#define MEMNGR_STACK_ALLOCATOR

#include <atomic>

#include "Allocator.h"

// DEFINITIONS
// -------------------------
typedef unsigned int Marker;
// -------------------------

class StackAllocator : private Allocator {
private: /// VARIABLES
	std::atomic<Marker> m_marker;

private: /// FUNCTIONS
	unsigned int padMemory(unsigned int sizeBytes);
	void cleanUp();

public: /// FUNCTIONS
	StackAllocator(void* memPtr, unsigned int sizeBytes);
	virtual ~StackAllocator();

	void* allocate(unsigned int sizeBytes);
	virtual void deallocateAll();

	Marker getMarker();
	void clearToMarker(Marker marker);

	// Memory tracking 
	virtual std::vector<bool> getUsedMemory();
	float getUsedMemoryPercentage();
};

#endif //MEMNGR_STACK_ALLOCATOR
