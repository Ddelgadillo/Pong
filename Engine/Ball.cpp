#include "Ball.h"

//Constructor also sets all variables with paramters that are called by the game
Ball::Ball(int xPos, int yPos, float ballXVel, float ballYVel) :
	x(xPos),
	y(yPos),
	xVel(ballXVel),
	yVel(ballYVel)
{
}

//called by the game in order to move the ball
void Ball::Update()
{
	//animates ball
	x += xVel;
	y += yVel;

	//HEY BALL!!! DON'T LEAVE THE SCREEN
	ClampScreen();
}//Update()

//Returns the Y postion so it can be used by other classes
int Ball::getY() const
{
	return y;
}//getY()

//Makes sure ball doesn't leave top or bottom screen
void Ball::ClampScreen()
{
	//Bottom
	if (y + height >= Graphics::ScreenHeight)
	{
		y = (Graphics::ScreenHeight - 1) - height;
		yVel = -yVel; // reverse Y velcotiy if it hits the bottom
	}
	else if (y <= 0) //Top
	{
		y = 1; // will crash for some reason without this??? 
		yVel = -yVel; // reverse Y velcotiy if it hits the top
	}//ClampScreen()
}

//Checks collision with the player paddle
void Ball::CollisionLeft(Paddle& paddle)
{
	//calculates the paddles bottom
	const int paddleBottom = paddle.GetY() + paddle.GetHeight();
	//calculates the ball's bottom
	const int ballBottom = y + height;

	//if the ball has reached the left side of the screen
	if (x <= 0)
	{
		//if the ball is in between the paddles
		if (ballBottom >= paddle.GetY() && y <= paddleBottom)
		{
			//resets X to the paddle's left side
			x = paddle.GetX() + paddle.GetWidth();
			//revers the X velocity of the ball
			xVel = -xVel;

			//calculates where in the paddle the ball was hit
			float deltaY = y - (paddle.GetY() + paddle.GetHeight() / 2);

			//assign the Y velocity to this
			yVel = deltaY * 0.35;
		}
		else
		{
			//if it passed the paddle then reset the ball
			BallReset();
		}
	}
}//CollisionLeft()

void Ball::CollisionRight(Paddle& paddle)
{
	//calculates the paddles bottom
	const int paddleBottom = paddle.GetY() + paddle.GetHeight();
	//calculates the ball's bottom
	const int ballBottom = y + height;

	//if the ball is in between the paddles
	if (x + width >= Graphics::ScreenWidth)
	{
		//if the ball is in between the paddles
		if (ballBottom >= paddle.GetY() && y <= paddleBottom)
		{
			//resets X to the paddle's left side
			x = paddle.GetX() - width;
			//revers the X velocity of the ball
			xVel = -xVel;

			//calculates where in the paddle the ball was hit
			float deltaY = y - (paddle.GetY() + paddle.GetHeight() / 2);

			//assign the Y velocity to this
			yVel = deltaY * 0.35;
		}
		else
		{
			//if it passed the paddle then reset the ball
			BallReset();
		}
	}
}//CollisionRight()

//Resets the ball if the paddle was missed
void Ball::BallReset()
{
	//reverse X so it does not go in the same direction. Makes it FAIR!
	xVel = -xVel;
	//Reasing Y velcity or it stays the same
	yVel = 4.0f;

	//reassign X postion to the middle of the screen
	x = Graphics::ScreenWidth / 2;
	//reassign Y postion to the middle of the screen
	y = Graphics::ScreenHeight / 2;
}//BallReset()

//draw the ball
void Ball::DrawBall(Graphics& gfx) const
{
	gfx.PutPixel(5 + x, 0 + y,   198, 237, 44);
	gfx.PutPixel(6 + x, 0 + y,   198, 237, 44);
	gfx.PutPixel(7 + x, 0 + y,   198, 237, 44);
	gfx.PutPixel(8 + x, 0 + y,   198, 237, 44);
	gfx.PutPixel(9 + x, 0 + y,   198, 237, 44);
	gfx.PutPixel(10 + x, 0 + y,  198, 237, 44);
	gfx.PutPixel(11 + x, 0 + y,  198, 237, 44);
	gfx.PutPixel(12 + x, 0 + y,  198, 237, 44);
	gfx.PutPixel(13 + x, 0 + y,  198, 237, 44);
	gfx.PutPixel(14 + x, 0 + y,  198, 237, 44);
	gfx.PutPixel(4 + x, 1 + y,   198, 237, 44);
	gfx.PutPixel(5 + x, 1 + y,   198, 237, 44);
	gfx.PutPixel(6 + x, 1 + y,   198, 237, 44);
	gfx.PutPixel(7 + x, 1 + y,   198, 237, 44);
	gfx.PutPixel(8 + x, 1 + y,   198, 237, 44);
	gfx.PutPixel(9 + x, 1 + y,   198, 237, 44);
	gfx.PutPixel(10 + x, 1 + y,  198, 237, 44);
	gfx.PutPixel(11 + x, 1 + y,  198, 237, 44);
	gfx.PutPixel(12 + x, 1 + y,  198, 237, 44);
	gfx.PutPixel(13 + x, 1 + y,  198, 237, 44);
	gfx.PutPixel(14 + x, 1 + y,  198, 237, 44);
	gfx.PutPixel(15 + x, 1 + y,  198, 237, 44);
	gfx.PutPixel(2 + x, 2 + y,   198, 237, 44);
	gfx.PutPixel(3 + x, 2 + y,   198, 237, 44);
	gfx.PutPixel(4 + x, 2 + y,   198, 237, 44);
	gfx.PutPixel(5 + x, 2 + y,   198, 237, 44);
	gfx.PutPixel(6 + x, 2 + y,   198, 237, 44);
	gfx.PutPixel(7 + x, 2 + y,   198, 237, 44);
	gfx.PutPixel(8 + x, 2 + y,   198, 237, 44);
	gfx.PutPixel(9 + x, 2 + y,   198, 237, 44);
	gfx.PutPixel(10 + x, 2 + y,  198, 237, 44);
	gfx.PutPixel(11 + x, 2 + y,  198, 237, 44);
	gfx.PutPixel(12 + x, 2 + y,  198, 237, 44);
	gfx.PutPixel(13 + x, 2 + y,  198, 237, 44);
	gfx.PutPixel(14 + x, 2 + y,  198, 237, 44);
	gfx.PutPixel(15 + x, 2 + y,  198, 237, 44);
	gfx.PutPixel(16 + x, 2 + y,  198, 237, 44);
	gfx.PutPixel(17 + x, 2 + y,  198, 237, 44);
	gfx.PutPixel(2 + x, 3 + y,   198, 237, 44);
	gfx.PutPixel(3 + x, 3 + y,   198, 237, 44);
	gfx.PutPixel(4 + x, 3 + y,   198, 237, 44);
	gfx.PutPixel(5 + x, 3 + y,   198, 237, 44);
	gfx.PutPixel(6 + x, 3 + y,   198, 237, 44);
	gfx.PutPixel(7 + x, 3 + y,   198, 237, 44);
	gfx.PutPixel(8 + x, 3 + y,   198, 237, 44);
	gfx.PutPixel(9 + x, 3 + y,   198, 237, 44);
	gfx.PutPixel(10 + x, 3 + y,  198, 237, 44);
	gfx.PutPixel(11 + x, 3 + y,  198, 237, 44);
	gfx.PutPixel(12 + x, 3 + y,  198, 237, 44);
	gfx.PutPixel(13 + x, 3 + y,  198, 237, 44);
	gfx.PutPixel(14 + x, 3 + y,  198, 237, 44);
	gfx.PutPixel(15 + x, 3 + y,  198, 237, 44);
	gfx.PutPixel(16 + x, 3 + y,  198, 237, 44);
	gfx.PutPixel(17 + x, 3 + y,  198, 237, 44);
	gfx.PutPixel(1 + x, 4 + y,   198, 237, 44);
	gfx.PutPixel(2 + x, 4 + y,   198, 237, 44);
	gfx.PutPixel(3 + x, 4 + y,   198, 237, 44);
	gfx.PutPixel(4 + x, 4 + y,   198, 237, 44);
	gfx.PutPixel(5 + x, 4 + y,   198, 237, 44);
	gfx.PutPixel(6 + x, 4 + y,   198, 237, 44);
	gfx.PutPixel(7 + x, 4 + y,   198, 237, 44);
	gfx.PutPixel(8 + x, 4 + y,   198, 237, 44);
	gfx.PutPixel(9 + x, 4 + y,   198, 237, 44);
	gfx.PutPixel(10 + x, 4 + y,  198, 237, 44);
	gfx.PutPixel(11 + x, 4 + y,  198, 237, 44);
	gfx.PutPixel(12 + x, 4 + y,  198, 237, 44);
	gfx.PutPixel(13 + x, 4 + y,  198, 237, 44);
	gfx.PutPixel(14 + x, 4 + y,  198, 237, 44);
	gfx.PutPixel(15 + x, 4 + y,  198, 237, 44);
	gfx.PutPixel(16 + x, 4 + y,  198, 237, 44);
	gfx.PutPixel(17 + x, 4 + y,  198, 237, 44);
	gfx.PutPixel(18 + x, 4 + y,  198, 237, 44);
	gfx.PutPixel(0 + x, 5 + y,   198, 237, 44);
	gfx.PutPixel(1 + x, 5 + y,   198, 237, 44);
	gfx.PutPixel(2 + x, 5 + y,   198, 237, 44);
	gfx.PutPixel(3 + x, 5 + y,   198, 237, 44);
	gfx.PutPixel(4 + x, 5 + y,   198, 237, 44);
	gfx.PutPixel(5 + x, 5 + y,   198, 237, 44);
	gfx.PutPixel(6 + x, 5 + y,   198, 237, 44);
	gfx.PutPixel(7 + x, 5 + y,   198, 237, 44);
	gfx.PutPixel(8 + x, 5 + y,   198, 237, 44);
	gfx.PutPixel(9 + x, 5 + y,   198, 237, 44);
	gfx.PutPixel(10 + x, 5 + y,  198, 237, 44);
	gfx.PutPixel(11 + x, 5 + y,  198, 237, 44);
	gfx.PutPixel(12 + x, 5 + y,  198, 237, 44);
	gfx.PutPixel(13 + x, 5 + y,  198, 237, 44);
	gfx.PutPixel(14 + x, 5 + y,  198, 237, 44);
	gfx.PutPixel(15 + x, 5 + y,  198, 237, 44);
	gfx.PutPixel(16 + x, 5 + y,  198, 237, 44);
	gfx.PutPixel(17 + x, 5 + y,  198, 237, 44);
	gfx.PutPixel(18 + x, 5 + y,  198, 237, 44);
	gfx.PutPixel(19 + x, 5 + y,  198, 237, 44);
	gfx.PutPixel(0 + x, 6 + y,   198, 237, 44);
	gfx.PutPixel(1 + x, 6 + y,   198, 237, 44);
	gfx.PutPixel(2 + x, 6 + y,   198, 237, 44);
	gfx.PutPixel(3 + x, 6 + y,   198, 237, 44);
	gfx.PutPixel(4 + x, 6 + y,   198, 237, 44);
	gfx.PutPixel(5 + x, 6 + y,   198, 237, 44);
	gfx.PutPixel(6 + x, 6 + y,   198, 237, 44);
	gfx.PutPixel(7 + x, 6 + y,   198, 237, 44);
	gfx.PutPixel(8 + x, 6 + y,   198, 237, 44);
	gfx.PutPixel(9 + x, 6 + y,   198, 237, 44);
	gfx.PutPixel(10 + x, 6 + y,  198, 237, 44);
	gfx.PutPixel(11 + x, 6 + y,  198, 237, 44);
	gfx.PutPixel(12 + x, 6 + y,  198, 237, 44);
	gfx.PutPixel(13 + x, 6 + y,  198, 237, 44);
	gfx.PutPixel(14 + x, 6 + y,  198, 237, 44);
	gfx.PutPixel(15 + x, 6 + y,  198, 237, 44);
	gfx.PutPixel(16 + x, 6 + y,  198, 237, 44);
	gfx.PutPixel(17 + x, 6 + y,  198, 237, 44);
	gfx.PutPixel(18 + x, 6 + y,  198, 237, 44);
	gfx.PutPixel(19 + x, 6 + y,  198, 237, 44);
	gfx.PutPixel(0 + x, 7 + y,   198, 237, 44);
	gfx.PutPixel(1 + x, 7 + y,   198, 237, 44);
	gfx.PutPixel(2 + x, 7 + y,   198, 237, 44);
	gfx.PutPixel(3 + x, 7 + y,   198, 237, 44);
	gfx.PutPixel(4 + x, 7 + y,   198, 237, 44);
	gfx.PutPixel(5 + x, 7 + y,   198, 237, 44);
	gfx.PutPixel(6 + x, 7 + y,   198, 237, 44);
	gfx.PutPixel(7 + x, 7 + y,   198, 237, 44);
	gfx.PutPixel(8 + x, 7 + y,   198, 237, 44);
	gfx.PutPixel(9 + x, 7 + y,   198, 237, 44);
	gfx.PutPixel(10 + x, 7 + y,  198, 237, 44);
	gfx.PutPixel(11 + x, 7 + y,  198, 237, 44);
	gfx.PutPixel(12 + x, 7 + y,  198, 237, 44);
	gfx.PutPixel(13 + x, 7 + y,  198, 237, 44);
	gfx.PutPixel(14 + x, 7 + y,  198, 237, 44);
	gfx.PutPixel(15 + x, 7 + y,  198, 237, 44);
	gfx.PutPixel(16 + x, 7 + y,  198, 237, 44);
	gfx.PutPixel(17 + x, 7 + y,  198, 237, 44);
	gfx.PutPixel(18 + x, 7 + y,  198, 237, 44);
	gfx.PutPixel(19 + x, 7 + y,  198, 237, 44);
	gfx.PutPixel(0 + x, 8 + y,   198, 237, 44);
	gfx.PutPixel(1 + x, 8 + y,   198, 237, 44);
	gfx.PutPixel(2 + x, 8 + y,   198, 237, 44);
	gfx.PutPixel(3 + x, 8 + y,   198, 237, 44);
	gfx.PutPixel(4 + x, 8 + y,   198, 237, 44);
	gfx.PutPixel(5 + x, 8 + y,   198, 237, 44);
	gfx.PutPixel(6 + x, 8 + y,   198, 237, 44);
	gfx.PutPixel(7 + x, 8 + y,   198, 237, 44);
	gfx.PutPixel(8 + x, 8 + y,   198, 237, 44);
	gfx.PutPixel(9 + x, 8 + y,   198, 237, 44);
	gfx.PutPixel(10 + x, 8 + y,  198, 237, 44);
	gfx.PutPixel(11 + x, 8 + y,  198, 237, 44);
	gfx.PutPixel(12 + x, 8 + y,  198, 237, 44);
	gfx.PutPixel(13 + x, 8 + y,  198, 237, 44);
	gfx.PutPixel(14 + x, 8 + y,  198, 237, 44);
	gfx.PutPixel(15 + x, 8 + y,  198, 237, 44);
	gfx.PutPixel(16 + x, 8 + y,  198, 237, 44);
	gfx.PutPixel(17 + x, 8 + y,  198, 237, 44);
	gfx.PutPixel(18 + x, 8 + y,  198, 237, 44);
	gfx.PutPixel(19 + x, 8 + y,  198, 237, 44);
	gfx.PutPixel(0 + x, 9 + y,   198, 237, 44);
	gfx.PutPixel(1 + x, 9 + y,   198, 237, 44);
	gfx.PutPixel(2 + x, 9 + y,   198, 237, 44);
	gfx.PutPixel(3 + x, 9 + y,   198, 237, 44);
	gfx.PutPixel(4 + x, 9 + y,   198, 237, 44);
	gfx.PutPixel(5 + x, 9 + y,   198, 237, 44);
	gfx.PutPixel(6 + x, 9 + y,   198, 237, 44);
	gfx.PutPixel(7 + x, 9 + y,   198, 237, 44);
	gfx.PutPixel(8 + x, 9 + y,   198, 237, 44);
	gfx.PutPixel(9 + x, 9 + y,   198, 237, 44);
	gfx.PutPixel(10 + x, 9 + y,  198, 237, 44);
	gfx.PutPixel(11 + x, 9 + y,  198, 237, 44);
	gfx.PutPixel(12 + x, 9 + y,  198, 237, 44);
	gfx.PutPixel(13 + x, 9 + y,  198, 237, 44);
	gfx.PutPixel(14 + x, 9 + y,  198, 237, 44);
	gfx.PutPixel(15 + x, 9 + y,  198, 237, 44);
	gfx.PutPixel(16 + x, 9 + y,  198, 237, 44);
	gfx.PutPixel(17 + x, 9 + y,  198, 237, 44);
	gfx.PutPixel(18 + x, 9 + y,  198, 237, 44);
	gfx.PutPixel(19 + x, 9 + y,  198, 237, 44);
	gfx.PutPixel(0 + x, 10 + y,  198, 237, 44);
	gfx.PutPixel(1 + x, 10 + y,  198, 237, 44);
	gfx.PutPixel(2 + x, 10 + y,  198, 237, 44);
	gfx.PutPixel(3 + x, 10 + y,  198, 237, 44);
	gfx.PutPixel(4 + x, 10 + y,  198, 237, 44);
	gfx.PutPixel(5 + x, 10 + y,  198, 237, 44);
	gfx.PutPixel(6 + x, 10 + y,  198, 237, 44);
	gfx.PutPixel(7 + x, 10 + y,  198, 237, 44);
	gfx.PutPixel(8 + x, 10 + y,  198, 237, 44);
	gfx.PutPixel(9 + x, 10 + y,  198, 237, 44);
	gfx.PutPixel(10 + x, 10 + y, 198, 237, 44);
	gfx.PutPixel(11 + x, 10 + y, 198, 237, 44);
	gfx.PutPixel(12 + x, 10 + y, 198, 237, 44);
	gfx.PutPixel(13 + x, 10 + y, 198, 237, 44);
	gfx.PutPixel(14 + x, 10 + y, 198, 237, 44);
	gfx.PutPixel(15 + x, 10 + y, 198, 237, 44);
	gfx.PutPixel(16 + x, 10 + y, 198, 237, 44);
	gfx.PutPixel(17 + x, 10 + y, 198, 237, 44);
	gfx.PutPixel(18 + x, 10 + y, 198, 237, 44);
	gfx.PutPixel(19 + x, 10 + y, 198, 237, 44);
	gfx.PutPixel(0 + x, 11 + y,  198, 237, 44);
	gfx.PutPixel(1 + x, 11 + y,  198, 237, 44);
	gfx.PutPixel(2 + x, 11 + y,  198, 237, 44);
	gfx.PutPixel(3 + x, 11 + y,  198, 237, 44);
	gfx.PutPixel(4 + x, 11 + y,  198, 237, 44);
	gfx.PutPixel(5 + x, 11 + y,  198, 237, 44);
	gfx.PutPixel(6 + x, 11 + y,  198, 237, 44);
	gfx.PutPixel(7 + x, 11 + y,  198, 237, 44);
	gfx.PutPixel(8 + x, 11 + y,  198, 237, 44);
	gfx.PutPixel(9 + x, 11 + y,  198, 237, 44);
	gfx.PutPixel(10 + x, 11 + y, 198, 237, 44);
	gfx.PutPixel(11 + x, 11 + y, 198, 237, 44);
	gfx.PutPixel(12 + x, 11 + y, 198, 237, 44);
	gfx.PutPixel(13 + x, 11 + y, 198, 237, 44);
	gfx.PutPixel(14 + x, 11 + y, 198, 237, 44);
	gfx.PutPixel(15 + x, 11 + y, 198, 237, 44);
	gfx.PutPixel(16 + x, 11 + y, 198, 237, 44);
	gfx.PutPixel(17 + x, 11 + y, 198, 237, 44);
	gfx.PutPixel(18 + x, 11 + y, 198, 237, 44);
	gfx.PutPixel(19 + x, 11 + y, 198, 237, 44);
	gfx.PutPixel(0 + x, 12 + y,  198, 237, 44);
	gfx.PutPixel(1 + x, 12 + y,  198, 237, 44);
	gfx.PutPixel(2 + x, 12 + y,  198, 237, 44);
	gfx.PutPixel(3 + x, 12 + y,  198, 237, 44);
	gfx.PutPixel(4 + x, 12 + y,  198, 237, 44);
	gfx.PutPixel(5 + x, 12 + y,  198, 237, 44);
	gfx.PutPixel(6 + x, 12 + y,  198, 237, 44);
	gfx.PutPixel(7 + x, 12 + y,  198, 237, 44);
	gfx.PutPixel(8 + x, 12 + y,  198, 237, 44);
	gfx.PutPixel(9 + x, 12 + y,  198, 237, 44);
	gfx.PutPixel(10 + x, 12 + y, 198, 237, 44);
	gfx.PutPixel(11 + x, 12 + y, 198, 237, 44);
	gfx.PutPixel(12 + x, 12 + y, 198, 237, 44);
	gfx.PutPixel(13 + x, 12 + y, 198, 237, 44);
	gfx.PutPixel(14 + x, 12 + y, 198, 237, 44);
	gfx.PutPixel(15 + x, 12 + y, 198, 237, 44);
	gfx.PutPixel(16 + x, 12 + y, 198, 237, 44);
	gfx.PutPixel(17 + x, 12 + y, 198, 237, 44);
	gfx.PutPixel(18 + x, 12 + y, 198, 237, 44);
	gfx.PutPixel(19 + x, 12 + y, 198, 237, 44);
	gfx.PutPixel(0 + x, 13 + y,  198, 237, 44);
	gfx.PutPixel(1 + x, 13 + y,  198, 237, 44);
	gfx.PutPixel(2 + x, 13 + y,  198, 237, 44);
	gfx.PutPixel(3 + x, 13 + y,  198, 237, 44);
	gfx.PutPixel(4 + x, 13 + y,  198, 237, 44);
	gfx.PutPixel(5 + x, 13 + y,  198, 237, 44);
	gfx.PutPixel(6 + x, 13 + y,  198, 237, 44);
	gfx.PutPixel(7 + x, 13 + y,  198, 237, 44);
	gfx.PutPixel(8 + x, 13 + y,  198, 237, 44);
	gfx.PutPixel(9 + x, 13 + y,  198, 237, 44);
	gfx.PutPixel(10 + x, 13 + y, 198, 237, 44);
	gfx.PutPixel(11 + x, 13 + y, 198, 237, 44);
	gfx.PutPixel(12 + x, 13 + y, 198, 237, 44);
	gfx.PutPixel(13 + x, 13 + y, 198, 237, 44);
	gfx.PutPixel(14 + x, 13 + y, 198, 237, 44);
	gfx.PutPixel(15 + x, 13 + y, 198, 237, 44);
	gfx.PutPixel(16 + x, 13 + y, 198, 237, 44);
	gfx.PutPixel(17 + x, 13 + y, 198, 237, 44);
	gfx.PutPixel(18 + x, 13 + y, 198, 237, 44);
	gfx.PutPixel(19 + x, 13 + y, 198, 237, 44);
	gfx.PutPixel(0 + x, 14 + y,  198, 237, 44);
	gfx.PutPixel(1 + x, 14 + y,  198, 237, 44);
	gfx.PutPixel(2 + x, 14 + y,  198, 237, 44);
	gfx.PutPixel(3 + x, 14 + y,  198, 237, 44);
	gfx.PutPixel(4 + x, 14 + y,  198, 237, 44);
	gfx.PutPixel(5 + x, 14 + y,  198, 237, 44);
	gfx.PutPixel(6 + x, 14 + y,  198, 237, 44);
	gfx.PutPixel(7 + x, 14 + y,  198, 237, 44);
	gfx.PutPixel(8 + x, 14 + y,  198, 237, 44);
	gfx.PutPixel(9 + x, 14 + y,  198, 237, 44);
	gfx.PutPixel(10 + x, 14 + y, 198, 237, 44);
	gfx.PutPixel(11 + x, 14 + y, 198, 237, 44);
	gfx.PutPixel(12 + x, 14 + y, 198, 237, 44);
	gfx.PutPixel(13 + x, 14 + y, 198, 237, 44);
	gfx.PutPixel(14 + x, 14 + y, 198, 237, 44);
	gfx.PutPixel(15 + x, 14 + y, 198, 237, 44);
	gfx.PutPixel(16 + x, 14 + y, 198, 237, 44);
	gfx.PutPixel(17 + x, 14 + y, 198, 237, 44);
	gfx.PutPixel(18 + x, 14 + y, 198, 237, 44);
	gfx.PutPixel(19 + x, 14 + y, 198, 237, 44);
	gfx.PutPixel(1 + x, 15 + y,  198, 237, 44);
	gfx.PutPixel(2 + x, 15 + y,  198, 237, 44);
	gfx.PutPixel(3 + x, 15 + y,  198, 237, 44);
	gfx.PutPixel(4 + x, 15 + y,  198, 237, 44);
	gfx.PutPixel(5 + x, 15 + y,  198, 237, 44);
	gfx.PutPixel(6 + x, 15 + y,  198, 237, 44);
	gfx.PutPixel(7 + x, 15 + y,  198, 237, 44);
	gfx.PutPixel(8 + x, 15 + y,  198, 237, 44);
	gfx.PutPixel(9 + x, 15 + y,  198, 237, 44);
	gfx.PutPixel(10 + x, 15 + y, 198, 237, 44);
	gfx.PutPixel(11 + x, 15 + y, 198, 237, 44);
	gfx.PutPixel(12 + x, 15 + y, 198, 237, 44);
	gfx.PutPixel(13 + x, 15 + y, 198, 237, 44);
	gfx.PutPixel(14 + x, 15 + y, 198, 237, 44);
	gfx.PutPixel(15 + x, 15 + y, 198, 237, 44);
	gfx.PutPixel(16 + x, 15 + y, 198, 237, 44);
	gfx.PutPixel(17 + x, 15 + y, 198, 237, 44);
	gfx.PutPixel(18 + x, 15 + y, 198, 237, 44);
	gfx.PutPixel(2 + x, 16 + y,  198, 237, 44);
	gfx.PutPixel(3 + x, 16 + y,  198, 237, 44);
	gfx.PutPixel(4 + x, 16 + y,  198, 237, 44);
	gfx.PutPixel(5 + x, 16 + y,  198, 237, 44);
	gfx.PutPixel(6 + x, 16 + y,  198, 237, 44);
	gfx.PutPixel(7 + x, 16 + y,  198, 237, 44);
	gfx.PutPixel(8 + x, 16 + y,  198, 237, 44);
	gfx.PutPixel(9 + x, 16 + y,  198, 237, 44);
	gfx.PutPixel(10 + x, 16 + y, 198, 237, 44);
	gfx.PutPixel(11 + x, 16 + y, 198, 237, 44);
	gfx.PutPixel(12 + x, 16 + y, 198, 237, 44);
	gfx.PutPixel(13 + x, 16 + y, 198, 237, 44);
	gfx.PutPixel(14 + x, 16 + y, 198, 237, 44);
	gfx.PutPixel(15 + x, 16 + y, 198, 237, 44);
	gfx.PutPixel(16 + x, 16 + y, 198, 237, 44);
	gfx.PutPixel(17 + x, 16 + y, 198, 237, 44);
	gfx.PutPixel(2 + x, 17 + y,  198, 237, 44);
	gfx.PutPixel(3 + x, 17 + y,  198, 237, 44);
	gfx.PutPixel(4 + x, 17 + y,  198, 237, 44);
	gfx.PutPixel(5 + x, 17 + y,  198, 237, 44);
	gfx.PutPixel(6 + x, 17 + y,  198, 237, 44);
	gfx.PutPixel(7 + x, 17 + y,  198, 237, 44);
	gfx.PutPixel(8 + x, 17 + y,  198, 237, 44);
	gfx.PutPixel(9 + x, 17 + y,  198, 237, 44);
	gfx.PutPixel(10 + x, 17 + y, 198, 237, 44);
	gfx.PutPixel(11 + x, 17 + y, 198, 237, 44);
	gfx.PutPixel(12 + x, 17 + y, 198, 237, 44);
	gfx.PutPixel(13 + x, 17 + y, 198, 237, 44);
	gfx.PutPixel(14 + x, 17 + y, 198, 237, 44);
	gfx.PutPixel(15 + x, 17 + y, 198, 237, 44);
	gfx.PutPixel(16 + x, 17 + y, 198, 237, 44);
	gfx.PutPixel(17 + x, 17 + y, 198, 237, 44);
	gfx.PutPixel(4 + x, 18 + y,  198, 237, 44);
	gfx.PutPixel(5 + x, 18 + y,  198, 237, 44);
	gfx.PutPixel(6 + x, 18 + y,  198, 237, 44);
	gfx.PutPixel(7 + x, 18 + y,  198, 237, 44);
	gfx.PutPixel(8 + x, 18 + y,  198, 237, 44);
	gfx.PutPixel(9 + x, 18 + y,  198, 237, 44);
	gfx.PutPixel(10 + x, 18 + y, 198, 237, 44);
	gfx.PutPixel(11 + x, 18 + y, 198, 237, 44);
	gfx.PutPixel(12 + x, 18 + y, 198, 237, 44);
	gfx.PutPixel(13 + x, 18 + y, 198, 237, 44);
	gfx.PutPixel(14 + x, 18 + y, 198, 237, 44);
	gfx.PutPixel(15 + x, 18 + y, 198, 237, 44);
	gfx.PutPixel(5 + x, 19 + y,  198, 237, 44);
	gfx.PutPixel(6 + x, 19 + y,  198, 237, 44);
	gfx.PutPixel(7 + x, 19 + y,  198, 237, 44);
	gfx.PutPixel(8 + x, 19 + y,  198, 237, 44);
	gfx.PutPixel(9 + x, 19 + y,  198, 237, 44);
	gfx.PutPixel(10 + x, 19 + y, 198, 237, 44);
	gfx.PutPixel(11 + x, 19 + y, 198, 237, 44);
	gfx.PutPixel(12 + x, 19 + y, 198, 237, 44);
	gfx.PutPixel(13 + x, 19 + y, 198, 237, 44);
	gfx.PutPixel(14 + x, 19 + y, 198, 237, 44);

}


