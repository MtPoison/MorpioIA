#pragma once
#include <iostream>
#include "string"
class Morpion
{
private: 
	char carte[3][3];
public: 
	void generateCarte();
	bool verifieWin(char _signe);
	bool posePoint(int _x, int _y, char _signe);
	void IAposePoint(int _x, int _y, char _signe);
	void printCarte();
	char getElement(int _i, int _j) const {return this->carte[_i][_j];}
};

