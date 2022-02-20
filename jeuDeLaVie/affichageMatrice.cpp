#include <vector>
#include <iostream>
#include "structCellule.h"

using namespace std;

/*
 * Cette fonction permet d'afficher le contenu d'un tableau de booleen en ligne
 * - si le booleen est vrai, ca affiche un X
 * - si le booleen est faux, ca affiche un espace
 */
void afficherTableau(vector<cellule> & tableau){
    cout << '|';
    //Dans cette boucle on parcours le tableau afin de déterminer l'etat du booleen et d'afficher le caractere en consequence
    for (unsigned i=0;i<tableau.size();++i){
        if (tableau[i].etat)
            cout<<"X ";
        else
            cout<<"  ";
    }
    cout << '|' << endl;
}

//Affichage de la matrice
void afficherMatrice(vector<vector<cellule>> & matrice){
    //Permet de clear le terminale
    cout << "\x1B[2J\x1B[H" << ' ';
    //délimitation haute de l'affichage de la matrice
    for (unsigned i = 0 ; i<matrice.size()*2;++i)
        cout << '-';
    cout << endl;
    //Affichage, une par une, des lignes de la matrice
    for (unsigned i=0;i<matrice.size();++i)
        afficherTableau(matrice[i]);
    cout << ' ';
    //Delimitation basse de l'affichage de la matrice
    for (unsigned i = 0 ; i<matrice.size()*2;++i)
        cout << '-';
}
