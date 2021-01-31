#include <cstdint>
#pragma once


enum class EFIMemoryType:uint32_t
{
	EfiReservedMemoryType = 0,
	EfiLoaderCode,
	EfiLoaderData,
	EfiBootServicesCode,
	EfiBootServicesData,
	EfiRuntimeServicesCode,
	EfiRuntimeServicesData,
	EfiConventionalMemory,
	EfiLoaderCode,
	EfiUnusableMemory,
	EfiACPIReclaimMemory,
	EfiACPIMemoryNVS,
	EfiMemoryMappedIO,
	EfiMemoryMappedIOPortSpace,
	EfiPalCode,
}

struct EFI_MEMORY_DESCRIPTOR {
	EFIMemoryType type;
	void* physAddr;
	void* virtAddr;
	uint64_t numPages;
	uint64_t attribs;
};

extern const char* EFI_MEMORY_TYPE_STRINGS[];