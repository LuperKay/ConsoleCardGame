#pragma once
#include "Card.h"

class Player
{
private:
	int hp = 10;
	Card pickedCard;
	string name;

public:
	void setName(string playerName);
	int getHP();
	void printValues();
	void setCard(Card otherCard);
	Card& getCard();
	void setHP(int hp);
	bool isDead();
};

