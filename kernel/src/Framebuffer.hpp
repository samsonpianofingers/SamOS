#pragma once
#include <cstddef>

struct Framebuffer {
	void* BaseAddress;
	size_t BufferSize;
	unsigned int Width, Height;
	unsigned int PixelsPerScanline;
};