/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rng(rd()),
	ballXPos(300, 500),
	ballYPos(20, 580),
	ball(390, ballYPos(rng), 8.0f, 4.0f),
	paddle1(1, 280),
	paddle2((Graphics::ScreenWidth - 16) , 280)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	//Moves player paddle
	paddle1.MovePaddle(wnd);
	//Moves the ball
	ball.Update();
	//Checks for collison with player paddle
	ball.CollisionLeft(paddle1);
	//Checks for collison with computer paddle
	ball.CollisionRight(paddle2);
	//AI to move computer paddle
	computerAI();
}

void Game::ComposeFrame()
{
	DrawCourt();
	DrawNet();
	//Draws the ball
	ball.DrawBall(gfx);
	//Draws the player paddle
	paddle1.DrawPaddle(gfx);
	//Draws the computer paddle
	paddle2.DrawPaddle(gfx);
}

//AI for computer paddle
void Game::computerAI()
{
	//Gets the mid point of the computer paddle
	int center = paddle2.GetY() + (paddle2.GetHeight() / 2);

	//If the center is less then the ball go down
	if (center < ball.getY() - 35)
	{
		paddle2.y += 8;
	}
	else if (center > ball.getY() + 35) //If the center is less then the ball go up
	{
		paddle2.y -= 8;
	}

	//make sure computer paddle does not go out of the screen
	paddle2.ClampToScreen();
}

void Game::DrawCourt()
{
	Color court;
	court.SetR(94);
	court.SetG(150);
	court.SetB(91);

	gfx.DrawRect(15, 15, gfx.ScreenHeight - 30, gfx.ScreenWidth - 30, court);
}

void Game::DrawNet()
{
	Color net;
	net.SetR(255);
	net.SetG(255);
	net.SetB(255);

	gfx.DrawRect((gfx.ScreenWidth / 2) - 5, 15,   80, 5, net);
	gfx.DrawRect((gfx.ScreenWidth / 2) - 5, 105, 80, 5, net);
	gfx.DrawRect((gfx.ScreenWidth / 2) - 5, 205, 80, 5, net);
	gfx.DrawRect((gfx.ScreenWidth / 2) - 5, 305, 80, 5, net);
	gfx.DrawRect((gfx.ScreenWidth / 2) - 5, 405, 80, 5, net);
	gfx.DrawRect((gfx.ScreenWidth / 2) - 5, 505, 80, 5, net);
}
