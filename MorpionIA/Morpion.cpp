#include "Morpion.h"

void Morpion::generateCarte()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			carte[i][j] = '_';
		}
	}
}

void Morpion::printCarte()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << "|";
			std::cout << carte[i][j];
		}
		std::cout << "|";
		std::cout << "\n";
	}
}

bool Morpion::verifieWin(char _signe)
{
	for (int i = 0; i < 3; i++)
	{
			if (carte[i][0] == _signe && carte[i][1] == _signe && carte[i][2] == _signe)
			{
				return true;
			}
	}
	for (int j = 0; j < 3; j++)
	{
		if (carte[0][j] == _signe && carte[1][j] == _signe && carte[2][j] == _signe)
		{
			return true;
		}
	}
	if (carte[0][0] == _signe && carte[1][1] == _signe && carte[2][2] == _signe || 
		carte[0][2] == _signe && carte[1][1] == _signe && carte[2][0] == _signe)
	{
		return true;
	}
	return false;
}

bool Morpion::posePoint(int _x, int _y, char _signe)
{
	if (carte[_x][_y] == '_')
	{
		carte[_x][_y] = _signe;
		return true;
	}
	return false;
}

void Morpion::IAposePoint(int _x, int _y, char _signe)
{
		carte[_x][_y] = _signe;
}
