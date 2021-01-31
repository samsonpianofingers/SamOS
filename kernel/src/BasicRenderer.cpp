#include "BasicRenderer.hpp"

BasicRenderer::BasicRenderer() :
	m_pBuffer(nullptr),
	m_pFont(nullptr),
	m_CursorPosition({0,0}),
	m_Colour(0xFFFFFFFF) {}

BasicRenderer::BasicRenderer(Framebuffer* buffer, PSF1_FONT* font) : 
	m_pBuffer(buffer),
	m_pFont(font),
	m_CursorPosition({0,0}),
	m_Colour(0xFFFFFFFF)
	{}

BasicRenderer::~BasicRenderer() {}

Framebuffer* BasicRenderer::GetFrameBuffer(){
	return m_pBuffer;
}

void BasicRenderer::SetCursorPos(unsigned int x, unsigned int y){
	m_CursorPosition.X = x;
	m_CursorPosition.Y = y;
}

void BasicRenderer::SetColour(unsigned int colour){
	m_Colour = colour;
}

void BasicRenderer::PutChar(char chr, unsigned int xOffset, unsigned int yOffset) {

	unsigned int* pPixel = (unsigned int*) m_pBuffer->BaseAddress;
	unsigned char chrsize = m_pFont->psf1_Header->charsize;
	char* pFont = (char*) m_pFont->glyphBuffer + (chr * chrsize);
/*	Check if the bit is set for glyph
    and set corresponding pixel*/
	for(unsigned int y = yOffset; y < yOffset + 16; y++){
		for (unsigned int x = xOffset; x < xOffset + 8; x++){

			if((*pFont & (0b10000000 >> (x - xOffset))) > 0){
				*(unsigned int*)(pPixel + x + (y*m_pBuffer->PixelsPerScanline)) = m_Colour;
			}
		}
		pFont++;
	}
}

void BasicRenderer::Print(const char *string) {
	char* chr = (char*) string;
	while (*chr != 0){
		PutChar(*chr, m_CursorPosition.X, m_CursorPosition.Y);
		m_CursorPosition.X+=8;
		if(m_CursorPosition.X + 8 > m_pBuffer->Width){
			m_CursorPosition.X = 0;
			m_CursorPosition.Y += 16;
		}
		chr++;
	}
}

void BasicRenderer::Next(){
	m_CursorPosition.Y += 16;
	m_CursorPosition.X = 0;
}