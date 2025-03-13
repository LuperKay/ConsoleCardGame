#pragma once
#include <string> 
#include <functional>
using namespace std;

class Card
{
private:
	int damage;
	int heal;
	string name;
	function<void(Card& card)> cardAffectCard;

public:
	Card(string name = "Unknown", int damage = 0, int heal = 0, function<void(Card& card)> affect = [](Card& card){});

	void printValues();
	void setDamage(int cardDamage);
	int getDamage();
	string getName();
	void affectCard(Card& card);
};

