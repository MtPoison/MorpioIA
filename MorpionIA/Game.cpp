#include "Game.h"


void Game::partie()
{
	Joueur j1('O', mort);
	Joueur j2('X', mort);
	IA ia('X', mort, j1.getSigne());

	mort.generateCarte();
	mort.printCarte();

	int i = 0;

	while (i <= 9) {
		std::cout << "jouer 1 " << "\n";
		j1.posePoint();
		mort.printCarte();
		if (mort.verifieWin(j1.getSigne()))
		{
			std::cout << "j1 game";
			break;
		}
		std::cout << "IA " << "\n";
		ia.posePoint();
		mort.printCarte();
		if (mort.verifieWin(ia.getSigne()))
		{
			std::cout << "IA game";
			break;
		}
		if (i == 9)
		{
			std::cout << "draw";
		}
		i++;
	}
}
