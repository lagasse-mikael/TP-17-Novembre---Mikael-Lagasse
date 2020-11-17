// But : Declarer les fonctions pour les menus.
// Auteur :	 Mikael Lagasse
// Date :  17 Novembre 2020

#include "Menus2068410.h"       // POur faire references au menus.
#include<iostream>
#include <stdlib.h>

#include <string>       // Pour pouvoir utiliser les strings.

using namespace std;        // std:: , c'est non.

// Extern :
// Pouvoir utiliser nos variables delcarer dans d'autre cpp dans un cpp different.

extern const string UPDATE;     //Couleur pour le text : Update : Si on a fait un changement quelque part.
extern const string ERREUR;     // Si quelque chose ne fonctionne pas
extern const string DEFAUT;     // B l a n c .

extern const string ROUGE;      //Couleurs pour les choix de couleurs : 
extern const string VERT;
extern const string JAUNE;
extern const string BLEU;
extern const string ROSE;
extern const string CYAN;
extern const string BLANC;      // Bref, beaucoup de couleurs!!

extern char contour;        // Notre motif pour le contour
extern char interieur;      // Notre motif pour l'interieur.

extern string choixCouleurC;        // Notre choix de couleur pour le contour
extern string choixCouleurI;        // Notre choix de couleur pour l'interieur

int validerMenu(int typeMenu, int max, bool update)     // Ici on valide si nos choix dans les menus sont bon et on en fait afficher d'autre au besoin
{
        
    system("cls");      // Enlevons tout de l'ecran

    if (update)     // Si il y a eu un changement
    {
    cout << UPDATE << "* Changement sauvegarder *" << DEFAUT << endl;       // Changement sauvegarder en vert.
    cout << endl;       // Et on skip une ligne
    }

    int choix;       // Intialise la fonction qui gardera notre choix.

    switch (typeMenu)       // Switch statement afin de savoir quel type de menu on veut : 
    {
    case 1:     // Menu principal
        afficherMenu1();
        break;
    case 2:     // Menu du remplissage
        afficherMenu2();
        break;
    case 3:     // Menu des options
        afficherMenu3();
        break;
    case 4:     // Menu pour la modification du contour
        ModifContour();
        break;
    case 5:     // Menu pour la modification du remplissage
        ModifRemp();
        break;
    default:        // Default! il doit etre la par defaut..
        break;
    }
    
    cin >> choix;       // On prend en compte notre choix.

    while (!(choix > 0 && choix <= max))        // Si notre reponse n'est pas valide :
    {
        cin.clear();        // On clear la memoire du clavier pour eviter tout loop infini.
        cin.ignore();
        cout << ERREUR << "Veuillez reesayer a nouveau! "<< endl << DEFAUT << "Votre Choix -->";        // PEtit message pour reessayer.
        cin >> choix;           // Et on redemande la question.
    }
    return choix;       // Et on retourne notre choix sous forme d'integer.
}

void afficherMenu1()
{
    cout << "1.Rectangle" << "              " << choixCouleurC << "Contour : " << DEFAUT << contour << choixCouleurI << "  Interieur : " << DEFAUT << interieur << "\n2.Triangle"<< "               Concu par : " << BLEU <<"Mikael Lagasse" << BLANC <<"\n3.Carré\n4.Losange\n5.Options\n\n6.Quitter\nVotre Choix -->";
    // Menu principal qui nous montre notre motif de contour / remplissage selectionner , ainsi que la couleur qui lui est attribuer
}

void afficherMenu2()
{
    cout << "1.Forme pleine\n2.Forme vide\n3.Retour au menu précédent\n\nVotre Choix -->";
    // Menu pour savoir le remplissage.
}

void afficherMenu3()
{
    cout << "1.Modifier les contours\n2.Modifier le remplissage\n3.Retour au menu précédent\n\nVotre Choix -->";
    // Menu d'options pour les graphique.
}

void ModifContour()         // Ici on prend en charge le choix de ce qu'on veut faire avec notre contour
{

    int input;      // Variable ou on mettera nos choix

    system("cls");      // On nettoie l'ecran

    cout << "Modifier le motif ou la couleur du contour?\n1.Couleur\n2.Motif\n\nVotre choix -->";       // Petit message a savoir ce qu'on veut faire.

    cin >> input;       // On stock notre reponse dans input

    switch (input)      // Switch statement a savoir quel menu on affichera.
    {
    case 1:     // Si c'est 1 , c'est pour les couleurs.
        choixCouleur(2);        // Et vu qu'on parle de motif , on amene 2 comme parametre , 2 c'est pour les contours.
        break;
    case 2:     // Si c'est 2 , c'est pour le motif.
        choixMotif(2);      // On parle encore de contour , donc 2.
        break;
    default:        // Encore default , :/ 
        break;
    }
}

void ModifRemp()        // Ici on prend en charge le choix de ce qu'on veut faire avec notre remplissage
{

    int input;      // Meme chose , variable ou on mettera nos choix

    system("cls");      // On nettoie encore l'ecran
    
    cout << "Modifier le motif ou la couleur de l'interieur?\n1.Couleur\n2.Motif\n\nVotre choix -->";       // Message de menu.
    
    cin >> input;           // On stock la reponse dans input.
    
    switch (input)      // Switch statement a savoir quel menu on affichera.
    {
    case 1:         // Comme ModifContour , 1 c'est pour les couleurs
        choixCouleur(1);        // Et maintenant on parle de remplissage , donc on amene 1 comme parametre.
        break;
    case 2:         // Meme chose que ModifContour , 2 c'est pour les motifs.
        choixMotif(1);          // Maintenant on amene 1 pour dire a choixMotif() qu'on parle de Remplissage.
        break;
    default:            // Bien le bonjour default.
        break;
    }
}
void choixCouleur(int type)         // Ici on prend en compte la couleur a attribuer.
{ 
    system("cls");          // On enleve tout de l'ecran.
    
    int choix;          // Variable pour notre choix.

    cout << "1 : " << ROUGE << "Rouge" << BLANC << endl;            // Ici on output toute les couleurs disponibles.
    cout << "2 : " << VERT << "Vert" << BLANC << endl;
    cout << "3 : " << JAUNE << "Jaune" << BLANC << endl;
    cout << "4 : " << BLEU << "Bleu" << BLANC << endl;
    cout << "5 : " << ROSE << "Rose" << BLANC << endl;
    cout << "6 : " << CYAN << "Cyan" << BLANC << endl;
    cout << "7 : " << BLANC << "Blanc" << BLANC << endl;
    
    cout << endl <<"Veuillez entrer une couleur qui sera utiliser pour " << ((type == 1) ? "l'interieur" : "le contour") << " des formes : " << endl;
    // cout pour indiquer a l'utilisateur pour quoi il assigenra une nouvelle couleur , soit l'interieur ou le contour en vrai.
    if (type == 1)          // Si notre parametre etait de 1 ( Remplissage ) : 
    {
        cin >> choix;       // On prend son choix.
        switch (choix)      // On le compare a la liste qu'il a chosi , 
        {
        case 1:
            choixCouleurI = ROUGE;      // Et on l'attribut a choixCouleur , qui lui sera utiliser pas mal afin de donner la couleur au motif.
            break;
        case 2:
            choixCouleurI = VERT;
            break;
        case 3:
            choixCouleurI = JAUNE;
            break;
        case 4:
            choixCouleurI = BLEU;
            break;
        case 5:
            choixCouleurI = ROSE;
            break;
        case 6:
            choixCouleurI = CYAN;
            break;
        case 7:
            choixCouleurI = BLANC;      // Bref , on fait la meme chose partout dependament la couleur qu'il a choisi.
            break;
        default:
            break;
        }
    }
    else              // Et si finalment notre parametre etait de 2 ( Contour ) : 
    {
    cin >> choix;       // On prend son choix.
    switch (choix)      // Meme chose , on compare son choix selon la liste qui a ete afficher , 
    {
        case 1:
            choixCouleurC = ROUGE;      // Et on l'attribut a sa variable qui sera utiliser pour lui donner ca couleur.
            break;
        case 2:
            choixCouleurC = VERT;
            break;
        case 3:
            choixCouleurC = JAUNE;
            break;
        case 4:
            choixCouleurC = BLEU;
            break;
        case 5:
            choixCouleurC = ROSE;
            break;
        case 6:
            choixCouleurC = CYAN;
            break;
        case 7:
            choixCouleurC = BLANC;      // Encore la meme chose pour tout le Switch statement.
            break;
        default:
            break;
        }
    }
}

void choixMotif(int type)       // Ici on choisi le motif selon "type" ( Qu'est ce qu'on veut modifier ) 
{
    system("cls");      // On enleve tout de l'ecran
    
    int choix;      // Declare notre variable pour notre choix.

    cout << "Veuillez entrer un charactere qui sera utiliser pour " << ((type == 1)?"l'interieur":"le contour")<< " des formes : " << endl;
    // On indique sur quoi l'utilisateur fera le changement.
   if (type == 1)       // Si c'est pour les motifs interieur L 
        cin >> interieur;       // le nouveau motif y sera assigner.
   else                // Et si c'est pour les motifs de contour
        cin >> contour;         // meme chose, sauf que cette fois-ci , ce sera pour le contour.
}
//Sources :
// https://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html
