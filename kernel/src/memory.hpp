#pragma once
#include <cstdint>
#include "efiMemory.hpp"

uint64_t GetMemorySize(EFI_MEMORY_DESCRIPTOR* mMap, uint64_t mMapEntries, uint64_t mMapDescSize);