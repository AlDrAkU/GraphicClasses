// SDL and OpenGL Includes
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
#include "structs.h"
#include "utils.h"
#pragma region generalDirectives

// SDL libs
#pragma comment(lib, "sdl2.lib")
#pragma comment(lib, "SDL2main.lib")

// OpenGL libs
#pragma comment (lib,"opengl32.lib")
#pragma comment (lib,"Glu32.lib")
const int g_border{ 10 };





void DrawRect(float left, float bottom, float width, float height, int lineWidth)
{
	glBegin(GL_LINE_LOOP);
	glColor4f( 1.0f, 0.0f,0.0f, 1.0f);
	glLineWidth(float(lineWidth));

	left = g_border + left;
	bottom = g_border + bottom;
	width = width;
	height = height;

	glVertex2f(left, bottom);
	glVertex2f(left + width, bottom);
	glVertex2f(left + width, bottom + height);
	glVertex2f(left, bottom + height);
	glEnd();

}
void DrawRect(Point2f pos, float width, float height, int lineWidth)
{
	glLineWidth(float(lineWidth));
	DrawRect(pos.x,pos.y, width, height, lineWidth);

}
void DrawRect(Rectf rectangle1, int lineWidth)
{
	glLineWidth(float(lineWidth));
	DrawRect(rectangle1.left, rectangle1.bottom, rectangle1.width, rectangle1.height, lineWidth);
}
void DrawEllipse(const Color4f & color, const Circlef &ellipse, int nrSides)
{
	float angle{ float(2 * M_PI) };

	angle = angle / nrSides;

	glBegin(GL_TRIANGLE_FAN);
	glColor4f(color.r, color.g, color.b, color.a);

	glVertex2f(ellipse.center.x, ellipse.center.y);

	for (int i = 0; i <= nrSides; i++)
	{
		glVertex2f(float(ellipse.center.x + (ellipse.radius * cos(i*angle))), float(ellipse.center.y + (ellipse.radius * sin(i*angle))));
	}

	glEnd();
}
