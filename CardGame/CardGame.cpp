#include <iostream>
#include "Player.h"
#include "Card.h"
#include <optional>

int randomMax(int max) {
    std::srand(std::time(0)); // Seed the random number generator (only needed once)
    return std::rand() % (max + 1);   
}

bool endGame()
{
	string answer;
	std::cout << "Do you want to restart? y/n : ";
	std::getline(std::cin, answer);

	if (answer == "y")
	{
		return false;
	}
	else if (answer == "n")
	{
		return true;
	}
	else
	{
		std::cout << "Unexpect input, bye!" << std::endl;
		return true;
	}
}

int main()
{
	Player realPlayer;
	Player botPlayer;

	realPlayer.setName("Player");
	botPlayer.setName("Bot");

	Card attackCard("Attack", 4);
	Card counterAttackCard(
		"Counter-attack",
		1,
		0,
		[attackCardName = attackCard.getName()](Card& card) {
			if (card.getName() == attackCardName)
			{
				card.setDamage(0);
			}
		}
	);
	Card holyAttackCard("Holy Attack", 1, 2);

	Card cards[] = { attackCard, counterAttackCard, holyAttackCard };

	int turnNumber = 0;
	string enteredCardName;

	while (true)
	{		
		turnNumber++;
		std::cout << "Turn #" << turnNumber << std::endl;

		// 1. Pick card
		// 1.1 Bot pick card

		int randNumber = randomMax(2);

		botPlayer.setCard(cards[randNumber]);

		// 1.2 Player pick card 

		string cardList;

		for (int i = 0; i < std::size(cards); i++)
		{
			cardList += cards[i].getName() + ", ";
		}

		// 1.2.1 Accept user input
		
		std::cout << "Enter card name from the list to play that card: " << cardList << std::endl;
		std::getline(std::cin, enteredCardName);
		std::cout << "Chosen card: " << enteredCardName << std::endl;

		// 1.2.2 Search user card in array

		Card* userCard = nullptr;

		for (int i = 0; i < std::size(cards); i++)
		{
			if (cards[i].getName() == enteredCardName)
			{
				userCard = &cards[i];
			}

		}

		// 1.2.3 Check if we find input card, write it into user or show error

		if (userCard)
		{
			realPlayer.setCard(*userCard);
		}
		else
		{
			std::cout << "Entered card does not exist, please enter card from the list: " << cardList << std::endl;
		}

		// 2. Apply cards affect to each other (card to card)

		botPlayer.getCard().affectCard(realPlayer.getCard());
		realPlayer.getCard().affectCard(botPlayer.getCard());

		// 3. Apply cards affect to players

		realPlayer.setHP(realPlayer.getHP() - botPlayer.getCard().getDamage());
		botPlayer.setHP(botPlayer.getHP() - realPlayer.getCard().getDamage());

		realPlayer.printValues();
		botPlayer.printValues();

		// 4. End game check.

		if (botPlayer.isDead() && realPlayer.isDead())
		{
			std::cout << "Draw!" << std::endl;
		}
		else if (realPlayer.isDead())
		{
			std::cout << "You lose!" << std::endl;
		}
		else if (botPlayer.isDead())
		{
			std::cout << "You win!" << std::endl;
		}

		// 5. Restar?

		if (realPlayer.isDead() || botPlayer.isDead())
		{
			if (endGame())
			{
				return 0;
			}
			
			realPlayer.setHP(10);
			botPlayer.setHP(10);
			turnNumber = 0;
		}
	}

	return 0;
}