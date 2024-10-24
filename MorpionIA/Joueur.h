#pragma once
#include "Morpion.h"
#include <iostream>
class Joueur
{
private:
	char signe;
	Morpion& mort;
	bool good;
public:
	Joueur(char _signe, Morpion& _mort) : signe(_signe), mort(_mort) {}
	void posePoint();
	bool isGood() { return good; }
	char getSigne() { return signe; }
};

