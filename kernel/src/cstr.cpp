#include "cstr.hpp"

void strcopy(char* src, char* dst)
{
    if(!dst || !src){
        return;
    }
    while((*dst++ = *src++) != '\0');
}

size_t strlen(const char* str)
{
    const char* endOfString = str;
    while (*endOfString++);
    return (endOfString - str - 1);
}

char uintTo_StringBuffer[128];
const char* toString(uint64_t value){
	uint8_t size = 0;
	uint64_t sizeTest = value;
	while (sizeTest / 10 > 0){
		sizeTest /= 10;
		size++;
	}
	uint8_t index = 0;
	while( value / 10 > 0){
		uint8_t rem = value % 10;
		value /= 10;
		uintTo_StringBuffer[size - index] = rem + '0';
		index++; 
	}
	uint8_t rem = value % 10;
	uintTo_StringBuffer[size - index] = rem + '0';
	uintTo_StringBuffer[size + 1] = 0;
	return uintTo_StringBuffer;
}

char intTo_StringBuffer[128];
const char* toString(int64_t value){
    uint8_t isNegative = 0;

    if (value < 0){
        isNegative = 1;
        value = -value;
        intTo_StringBuffer[0] = '-';
    }

    uint8_t size;
    uint64_t sizeTest = value;
    while (sizeTest / 10 > 0){
        sizeTest /= 10;
        size++;
    }

    uint8_t index = 0;
    while(value / 10 > 0){
        uint8_t rem = value % 10;
        value /= 10;
        intTo_StringBuffer[isNegative + size - index] = rem + '0';
        index++;
    }
    uint8_t rem = value % 10;
    intTo_StringBuffer[isNegative + size - index] = rem + '0';
    intTo_StringBuffer[isNegative + size + 1] = 0; 
    return intTo_StringBuffer;
}

char floatTo_StringBuffer[128];
const char* toString(float value, uint8_t decimalPlaces){

    if (decimalPlaces > 20) decimalPlaces = 20;

    char* intPtr = (char*) toString((int64_t) value);
    char* floatPtr = (char*) floatTo_StringBuffer;
    if (value < 0.0f){
        value *= 1;
    }

    while(*intPtr != 0){
        *floatPtr = *intPtr;
        intPtr++;
        floatPtr++;
    }

    *floatPtr = '.';
    floatPtr++;

    float newValue = value - (int)value;
    for(uint8_t i = 0; i < decimalPlaces; i++){
        newValue *= 10;
        *floatPtr = (int)newValue + '0';
        newValue -= (int)newValue;
        floatPtr++;
    }

    *floatPtr = 0;
    return floatTo_StringBuffer;
}

const char* toString(float value){
    return toString(value, 2);
}

char doubleTo_StringBuffer[128];
const char* toString(double value, uint8_t decimalPlaces){

    if (decimalPlaces > 20) decimalPlaces = 20;

    char* intPtr = (char*) toString((int64_t) value);
    char* doublePtr = doubleTo_StringBuffer;
    if (value < 0){
        value *= -1;
    }

    while(*intPtr != 0){
        *doublePtr = *intPtr;
        intPtr++;
        doublePtr++;
    }

    *doublePtr = '.';
    doublePtr++;

    double newValue = value - (int)value;
    for(uint8_t i = 0; i < decimalPlaces; i++){
        newValue *= 10;
        *doublePtr = (int)newValue + '0';
        newValue -= (int)newValue;
        doublePtr++;
    }

    *doublePtr = 0;
    return doubleTo_StringBuffer;
}

const char* toString(double value){
    return toString(value, 2);
}

char uintTo_HexStringBuffer[128];

const char* toHexString(uint64_t value){
    uint64_t* valPtr = &value;
    uint8_t* ptr;
    uint8_t tmp;
    uint8_t size = sizeof(value)*2-1;

    for(uint8_t i = 0; i < size; i++){
        ptr = ((uint8_t*)valPtr + i);
        tmp = (*ptr & 0xF0) >> 4;
        uintTo_HexStringBuffer[size - (i*2 + 1)] = tmp + (tmp > 9 ? 55 : 48);
        tmp = (*ptr & 0x0F);
        uintTo_HexStringBuffer[size - (i*2)] = tmp + (tmp > 9 ? 55 : 48);
    }
    uintTo_HexStringBuffer[size + 1] = 0;
    return uintTo_HexStringBuffer;
}

const char* toHexString(uint32_t value){
    uint32_t* valPtr = &value;
    uint8_t* ptr;
    uint8_t tmp;
    uint8_t size = sizeof(value)*2-1;

    for(uint8_t i = 0; i < size; i++){
        ptr = ((uint8_t*)valPtr + i);
        tmp = (*ptr & 0xF0) >> 4;
        uintTo_HexStringBuffer[size - (i*2 + 1)] = tmp + (tmp > 9 ? 55 : 48);
        tmp = (*ptr & 0x0F);
        uintTo_HexStringBuffer[size - (i*2)] = tmp + (tmp > 9 ? 55 : 48);
    }
    uintTo_HexStringBuffer[size + 1] = 0;
    return uintTo_HexStringBuffer;
}

const char* toHexString(uint16_t value){
    uint16_t* valPtr = &value;
    uint8_t* ptr;
    uint8_t tmp;
    uint8_t size = sizeof(value)*2-1;

    for(uint8_t i = 0; i < size; i++){
        ptr = ((uint8_t*)valPtr + i);
        tmp = (*ptr & 0xF0) >> 4;
        uintTo_HexStringBuffer[size - (i*2 + 1)] = tmp + (tmp > 9 ? 55 : 48);
        tmp = (*ptr & 0x0F);
        uintTo_HexStringBuffer[size - (i*2)] = tmp + (tmp > 9 ? 55 : 48);
    }
    uintTo_HexStringBuffer[size + 1] = 0;
    return uintTo_HexStringBuffer;
}

const char* toHexString(uint8_t value){
    uint8_t* valPtr = &value;
    uint8_t* ptr;
    uint8_t tmp;
    uint8_t size = sizeof(value)*2-1;

    for(uint8_t i = 0; i < size; i++){
        ptr = ((uint8_t*)valPtr + i);
        tmp = (*ptr & 0xF0) >> 4;
        uintTo_HexStringBuffer[size - (i*2 + 1)] = tmp + (tmp > 9 ? 55 : 48);
        tmp = (*ptr & 0x0F);
        uintTo_HexStringBuffer[size - (i*2)] = tmp + (tmp > 9 ? 55 : 48);
    }
    uintTo_HexStringBuffer[size + 1] = 0;
    return uintTo_HexStringBuffer;
}