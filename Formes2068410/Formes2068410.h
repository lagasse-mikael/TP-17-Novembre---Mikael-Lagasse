// But : Declarer les fonctions pour les formes.
// Auteur :	 Mikael Lagasse
// Date :  17 Novembre 2020

#pragma once

// Fonctions qui serviront au formes : 

/*
Ces fonctions, selon la forme, demandent les dimensions de la forme, 
affichent la phrase de présentation de la forme avec les bonnes dimensions 
et finalement appellent  la  fonction  dessinant  la  forme. 
*/

void traiterTriangle(int remp);		// Avoir les infos du : Triangle
void traiterCarre(int remp);		// Carre
void traiterLosange(int remp);		// Losange
void traiterRectangle(int remp);	// Rectangle

void dessinerRectangle(int x, int y,int remp); //Fonction qui dessine un rectangle ou un carré dont la hauteur, la largeur et le mode de remplissage sont passés en paramètre

// ^ comprend le Carre

void dessinerTriangle1(int h,int remp);	//Premier Triangle
void dessinerTriangle2(int h, int remp);	//Deuxieme Triangle
void dessinerTriangle3(int h, int remp);	//Troisieme Triangle
void dessinerTriangle4(int h, int remp);	//Quatrieme Triangle

// Bref , il sont tous different.

void dessinerLosange(int hauteur, int remp);	//Pour dessiner notre losange

int genererNombreAleatoire(int min,int max);	// Pour avoir un nombre aleatoire qui servira a nous donner un triangle aleatoire.