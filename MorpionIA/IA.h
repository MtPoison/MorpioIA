#pragma once
#include <vector>
#include "Morpion.h"
#include "Joueur.h"
class IA
{
private:
	char signe;
	char jSigne;
	Morpion& mort;
	bool good;
public:
	IA(char _signe, Morpion& _mort, char _jSigne) : signe(_signe), mort(_mort), jSigne(_jSigne){}
	int verrifieWin();
	std::vector<std::pair<int, int>> trouverCoupsValides();
	bool ResteCoups();
	std::pair<int, int> bloquerJoueur();
	int MinMax(int profondeur, char joueurActuel);
	std::pair<int, int> meilleurCoupIA();
	void posePoint();
	char getSigne() { return signe; }
	bool isGood() { return good; }
};

