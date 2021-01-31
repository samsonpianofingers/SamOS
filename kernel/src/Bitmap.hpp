#pragma once
#include <cstddef>
#include <cstdint>

class Bitmap{
public:
    size_t size;
    uint8_t* buffer;
    bool operator[](uint64_t index);
    void Set(uint64_t index, bool value);
};