#include "BasicRenderer.hpp"
#include "cstr.hpp"
#include "efiMemory.hpp"
#include "memory.hpp"

 extern "C" void _Unwind_Resume(){};
 extern "C" void __gxx_personality_v0(){};

struct BootInfo {
	Framebuffer* buffer;
	PSF1_FONT* font;
	EFI_MEMORY_DESCRIPTOR* mMap;
	uint64_t mMapSize;
	uint64_t mMapDescSize;
};

extern "C" int _start(BootInfo* bootInfo){
	BasicRenderer renderer(bootInfo->buffer, bootInfo->font);
	renderer.SetColour(0xFF00FF00);
	uint64_t mMapEntries = bootInfo->mMapSize / bootInfo->mMapDescSize;
	renderer.Print(toString(GetMemorySize(bootInfo->mMap, mMapEntries, bootInfo->mMapDescSize)));
	return 0;
}