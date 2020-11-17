// But : Instructions des fonctions des formes.
// Auteur :	 Mikael Lagasse
// Date :  17 Novembre 2020
#include "Formes2068410.h"      // Pour pouvoir utiliser nos references a nos fonctions.
#include<iostream>
#include<string.h>      // Pour les strings.
#include <stdlib.h>

using namespace std;            // Impossible que j'ecrive "std::" au 2 secondes.. Donc on va utiliser ceci pour ne pas avoir a faire cela!

// Extern :
// Pouvoir utiliser nos variables delcarer dans d'autre cpp dans un cpp different.

extern const string ERREUR;     // Notre couleur pour les : Erreurs
extern const string DEFAUT;     // Couleur par defaut , on doit souvent la remettre par defaut sinon la couleur se "propage"

extern string choixCouleurC;    // Notre choix de couleur pour le contour
extern string choixCouleurI;    // Notre choix de couleur pour l'interieur

extern char contour;            // Le motif du contour choisi plus tot.
extern char interieur;          // Le motif de l'interieur choisi plus tot aussi

void traiterTriangle(int remp)      // Ou on recevera nos informations pour le triangles tout en tenant compte de notre choix de remplissage.
{
    int hauteur;        // Declarons nos variable tout le monde! Ici c'est la hauteur.

    int triRandom = genererNombreAleatoire(1, 4);       // Notre chiffre aleatoire ira dans triRandom et sera utiliser dans notre switch()

    cout << "Entrez la hauteur du triangle : ";     // Message super gentil
    cin >> hauteur;     // On stock notre reponse dans hauteur


    switch (triRandom)      // Un switch statement selon notre chiffre aleatoire.
    {
    case 1:         // Si notre chiffre aleatoire est de 1 :
        dessinerTriangle1(hauteur, remp);        // Triangle #1
        break;
    case 2:
        dessinerTriangle2(hauteur, remp);       // Et ainsi de suite jusqu'a 4...
        break;
    case 3:
        dessinerTriangle3(hauteur, remp);
        break;
    case 4:
        dessinerTriangle4(hauteur, remp);       // 4 !
        break;
    default:        // Default qui ne peut s'empecher d'etre present a la fete 
        break;
    }
}

int genererNombreAleatoire(int min, int max)        // Utiliser pour les triangles. Chiffre entre 1 et 4
{
    return rand() % max + min;      // Nombre aleatoire entre notre maximum et notre minimum declarer plus haut.
}

void traiterCarre(int remp)         // Meme chose que TraiterRectangle , on va simplement prendre la mesure d'un coter et la mettre dans le parametre X et Y de la fonction dessinerRectangle();
{
    int c;      // On declare notre variable qui stockera combien notre coter mesurera. ( Est ce que ca ce dit mesurera?? Ecoutez , je suis tres fatiguer  , j'essais :/ ) 

    cout << "Entrez la hauteur/largeur du carre: ";         // On indique qu'on veut la mesure pour notre carre.

    cin >> c;       // On la stock dans notre variable declarer plus haut.
    while (!(c > 0))        // Et si on recoit une reponse non valide :
    {
        cin.clear();        // On clear tout ce qu'on a dans la memoire du clavier.
        cin.ignore();
        cout << "Veuillez entrer une mesure plus grande que" << ERREUR << " 0 "<< DEFAUT << ": " << endl;       // Petit message d'erreur
        cin >> c;       // Et on redemande jusqua ce qu'on aille la bonne mesure
    }
    dessinerRectangle(c, c, remp);      // Apres tout ca , on l'attribut au X et au Y de notre fonction dessinerRectangle();
}

void traiterLosange(int remp)       // Ici on va receuillir nos informations pour pouvoir dessiner notre Losange.
{
    int hauteur;        // On a juste de besoin de la hauteur.

    cout << "Entrez la hauteur impaire du losange : ";          // Message bin gentil
    cin >> hauteur;         // Integer stocker dans hauteur.

    while (hauteur % 2 == 0)        // Si notre reponse est pair , C'EST PAS CA QUI FAUT ::
    {
        system("cls");      // ON NETTOIE L'ECRAN C'EST LA PANIQUE TOUT LE MONDE
        cout << "Entrez la hauteur" << ERREUR <<  "IMPAIRE " << DEFAUT << "du losange : ";          // VITE UN CHIFFRE IMPAIR !!!!!
        cin >> hauteur;         // Et ici on espere recevoir un chiffre impair. Si on en recoit pas , on recommence la boucle jusqua ce qu'on en aille un.
    }

    dessinerLosange(hauteur, remp);         // Quand tout est beau et que notre hauteur est valide , on passe les parametres (hauteur et remplissage) a la fonction qui le dessinera.

}

void traiterRectangle(int remp)         // Et ici on va receuillir nos informations pour pouvoir ensuite dessiner notre Rectangle.
{
    int x, y;           // Nous declarons x et y , car on en aura de besoin pour dessinerRectangle(); 
    
    cout << "Entrez la hauteur du rectangle: ";     // Petit message assez claire
    cin >> y;           // On stock notre information dans Y
    cout << "Entrez la largeur du rectangle: ";     // On veut la largeur maintenant!
    cin >> x;           // On stock notre information dans Y

    dessinerRectangle(x, y, remp);
}

void dessinerRectangle(int x, int y, int remp)          // Fonctions pour dessiner notre rectangle qui prend en compte l'axe X ,Y et si on voulait le remplir ou non.
{
    system("cls");      // On nettoie l'ecran.

    cout << "Voici votre rectangle " << (remp == 1 ? "plein" : "vide") << " de " << x << "x" << y << " : " << endl;     // On indique que c'est un rectangle ,plein ou vide , ainsi que ses mesures.

    for (int i = 0; i < y; i++)     // Ici on va s'occuper de l'axe Y de notre rectangle.
    {

        cout << choixCouleurC << contour;       // Debut de notre contour :
        for (int j = 0; j < (x-2); j++)     // Ici , on parle de l'interieur de notre rectangle :
        {
            if (i == 0 || i == (y - 1))         // Donc si on est au debut ou la a la fin de notre rectangle , c'est qu'on ne peut pas le remplir
                cout << choixCouleurC << contour;           // On va donc simplement output le contour et sa couleur.
            else             // Sinon : On va regarder voir si on voulait l'avoir remplis ou non
                if (remp == 1)          // Si oui :
                    cout << choixCouleurI << interieur;         // On le remplis du motif et de la couleur choisi
                else           // Sinon :
                    cout << " ";        // Une simple espace
        }
        cout << choixCouleurC << contour << endl;        // Et on output l'extremiter de notre rectangle.
    }
    cout << DEFAUT;                     // Retour a la couleur de base.
    system("pause");                    // On prend le temps de regarder la forme
}

void dessinerTriangle1(int h, int remp)         // Premier Triangle ! Ca va etre long a expliquer les 4 triangles , donc attachez votre tuque.
{
    system("cls");          // On nettoie l'ecran

    cout << "Voici votre triangle #1 " << (remp == 1 ? "plein" : "vide") << " de hauteur " << h << endl;        // On indique que c'est un triangle ,plein ou vide , ainsi que sa hauteur.


    cout << choixCouleurC << contour << endl;       // Sommet de notre triangle.

    for (int i = 0; i < h - 1; i++)     // For() qui prend en charge l'axe des Y
    {
        cout << choixCouleurC << contour;       // Debut du contour de notre triangle.
        for (int j = 0; j < i; j++)         // For() qui prend en charge l'axe des X
        {
            if (i != h - 2)     // Si on est pas a la derniere couche de notre triangle ( qu'on peut le remplir a cette couche ) :
                if (remp == 1)      // Si on voulait le remplir :
                    cout << choixCouleurI << interieur;     // Nous allons le remplir avec notre motif choisi et nous prenons en consideration sa couleur.
                else              // Si on voulait pas le remplir :
                    cout << " ";        // Une simple espace fera l'affaire.
            else          // Et si on est vraiment a la derniere couche : 
                cout << choixCouleurC << contour;       // On va output le contour tout simplement , afin de cree une ligne bien droite.
        }
        cout << choixCouleurC << contour << endl;       // On prend en compte l'autre extremiter du contour et on l'affiche.
    }
    cout << DEFAUT;                     // Retour a la couleur de base.
    system("pause");                    // On prend le temps de regarder la forme
}

void dessinerTriangle2(int h, int remp)         // Triangle numero 2 , tout les triangles prennent les memes parametres , je vais donc me repeter un peu beaucoup :)))))))
{
    system("cls");          // On nettoie l'ecran , parce que c'est ca qui est ca.

    cout << "Voici votre triangle #2 " << (remp == 1 ? "plein" : "vide") << " de hauteur " << h << endl;           // On indique que c'est un triangle ,plein ou vide , ainsi que sa hauteur.

    for (int i = h; i > 0; i--)     // For() qui prend en charge l'axe Y du triangle
    {
        cout << choixCouleurC << contour;       // Debut du contour.
        for (int j = i - 2; j > 0; j--)         // Axe des X du triangle.
        {
            if (i != h )        // Si on peut remplir l'interieur du triangle : 
                if (remp == 1)          // Si on voulait le remplir : 
                    cout << choixCouleurI << interieur;     // On le remplis selon le motif et la couleur.
                else          // Et si on voulait pas le remplir : 
                    cout << " ";        // On met simpolement un espace
            else
                cout << choixCouleurC << contour;
        }
        if (!(i == 1))      // Si on est pas au sommet  : 
            cout << choixCouleurC << contour << endl;       // On prend en compte l'autre extremiter du contour et on l'affiche.
        else
            cout << endl;       // Sinon on met rien , cela evite le sommet de ressembler a ceci --> "   **    "
    }
    cout << DEFAUT;                     // Retour a la couleur de base.
    system("pause");                    // On prend le temps de regarder la forme
}

void dessinerTriangle3(int h, int remp)     // Triangle numero 3 , hauteur/largeur et remplissage important.
{
    int x = 0;      // On initialise notre X a 0.
    
    system("cls");      // Nettoie l'ecran.

    cout << "Voici votre triangle #3 " << (remp == 1 ? "plein" : "vide") << " de hauteur " << h << endl;            // On indique que c'est un triangle ,plein ou vide , ainsi que sa hauteur.

    for (int i = h; i > 0; i--)         // For() pour la vertical du triangle.
    {
        cout << string(x, ' ');         // Initialiser a 0 de base , donc pour la premiere iteration , il y aura aucun espace , mais ce sera utiliser a partir de la deuxieme iteration.
        cout << choixCouleurC << contour;       // Debut du contour.
        for (int j = i - 2; j > 0; j--)     // Bouble for qui prend en compte l'axe des X et le fait que nous avons deja dessiner deux motifs du contour (debut / fin)
        {
            if (i != h)     // Si nous sommes pas rendu a la fin de l'affichage de notre triangle :
                if (remp == 1)      // Et si on voulait un remplissage :
                    cout << choixCouleurI << interieur;     // On output le motif de l'interieur avec la couleur choisi.
                else
                    cout << " ";            // Si on voulait l'avoir vide , on met rien.
            else
                cout << "*";        // Et si on est a la fin , on output simplement le sommet.
        }
        if (!(i == 1))      // Si on est pas a la premiere iteration :
            cout << choixCouleurC << contour << endl;       // On output le contour normalment
        else
            cout << endl;       // Sinon on met rien , cela evite le sommet de ressembler a ceci --> "   **    "
        x++;             // On augmente X pour afficher un espace de plus prochaine iteration.
    }
    cout << DEFAUT;                     // Retour a la couleur de base.
    system("pause");                    // On prend le temps de regarder la forme
}

void dessinerTriangle4(int h, int remp)         // Triangle Numero 4 , imporant de prendre en charge la hauteur/largeur et si on veut le remplir ou non.
{
    system("cls");          // On enleve tout sur l'ecran.

    cout << "Voici votre triangle #4 " << (remp == 1 ? "plein" : "vide") << " de hauteur " << h << endl;            // On indique que c'est un triangle ,plein ou vide , ainsi que sa hauteur.

    int x = h - 1;          // Vu qu'on commence pas directement coller a gauche , nous devont commencer de la droite selon notre largeur et soustraire de 1 , car le sommet prend une case.

    cout << string(x, ' ');         // C'est ici qu'on prend en charge les premiers espaces. ( hors loop )
    x--;            // Apres avoir effectuer les premiers espaces , on soustrait pour dire que nous avont fini avec une couche de l'axe des X
    cout << choixCouleurC << contour << endl;           // Sommet du triangle.

    for (int i = 0; i < h - 1; i++)           // For() loop pour l'axe des Y.
    {
        cout << string(x, ' ');             // Nombre d'espaces a effectuer afin de bien centrer notre triangle avec le reste du triangle.
        cout << choixCouleurC << contour;               // Debut du contour.
        for (int j = 0; j < i; j++)             // Ici on a un for() loop qui prend en charge l'axe des X
        {
            if (i != h - 2)                 // Si on n'est pas entrain d' "output" les contour :
                if (remp == 1)          // Si on voulait remplir l'interieur :
                    cout << choixCouleurI << interieur;     // On output le motif de l'interieur et on prend en charge sa couleur.
                else            // Et si on voulait pas le remplir
                    cout << " ";            // Simplement des espaces.
            else          // Et ici , c'est si on est pas a l'interieur.
                cout << choixCouleurC << contour;           // On output donc le contour.
        }
        cout << choixCouleurC << contour << endl;                   // L'autre extremiter du contour qui prend en charge la couleur.
        x--;                    // On reduit X pour afficher un espace de moin prochaine iteration.
    }
    cout << DEFAUT;                     // Retour a la couleur de base.
    system("pause");                    // On prend le temps de regarder la forme
}

void dessinerLosange(int hauteur,int remp)          // Calculs relativement complexe (plusieurs offsets) afin d'arriver au resultat.
{
    system("cls");          // On rend l'ecran propre.

    cout << "Voici votre losange " << (remp == 1 ? "plein" : "vide") << " de hauteur " << hauteur << endl;      // On indique que c'est un losange ,plein ou vide , ainsi que sa hauteur.

    int x = 0;              // Initialisation de notre compteur.
    
    int hauteur2 = hauteur / 2;         // la hauteur de l'autre moitier qui est enfait la vrai hauteur / 2 , on en fait une copie.
    hauteur -= hauteur2;                // On prend la vrai hauteur et on enleve la copie de la moitier de cette variable , pour eviter d'avoir 1.5x notre losange.

    for (hauteur; hauteur > 0; hauteur--)         
    {
        cout << string(hauteur - 1, ' ');       // On commence par faire les espaces afin de commencer au millieux du Losange , on va faire - 1
                                                // Car le sommet prend bien evidemment une case. Sans l'espace , ce serait decaler vers la droite et ne serait pas
                                                // Alligner avec la partie du bas du losange.
        cout << choixCouleurC << contour;                        // On affiche le sommet du losange / la partie gauche du contour.
        if (x > 0)                              // Ici , si notre X est plus grand que zero , cela signifie qu'il y a de la place a l'interieur de notre losange.
        {                                       // Donc on va le remplir dependament de remp
            if (remp == 1)                      // Si on voulait le remplir (remp == 1) :
            {
                cout << choixCouleurI << string(x - 1, interieur);           // Comme au debut , le -1 evite de decaler le tout d'une case vers la droite et on applique la couleur.
                cout << choixCouleurI << string(x, interieur);               // Ici , c'est l'autre moitier du losange.
            }

            /*
            
            On pourrait voir chaque 1/4 du losange comme un triangle , comme les triangles 1,2,3,4 que l'on retrouve plus haut dans ce .cpp
            
            */

            else
            {
                cout << string(x - 1, ' ');         // Ici , c'est la meme chose qu'en haut , sauf qu'on l'execute seulement si on veut que l'interieur soit vide
                cout << string(x, ' ');             // Comme on peut voir , un espace , c'est relativement vide , non?
            }
            cout << choixCouleurC << contour;       // Avec ce dernier "cout" , on cree le contour ligne par ligne , exemple , au debut de l'iteration , on peut voir qu'il-y-a
                                                    // Un "cout << contour" aussi , c'est parce que on trace l'exterieur et qu'apres grace au for() qui suit , on s'occupe de l'interieur.
        }                                           // Il est bon de savoir que choixCouleurX est utiliser pour le choix de couleur.
        x++;                                        // A chaque fin d'iteration , on veut dire au programme qu'a la prochaine iteration , on passe a une prochaine ligne , donc qu'on devra
                                                    // "Output" plus de contenu par rapport a l'interieur. ( Tout ca depend surtout de la hauteur , car le X controle rien , le X n'est pas 
                                                    // utiliser dans aucune comparaison ou quoi que ce sois qui nous ferait sortir de la boucle.
        cout << endl;                               // Ici on skip une ligne pour pouvoir s'occuper de la prochaine "couche"
    }

    for (int j = 1; j <= hauteur2; j++)             // Ici c'est la deuxieme moitier de notre losange , comme on peut voir , il y a un "++".
    {                                               // Ce "j++" nous sera utile afin de savoir quand nous seront rendu a la fin de notre losange et 
                                                    // a savoir combien d'espaces nous auront a afficher.
        cout << string(j, ' ');                     // Ici , on commence deja a 1 , car on ne commence pas comme etant le moitier du losange , on est la mediane + 1 du losange.
                                                    // Le losange ne peut pas etre un chiffre impair est cela est une des raisons pourquoi.
        cout << choixCouleurC << contour;                            // On commence par le debut du contour , qui sera preceder par le contenu qu'on veut y mettre a l'interieur.
        if (x > 2)                                  // Le X a la meme valeur que dans le for() precedent. On s'entend que 2 n'est pas inclus dans cette comparaison est c'est sa qui faut.
                                                    // Car comme j'ai dis plus haut , on "deal" surtout avec des chiffres impair , on peut rien "remplir" a l'interieur de "**" par exemple.
                                                    // Donc quand X = 2 , c'est parce que nous somme rendu on sommet , il y a donc rien a faire et on skip le if statement.
        {
            if (remp == 1)                          // Si on voulait que la forme soit remplis : 
            {
                cout << choixCouleurI << string(x - 3, interieur);   // On la remplissait avec le motif et la couleur choisi , selon x et un offset qui le previent de decaler.
                cout << choixCouleurI << string(x - 2, interieur);   // Et meme chose ici , car ici c'est l'autre moitier (le 1/4 du losange)
            }
            else                                    // Et si on voulait pas de remplissage : 
            {
                cout << string(x - 3, ' ');         // Meme chose , sauf qu'on remplace l'interieur par un espace
                cout << string(x - 2, ' ');         // Et meme chose pour l'autre moitier.
            }
            cout << choixCouleurC << contour;                        // Et ici c'est la fin de la ligne , ou on affiche le contour de notre losange.
        }
        x--;                                        // On indique qu'on est "descendu" , dans le sens ou on retrecit le losange de plus en plus.
        cout << endl;                               // Et on fini notre "ligne" en skippant une ligne.
    }
    cout << DEFAUT;                                 // Retour a la couleur de base.
    system("pause");                                // Et bien evidemment on pause a la fin pour admirer le beau losange qui a pris un beau 4-5h a comprendre.
}



//Sources d'aide : 
//https://stackoverflow.com/questions/20667960/how-do-i-make-a-square-in-c
//http://courses.washington.edu/css342/zander/css332/datatypes.html
