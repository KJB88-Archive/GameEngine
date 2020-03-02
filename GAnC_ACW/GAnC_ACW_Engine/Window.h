#pragma once

class Game;

class Window
{
public:

	Window(int screenWidth, int screenHeight, Game* game, float screenDepth, float screenNear)
		: m_screenWidth(screenWidth), m_screenHeight(screenHeight), m_game(game), m_screenDepth(screenDepth), m_screenNear(screenNear) {};
	virtual ~Window() {};

	virtual void Run() = 0;

protected:

	Game* m_game;

	int m_screenWidth;
	int m_screenHeight;
	float m_screenDepth;
	float m_screenNear;
};

