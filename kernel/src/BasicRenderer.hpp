#pragma once
#include "Framebuffer.hpp"
#include "math.hpp"
#include "simpleFonts.hpp"

class BasicRenderer {
	Framebuffer* m_pBuffer;
	PSF1_FONT* m_pFont;
	Point m_CursorPosition;
	unsigned int m_Colour;
public:
	Framebuffer* GetFrameBuffer();
	void SetCursorPos(unsigned int x, unsigned int y);
	void SetColour(unsigned int colour);
	void PutChar(char chr, unsigned int xOffset, unsigned int yOffset);
	void Print(const char *string);
	void Next();

	BasicRenderer();
	BasicRenderer(Framebuffer* buffer, PSF1_FONT* font);
	~BasicRenderer();
	
};