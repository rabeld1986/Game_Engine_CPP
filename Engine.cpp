#include "Engine.h"
#include <iostream>
#include "TextureManager.h"


Engine* Engine::s_Instance = nullptr;

bool Engine::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 || IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
		SDL_Log("Failed to initialize SDL! %n", SDL_GetError());
		return m_IsRunning = false;
		
	}

	m_Window = SDL_CreateWindow("Soft Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, 0);
	
	if (m_Window == nullptr) {
		SDL_Log("Failed to create window! %n", SDL_GetError());
		return m_IsRunning = false;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	if (m_Renderer == nullptr) {
		SDL_Log("Failed to create renderer! %n", SDL_GetError());
		return m_IsRunning = false;
	}

	TextureManager::GetInstance()->Load("tree","Assets/appletree.png");
	return m_IsRunning = true;
}

bool Engine::Clean()
{
	return false;
}

void Engine::Quit()
{
	m_IsRunning = false;
}

void Engine::Update()
{
	SDL_Log("Something");
}

void Engine::Render()
{
	SDL_SetRenderDrawColor(m_Renderer,124,210,254,255);
	SDL_RenderClear(m_Renderer);
	TextureManager::GetInstance()->Draw("tree", 100, 100,560, 700);
	SDL_RenderPresent(m_Renderer);
}

void Engine::Events()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type) {
		case SDL_QUIT:
			Quit();
			break;
	}
}