#include "Paddle.h"

//Constructor sets the X and Y postions with the paramters that it passes through
Paddle::Paddle(int xPos, int yPos) :
	x(xPos),
	y(yPos),
	height(110),
	width(15)
{
}

//Returns the X position of the paddle
int Paddle::GetX() const
{
	return x;
}//GetX()

//Returns the Y position of the paddle
int Paddle::GetY() const
{
	return y;
}//GetY()

//Returns the height of the paddle
int Paddle::GetHeight() const
{
	return height;
}//GetHeight()

//Returns the width of the paddle
int Paddle::GetWidth() const
{
	return width;
}//GetWidth()


//Moves the player paddle
void Paddle::MovePaddle(const MainWindow& wnd)
{
	//Adjusts the Y postion of the player paddle by the mouse
	//Paddle will move by its mid location
	y = wnd.mouse.GetPosY() - (height / 2);

	//Make sure paddle does not go out of the screen
	ClampToScreen();
}//MovePaddle

//Make sure paddle does not go out of screen
void Paddle::ClampToScreen()
{
	//Bottom of the screen
	if (y + height >= Graphics::ScreenHeight)
	{
		y = (Graphics::ScreenHeight - 1) - height;
	}
	else if (y <= 0) //Top of the screen
	{
		y = 0;
	}
}//ClampToScreen()

//Draws the paddle
void Paddle::DrawPaddle(Graphics& gfx) const
{
	for (int i = y; i < height + y; i++)
	{
		for (int j = x; j < width + x; j++)
		{
			gfx.PutPixel(j, i, 255, 255, 255);
		}
	}
}//DrawPaddle()
