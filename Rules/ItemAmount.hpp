#pragma once

template <int cheese, int sword, int key>	
class ItemAmount  
{
	private:
		int cheeseAmount;
		int swordAmount;
		int keyAmount;
		int itemsAmount;
	public:

		ItemAmount(){
			this->cheeseAmount = cheese;
			this->swordAmount = sword;
			this->keyAmount = key;
			this->itemsAmount = cheese + sword + key;
		}
		int getCheeseCounter(){return cheeseAmount;}
		int getSwordCounter(){return swordAmount;}
		int getKeyCounter(){return keyAmount;}
		int getItemsCounter(){return itemsAmount;}
		void reduceItemsCounter(){this->itemsAmount --;}

};