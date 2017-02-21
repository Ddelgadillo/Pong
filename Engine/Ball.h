#pragma once
#include "Graphics.h"
#include "Paddle.h"

class Ball
{
public:
	//Comments in delclarations
	Ball(int xPos, int yPos, float ballXVel, float ballYVel);
	void Update();
	int getY() const;
	void CollisionLeft(Paddle& paddle);
	void CollisionRight(Paddle& paddle);
	void BallReset();
	void DrawBall(Graphics& gfx) const;
private:
	int x; //Ball X position
	int y; //Ball Y postion
	static constexpr int width = 20; //Ball width
	static constexpr int height = 20; //Ball Height
	float xVel; //Ball X velocity
	float yVel; //Ball Y velocity
	void ClampScreen(); //Makes sure ball does not leave screen from top or bottom
};