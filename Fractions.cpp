#pragma region generalDirectives
// SDL libs
#pragma comment(lib, "sdl2.lib")
#pragma comment(lib, "SDL2main.lib")
// OpenGL libs
#pragma comment (lib,"opengl32.lib")
#pragma comment (lib,"Glu32.lib")
// SDL extension libs 
#pragma comment(lib, "SDL2_image.lib") // Library to load image files
#pragma comment(lib, "SDL2_ttf.lib") // Library to use fonts
// SDL and OpenGL Includes
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
#include <SDL_image.h> // png loading
#include <SDL_ttf.h> // Font
#pragma endregion generalDirectives

#include<iostream>
#include"Fractions.h"
#include"structs.h"
#include "utils.h"
Fractions::Fractions()
:Fractions(0,0)
{
}
Fractions::Fractions(int numerator, int denominator) {

	m_Numerator = numerator;
	m_Denominator = denominator;

}
void Fractions::Draw(const Point2f& pos, float size) {
	glBegin(GL_QUADS);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glVertex2f(pos.x, pos.y);
	glVertex2f(pos.x+ size, pos.y);
	glVertex2f(pos.x+size , pos.y- size);
	glVertex2f(pos.x, pos.y-size);
	glEnd();





}
float Fractions::GetValue() {

	return m_Numerator / m_Denominator;

}
