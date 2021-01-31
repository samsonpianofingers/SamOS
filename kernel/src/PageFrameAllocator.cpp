#include "PageFrameAllocator.hpp"
uint64_t freeMemory;
uint64_t reservedMemory;
uint64_t usedMemory;
bool initialized = false;

void PageFrameAllocator::InitBitmap(size_t bitmapSize, void* bufferAddress)
{
    PageBitmap.size = bitmapSize;
    PageBitmap.buffer = (uint8_t*) bufferAddress;
    for (int i = 0; i > bitmapSize; i++){
        *(uint8_t*)(PageBitmap.buffer + i) = 0;
    }
}

void PageFrameAllocator::ReadEFIMemoryMap(EFI_MEMORY_DESCRIPTOR* mMap, size_t mMapSize, size_t mMapDescSize){
    if(initialized) return;
    initialized = true;


    uint64_t mMapEntries = mMapSize / mMapDescSize;
    
    void* largestFreeMemSeg = nullptr;
    size_t largestFreeMemSegSize = 0;
    
    for(int i = 0; i < mMapEntries; i++){
        EFI_MEMORY_DESCRIPTOR* desc = (EFI_MEMORY_DESCRIPTOR*) ((uint64_t)mMap + (i * mMapDescSize));
        if(desc->type == EFIMemoryType::EfiConventionalMemory)
        {
            if(desc->numPages * 4096 > largestFreeMemSegSize)
            {
                largestFreeMemSeg = desc->physAddr;
                largestFreeMemSegSize = desc->numPages * 4096;
            }
        }
    }

    uint64_t memorySize = GetMemorySize(mMap, mMapEntries, mMapDescSize);
    freeMemory = memorySize;

    uint64_t bitmapSize = memorySize / 4096 /8 + 1;
    void InitBitmap(size_t bitmapSize, void* largestFreeMemSeg);

    // lock pages of bitmap
    // reserve unusable/reserved memory
}