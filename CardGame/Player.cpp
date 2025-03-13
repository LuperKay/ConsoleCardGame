#include "Player.h"
#include "Card.h"
#include <iostream>

void Player::setName(string playerName)
{
	name = playerName;
}

int Player::getHP()
{
	return hp;
}

Card& Player::getCard()
{
	 return pickedCard;
}

void Player::setHP(int health)
{
	hp = health;
}

void Player::printValues()
{
	std::cout << "Name: " << name << ", hp: " << hp << std::endl;
	pickedCard.printValues();
}

void Player::setCard(Card otherCard)
{
	pickedCard = otherCard;
}

bool Player::isDead()
{
	return hp < 1;
}

