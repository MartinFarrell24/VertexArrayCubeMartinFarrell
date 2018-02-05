#include "Game.h"

bool updatable = false;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	m_vertexes[0] = { 1.f, 1.f, -5.f };
	m_vertexes[1] = {-1.f, 1.f, -5.f };
	m_vertexes[2] = {-1.f, -1.f, -5.f};
	m_vertexes[3] = {1.f, -1.f, -5.f };
	m_vertexes[4] = { 1.0f, 1.0f, -10.0f };
	m_vertexes[5] = { -1.0f, 1.0f, -10.0f };
	m_vertexes[6] = { -1.0f, -1.0f, -10.0f };
	m_vertexes[7] = { 1.0f, -1.0f, -10.0f };

	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(m_vertexes[0].x,m_vertexes[0].y,m_vertexes[0].z);
		glVertex3f(m_vertexes[1].x, m_vertexes[1].y, m_vertexes[1].z);
		glVertex3f(m_vertexes[2].x, m_vertexes[2].y, m_vertexes[2].z);
		
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(m_vertexes[0].x, m_vertexes[0].y, m_vertexes[0].z);
		glVertex3f(m_vertexes[3].x, m_vertexes[3].y, m_vertexes[3].z);
		glVertex3f(m_vertexes[2].x, m_vertexes[2].y, m_vertexes[2].z);
		
		glColor3f(1.f, 0.f, 0.f);
		glVertex3f(m_vertexes[4].x, m_vertexes[4].y, m_vertexes[4].z);
		glVertex3f(m_vertexes[5].x, m_vertexes[5].y, m_vertexes[5].z);
		glVertex3f(m_vertexes[6].x, m_vertexes[6].y, m_vertexes[6].z);
		
		glColor3f(1.f, 0.f, 0.f);
		glVertex3f(m_vertexes[4].x, m_vertexes[4].y, m_vertexes[4].z);
		glVertex3f(m_vertexes[7].x, m_vertexes[7].y, m_vertexes[7].z);
		glVertex3f(m_vertexes[6].x, m_vertexes[6].y, m_vertexes[6].z);

		glColor3f(1.f, 0.f, 1.f);
		glVertex3f(m_vertexes[1].x, m_vertexes[1].y, m_vertexes[1].z); // -1,1,5
		glVertex3f(m_vertexes[5].x, m_vertexes[5].y, m_vertexes[5].z); // -1,1,15
		glVertex3f(m_vertexes[6].x, m_vertexes[6].y, m_vertexes[6].z); // -1,-1,15
		
		glColor3f(1.f, 0.f, 1.f);
		glVertex3f(m_vertexes[6].x, m_vertexes[6].y, m_vertexes[6].z);
		glVertex3f(m_vertexes[2].x, m_vertexes[2].y, m_vertexes[2].z);
		glVertex3f(m_vertexes[1].x, m_vertexes[1].y, m_vertexes[1].z);
		
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(m_vertexes[7].x, m_vertexes[7].y, m_vertexes[7].z);
		glVertex3f(m_vertexes[6].x, m_vertexes[6].y, m_vertexes[6].z);
		glVertex3f(m_vertexes[2].x, m_vertexes[2].y, m_vertexes[2].z);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(m_vertexes[7].x, m_vertexes[7].y, m_vertexes[7].z);
		glVertex3f(m_vertexes[3].x, m_vertexes[3].y, m_vertexes[3].z);
		glVertex3f(m_vertexes[2].x, m_vertexes[2].y, m_vertexes[2].z);

		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(m_vertexes[1].x, m_vertexes[1].y, m_vertexes[1].z);
		glVertex3f(m_vertexes[5].x, m_vertexes[5].y, m_vertexes[5].z);
		glVertex3f(m_vertexes[6].x, m_vertexes[6].y, m_vertexes[6].z);

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(m_vertexes[1].x, m_vertexes[1].y, m_vertexes[1].z);
		glVertex3f(m_vertexes[2].x, m_vertexes[2].y, m_vertexes[2].z);
		glVertex3f(m_vertexes[6].x, m_vertexes[6].y, m_vertexes[6].z);

		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(m_vertexes[3].x, m_vertexes[3].y, m_vertexes[3].z);
		glVertex3f(m_vertexes[0].x, m_vertexes[0].y, m_vertexes[0].z);
		glVertex3f(m_vertexes[4].x, m_vertexes[4].y, m_vertexes[4].z);

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(m_vertexes[3].x, m_vertexes[3].y, m_vertexes[3].z);
		glVertex3f(m_vertexes[7].x, m_vertexes[7].y, m_vertexes[7].z);
		glVertex3f(m_vertexes[4].x, m_vertexes[4].y, m_vertexes[4].z);
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	glLoadIdentity();
	//glRotatef(rotationAngle, 0, 1, 0); // Rotates the camera on Y Axis
	
		
	
	glCallList(1);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

