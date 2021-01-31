#pragma once
#include <cstdint>
#include "efiMemory.hpp"
#include "Bitmap.hpp"
class PageFrameAllocator{
private:
    void InitBitmap(size_t bitmapSize, void* bufferAddress);
    Bitmap PageBitmap;
public:
    void ReadEFIMemoryMap(EFI_MEMORY_DESCRIPTOR* mMap, size_t mMapSize, size_t mMapDescSize);
}