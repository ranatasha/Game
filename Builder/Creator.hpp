#pragma once
	
class Creator  
{
	public:
		virtual ~Creator() = default;
		virtual void ResetEnemies() = 0;
		virtual void ResetItems() = 0;
		virtual void CreatePlayer() = 0;
		virtual void CreateEnemies(int cat, int owl, int zombie) = 0;
		virtual void CreateItems(int cheese, int sword, int key) = 0;
};