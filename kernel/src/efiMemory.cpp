#include "efiMemory.hpp"

const char* EFI_MEMORY_TYPE_STRINGS[] {
	
	"EfiReservedMemoryType",
	"EfiLoaderCode",
	"EfiLoaderData",

	"EfiBootServicesCode",
	"EfiBootServicesData",

	"EfiRuntimeServicesCode",
	"EfiRuntimeServicesData",

	"EfiConventionalMemory", // For Kernel Memory
	"EfiUnusableMemory",

	"EfiACPIReclaimMemory", // For Kernel Memory (ACPI)
	"EfiACPIMemoryNVS",

	"EfiMemoryMappedIO",
	"EfiMemoryMappedIOPortSpace",
	
	"EfiPalCode"
};