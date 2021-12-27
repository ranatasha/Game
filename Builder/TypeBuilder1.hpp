#pragma once
#include "../Map/Map.h"
#include "Builder.hpp"

class TypeBuilder1: public Builder {
	private:
		Map* map;

	public:
		TypeBuilder1();
		void Reset() override;
		void FillEmptyField() override;
		void CreateObstacles() override;
		void CreateExits() override;

		Map* getMap();
		~TypeBuilder1();

};