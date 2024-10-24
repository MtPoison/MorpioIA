#include "IA.h"


int IA::verrifieWin()
{
	if (mort.verifieWin(signe)) {
		return 10;
	}
	if (mort.verifieWin(jSigne)) {
		return -10;
	}
	return 0;
}

std::vector<std::pair<int, int>> IA::trouverCoupsValides() {
	std::vector<std::pair<int, int>> coups;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (mort.getElement(i, j) == '_')
			{
				coups.emplace_back(i, j);
			}
		}
	}
	return coups;
}


bool IA::ResteCoups()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (mort.getElement(i, j) == '=') return true;
		}
	}
	return false;
}

#include "IA.h"

int IA::MinMax(int profondeur, char joueurActuel) {
	int score = verrifieWin();
	if (score == 10) {
		return score - profondeur;
	}
	if (score == -10) {
		return score + profondeur;
	}
	if (!ResteCoups()) {
		return 0;
	}

	if (joueurActuel == signe) {
		int meilleurScore = std::numeric_limits<int>::min();
		std::vector<std::pair<int, int>> coupsValides = trouverCoupsValides();

		for (const auto& coup : coupsValides) {
			mort.IAposePoint(coup.first, coup.second, signe);

			int scoreActuel = MinMax(profondeur + 1, jSigne);
			mort.IAposePoint(coup.first, coup.second, '_');

			meilleurScore = std::max(meilleurScore, scoreActuel);
		}
		return meilleurScore;

	}
	else {
		int meilleurScore = std::numeric_limits<int>::max();
		std::vector<std::pair<int, int>> coupsValides = trouverCoupsValides();

		for (const auto& coup : coupsValides) {
			mort.IAposePoint(coup.first, coup.second, jSigne);

			if (mort.verifieWin(jSigne)) {
				meilleurScore = std::min(meilleurScore, -10);
			}
			else {
				int scoreActuel = MinMax(profondeur + 1, signe);
				meilleurScore = std::min(meilleurScore, scoreActuel);
			}

			mort.IAposePoint(coup.first, coup.second, '_');
		}
		return meilleurScore;
	}
}


std::pair<int, int> IA::bloquerJoueur() {
	std::vector<std::pair<int, int>> coupsValides = trouverCoupsValides();

	for (const auto& coup : coupsValides) {
		
		mort.IAposePoint(coup.first, coup.second, jSigne);

		
		if (mort.verifieWin(jSigne)) {
			mort.IAposePoint(coup.first, coup.second, '_');
			return coup;
		}
		mort.IAposePoint(coup.first, coup.second, '_');
	}
	return { -1, -1 };
}



std::pair<int, int> IA::meilleurCoupIA() {
	int meilleurScore = std::numeric_limits<int>::min();
	std::pair<int, int> meilleurCoup = { -1, -1 };

	std::vector<std::pair<int, int>> coupsValides = trouverCoupsValides();

	for (const auto& coup : coupsValides) {
		mort.IAposePoint(coup.first, coup.second, signe);
		int score = MinMax(0, jSigne);
		mort.IAposePoint(coup.first, coup.second, '_');

		if (score > meilleurScore) {
			meilleurScore = score;
			meilleurCoup = coup; 
		}
	}

	std::cout << "Meilleur coup choisi par l'IA : (" << meilleurCoup.first << ", " << meilleurCoup.second << ")" << std::endl;
	return meilleurCoup;
}

void IA::posePoint() {
	auto coupDeBlocage = bloquerJoueur();
	if (coupDeBlocage.first != -1) {
		mort.IAposePoint(coupDeBlocage.first, coupDeBlocage.second, signe);
		return; 
	}

	std::pair<int, int> meilleurCoup = meilleurCoupIA();
	mort.IAposePoint(meilleurCoup.first, meilleurCoup.second, signe);
}