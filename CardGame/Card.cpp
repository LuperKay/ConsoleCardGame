#include "Card.h"
#include "Player.h"
#include <iostream>
#include <format>

Card::Card(string name, int damage, int heal, function<void(Card& card)> affect)
    : name(name), damage(damage), heal(heal), cardAffectCard(affect) {}

void Card::printValues()
{
    std::cout << "Card name: " << name << ", card damage: " << damage << ", card heal: " << heal << std::endl;
}

void Card::setDamage(int cardDamage)
{
    damage = cardDamage;
}

int Card::getDamage()
{
    return damage;
}

string Card::getName()
{
    return name;
}

void Card::affectCard(Card& card)
{
    cardAffectCard(card);
}

