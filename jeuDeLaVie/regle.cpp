#include <vector>
#include "structCellule.h"

using namespace std;

/*
 * Regle basique d'un automate
 * vie si 3 voisins
 * mort si plus de 3 voisins ou si moins de deux voisins
 */
void regleBasique (vector<vector<cellule>> & mat){
    // On parcours tous les cases de la matrice afin de leur définir un état selon leur nombre de voisin
    for (unsigned li = 0 ; li<mat.size() ; ++li){
        for (unsigned col = 0 ; col<mat.size() ; ++col){
            if (mat[li][col].nbVoisin==3 && mat[li][col].etat==false)
                mat[li][col].etat=true;
            else if (mat[li][col].etat==true && (mat[li][col].nbVoisin>3 || mat[li][col].nbVoisin<2))
                mat[li][col].etat=false;
        }
    }
}

/*
 * Regle de conway d'un automate
 * vie si 3 voisins
 * mort si plus de 5 voisins
 */
void regleConway (vector<vector<cellule>> & mat){
    // On parcours tous les cases de la matrice afin de leur définir un état selon leur nombre de voisin
    for (unsigned li = 0 ; li<mat.size() ; ++li){
        for (unsigned col = 0 ; col<mat.size() ; ++col){
            if (mat[li][col].nbVoisin==3 && mat[li][col].etat==false)
                mat[li][col].etat=true;
            else if (mat[li][col].etat==true && (mat[li][col].nbVoisin>5))
                mat[li][col].etat=false;
        }
    }
}

/*
 * Regle de l'expension lente d'un automate
 * vie si 3 ou 5 ou 6 ou 7 voisins
 * mort si 1 ou plus de 6 voisins
 */
void regleExpensionLente (vector<vector<cellule>> & mat){
    // On parcours tous les cases de la matrice afin de leur définir un état selon leur nombre de voisin
    for (unsigned li = 0 ; li<mat.size() ; ++li){
        for (unsigned col = 0 ; col<mat.size() ; ++col){
            if ((mat[li][col].nbVoisin==3 || mat[li][col].nbVoisin==5 || mat[li][col].nbVoisin==6 || mat[li][col].nbVoisin==7) && mat[li][col].etat==false)
                mat[li][col].etat=true;
            else if (mat[li][col].etat==true && (mat[li][col].nbVoisin==1 || mat[li][col].nbVoisin>=5))
                mat[li][col].etat=false;
        }
    }
}
