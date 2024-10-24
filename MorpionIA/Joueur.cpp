#include "Joueur.h"

void Joueur::posePoint()
{
	int ligne;
	int colone;

	std::cin >> ligne;
	std::cin >> colone;

	good = mort.posePoint(ligne, colone, signe);
}
