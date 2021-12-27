#pragma once
#include "Builder.hpp"
#include "Creator.hpp"	
class Director  
{
	private:
		Builder* pBuilder;
		Creator* pCreator;
	public:
		void setBuilder(Builder* pBuilder);
		void createMap();

		void setCreator(Creator* pCreator);
		void createObjects(int cat, int owl, int zombie, int cheese, int sword, int key);

};