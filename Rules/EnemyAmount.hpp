#pragma once

template <int cat, int owl, int zombie>	
class EnemyAmount  
{
	private:
		int catAmount;
		int owlAmount;
		int zombieAmount;
		int enemiesAmount;
	public:

		EnemyAmount(){
			this->catAmount = cat;
			this->owlAmount = owl;
			this->zombieAmount = zombie;
			this->enemiesAmount = cat + owl + zombie;
		}
		int getCatCounter(){return catAmount;}
		int getOwlCounter(){return owlAmount;}
		int getZombieCounter(){return zombieAmount;}
		int getEnemiesCounter(){return enemiesAmount;}
		void reduceEnemiesCounter(){this->enemiesAmount --;}

};