#pragma once
#include "MainWindow.h"
#include "Graphics.h"

class Paddle
{
public:
	Paddle(int xPos, int yPos);
	int GetX() const;
	int GetY() const;
	int GetHeight() const;
	int GetWidth() const;
	void MovePaddle(const MainWindow& wnd);
	void DrawPaddle(Graphics& gfx) const;
	void ClampToScreen();
	int y; // paddle Y postion
private:
	int x; // paddle X postion
	int height; // paddle height
	int width; // paddle width
};