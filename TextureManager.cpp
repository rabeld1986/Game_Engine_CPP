#include "TextureManager.h"
#include "Engine.h"

TextureManager* TextureManager::s_Instance = nullptr;

bool TextureManager::Load(std::string id, std::string filename)
{
	SDL_Surface* surface = IMG_Load(filename.c_str());

	if (surface == nullptr) {
		SDL_Log("Failed to load texture: %n, %n",filename.c_str(), SDL_GetError());
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);

	if (texture == nullptr) {
		SDL_Log("Failed to load texture: %n",SDL_GetError());
		return false;
	}

	m_TextureMap[id] = texture;
	return true;
}


void TextureManager::Draw(std::string id, int x, int y, int width, int heigth, SDL_RendererFlip flip)
{
	SDL_Rect srcRect = { 0, 0, width, heigth };
	SDL_Rect destRect = { x, y, width, heigth };
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &destRect,0, nullptr,flip);
}

void TextureManager::Drop(std::string id)
{
	SDL_DestroyTexture();
}

void TextureManager::Clean()
{
}

