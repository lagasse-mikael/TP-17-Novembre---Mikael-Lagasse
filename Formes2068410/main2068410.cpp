// But :	   Programme qui dessine des formes aux dimensions diverses, pleines ou vides, selon les choix que l'utilisateur fait dans les menus	   
// Auteur :	   Mikael Lagasse
// Date de modification : 17 Novembre 2020
// Date de remise :      Pour le 17 Novembre 2020

//On peut rien enlever du main , mais on peut en ajouter SEULEMENT pour les defis.
//Idee pour plus de points : Couleurs , 




#include <iostream>		// Bibliothèque qui fournit des fonctions pour permettre la communication entre le programme et l'utilisateur
#include <time.h>		// Bibliothèque qui fournit des fonctions basées sur les dates et heures
#include "Menus2068410.h"		// Bibliothèque du programmeur rassemblant les fonctions permettant la gestion des menus et la validation des choix fait dans ces menus
#include "Formes2068410.h"		// Bibliothèque du programmeur offrant des fonctions permettant de dessiner différentes formes, pleines ou vides

using namespace std;
// Extern :
// Pouvoir utiliser nos variables delcarer dans d'autre cpp dans un cpp different.

// Graphique : publique

extern char interieur = '#';		// Nos variables externe (publique) qui tiennent les "graphiques" (motifs)
extern char contour = '*';

// Couleur en string :
// Sera plus facile pour nous de changer la couleur d'un seul character en "ajoutant" ce string a un autre string.
// Bref , en ajoutant ceci devant un autre string , on change sa couleur.

extern const string UPDATE = "\033[32;1m";		// Ici , c'est vert pour les changements
extern const string ERREUR = "\033[31;1m";		// Rouge pour les erreurs.
extern const string DEFAUT = "\033[0;1m";		// Et Blanc par defaut.

extern string choixCouleurC = DEFAUT;			// De base , notre choix de couleur pour le contour sera blanc.
extern string choixCouleurI = DEFAUT;			// Meme chose pour l'interieur.

// Autre couleurs : 

extern const string ROUGE = "\033[31m";			// Tres simple , c'est le string qui sert a changer la couleur lorsqu'on l'ajoute a un autre string.
extern const string VERT = "\033[32m";
extern const string JAUNE = "\033[33m";
extern const string BLEU = "\033[34m";
extern const string ROSE = "\033[35m";
extern const string CYAN = "\033[36m";
extern const string BLANC = "\033[37m";			// Bref , on declare toute nos couleurs pour plus tard.


int main()
{
   // Définition des constantes 
   int QUITTER = 6;     // Le choix maximum dans le menu 1. ***Pourrait changer si le programmeur ajoute une forme suppplémentaire*** <-- C'est pourquoi on enleve tout de suite const.
   int RETOUR = 3;     // Le choix maximum dans le menu 2. ***Pourrait changer si le programmeur ajoute une option suppplémentaire*** <-- C'est pourquoi on enleve tout de suite const.

   const int RECTANGLE = 1;     // Pour faciliter la lecture du code dans le switch
   const int TRIANGLE  = 2;
   const int CARRE     = 3;
   const int LOSANGE   = 4;
   const int OPTIONS   = 5;		// Options de Remplissage!

	// Définition des variables	
	int choixForme;		// Integer pour la forme qu'on a choisi
	int choixRemplissage;		// Integer pour le mode de remplissage
	int choixOptions;			// Integer pour l'options choisi dans le menu des options.


	//Autres
	srand(time(NULL));	            // Permet d'initialiser le random seed
	setlocale(LC_ALL,"");            // Permet de gérer les caractères accentués
	bool update = false;

   // Afficher le menu des formes et lire un choix valide 
	choixForme = validerMenu(1 /* choix du menu des formes */, QUITTER /* Nombres d'options au menu */, update);
	
   // Tant que l'utilisateur ne veut pas quitter

	/*if (choixForme == OPTIONS)
	{
		choixOptions = validerMenu(3, RETOUR);
	}*/

	//else
	//{
		while (choixForme != QUITTER)
		{
			// Afficher le menu du remplissage et lire un choix valide

			if (choixForme == OPTIONS)		// Si on va dans le menu des options : 
			{
				update = false;		// On indique qu'on a rien changer.
				choixOptions = validerMenu(3, RETOUR, update);		// On display le menu.
				switch (choixOptions)		// Switch statement a savoir ce qu'on a selectionner : 
				{
				case 1:		// Si c'est "1" , c'est pour modifier le contour.
					ModifContour();		// On appel donc la fonctions pour modifier le contour
					update = true;		// Et on indique qu'on fera un changement.
					break;
				case 2:		// Si c'est "2" , c'est pour modifier l'interieur.
					ModifRemp();		// On appel donc la fonctions pour modifier l'interieur.
					update = true;		// Et on indique le changement.
				default:
					break;
				}
			}
			else
			{
				update = false;		// Si on est ici , c'est qu'on a pas eu a faire des changements ou quoi que ce sois.
				choixRemplissage = validerMenu(2 /* Menu du remplissage */, RETOUR /* Nombres d'options au menu */,update);

				// Si l'utilisateur n'est pas revenu au menu principal
				if (choixRemplissage != RETOUR)
				{
					// Ici, l'utilisateur a fait le choix d'une forme et du remplissage, il nous reste à traiter et dessiner la forme
					switch (choixForme)
					{
					case RECTANGLE:
						// Traiter forme demande les dimensions de la forme, affiche la phrase de présentation de la forme et appelle la fonction
						// dessinant la forme
						traiterRectangle(choixRemplissage);
						break;
					case TRIANGLE:
						traiterTriangle(choixRemplissage);
						break;
					case CARRE:
						traiterCarre(choixRemplissage);
						break;
					case LOSANGE:
						traiterLosange(choixRemplissage);
						break;
					} // Fin du switch
				}// fin du if
			}
		   // On présente de nouveau le menu principal des choix des formes et on lit le choix de l'utilisateur
			choixForme = validerMenu(1 /* Menu des formes*/, QUITTER /* Nombres d'options au menu*/, update);

		} // Fin du while (choixForme != iQUITTER)
	//}
	return 0;

}


