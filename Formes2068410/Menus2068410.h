// But :	Delcarer les fonctions du menu.
// Auteur :	 Mikael Lagasse
// Date :  17 Novembre 2020

#pragma once

// Fonctions qui serviront au menus : 

int validerMenu(int typeMenu,int max,bool update);			//Boucle au debut qui verifie dans quel menu on veut entrer.

void afficherMenu1();		//Fonction qui affiche le menu 1
void afficherMenu2();		//Fonction qui affiche le menu 2
void afficherMenu3();		//Fonction qui affiche les options

void ModifContour();		// Fonction pour modifier nos contours
void ModifRemp();			// Fonction pour modifier l'interieur de notre forme.

void choixCouleur(int type);		// Fonction pour selectionner la couleur desirer par l'utilisateur.
void choixMotif(int type);			// Fonction pour selectionner le motif desirer par l'utilisateur.