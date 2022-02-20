#include <vector>
#include <random>
#include "structCellule.h"
using namespace std;

//Fonction permettant de remplir aléatoirement une matrice passée en paramètre selon un pourcentage lui aussi passé en paramètre
vector<vector<cellule>> remplirMatriceAlea(vector<vector<cellule>> & mat,const unsigned & pourcentage){
    for (unsigned li = 0 ; li<mat.size() ; ++li){
        for (unsigned col = 0 ; col<mat.size() ; ++col){
            unsigned alea = rand()%100;
            if (alea<pourcentage)
                mat[li][col].etat=true;
        }
    }
    return mat;
}

//Remplissage de la matrice afin que cela fasse une sorte de floraison
vector<vector<cellule>> remplirMatriceFloraison(vector<vector<cellule>> & mat){
    mat[10][10].etat=true;
    mat[9][10].etat=true;
    mat[11][10].etat=true;
    mat[9][9].etat=true;
    mat[9][11].etat=true;
    mat[11][9].etat=true;
    mat[11][11].etat=true;
    mat[10][8].etat=true;
    mat[10][12].etat=true;
    return mat;
}

//remplissage de la matrice afin de créer une sorte de canon envoyant des planeurs
vector<vector<cellule>> remplirMatriceCanon(vector<vector<cellule>> & mat){
    //stop gauche
    mat[20][0].etat=true;
    mat[21][0].etat=true;
    mat[20][1].etat=true;
    mat[21][1].etat=true;

    //canon gauche
    mat[20][10].etat=true;
    mat[21][10].etat=true;
    mat[22][10].etat=true;
    mat[19][11].etat=true;
    mat[23][11].etat=true;
    mat[18][12].etat=true;
    mat[24][12].etat=true;
    mat[18][13].etat=true;
    mat[24][13].etat=true;
    mat[21][14].etat=true;
    mat[19][15].etat=true;
    mat[23][15].etat=true;
    mat[20][16].etat=true;
    mat[21][16].etat=true;
    mat[22][16].etat=true;
    mat[21][17].etat=true;

    //canon droite
    mat[20][20].etat=true;
    mat[20][21].etat=true;
    mat[19][20].etat=true;
    mat[19][21].etat=true;
    mat[18][20].etat=true;
    mat[18][21].etat=true;
    mat[17][22].etat=true;
    mat[21][22].etat=true;
    mat[16][24].etat=true;
    mat[17][24].etat=true;
    mat[21][24].etat=true;
    mat[22][24].etat=true;

    //stop droite
    mat[18][34].etat=true;
    mat[18][35].etat=true;
    mat[19][34].etat=true;
    mat[19][35].etat=true;
    return mat;
}

//Remplissage de la matrice afin que cela fasse une sorte de floraison
vector<vector<cellule>> remplirMatriceFloraison2(vector<vector<cellule>> & mat){
    mat[41][40].etat=true;
    mat[40][40].etat=true;
    mat[39][40].etat=true;
    mat[40][41].etat=true;
    mat[40][39].etat=true;
    return mat;
}

//Remplissage de la matrice afin que cela créer une sorte de petit planeur qui bouge
vector<vector<cellule>> remplirMatricePlaneur(vector<vector<cellule>> & mat){
    mat[2][2].etat=true;
    mat[4][2].etat=true;
    mat[3][3].etat=true;
    mat[4][3].etat=true;
    mat[3][4].etat=true;
    return mat;
}

//Fonction permettant de changer la taille de la matrice afin que celle-ci soit divisible par 5
unsigned changeTailleMat5 (unsigned & tailleMat){
    while (true){
        if (tailleMat % 5 == 0)
            return tailleMat;
        else
            tailleMat++;
    }
}

//Fonction permettant de remplir le centre de la matrice aléatoirement
vector<vector<cellule>> remplirMatriceAleaCentre(vector<vector<cellule>> & mat, const unsigned & pourcentage,const unsigned & tailleMat){
    unsigned centre = tailleMat/5;
    for (unsigned li = 2*centre ; li<3*centre ; ++li){
        for (unsigned col = 2*centre ; col<3*centre ; ++col){
            unsigned alea = rand()%100;
            if (alea<pourcentage)
                mat[li][col].etat=true;
        }
    }
    return mat;
}

//Fonction permettant de creer une matrice selon une taille rentrée en paramètre
vector<vector<cellule>> creerMat (vector<vector<cellule>> & mat,const unsigned & taille){
    for (unsigned x = 0 ; x < taille ; ++x){
        vector<cellule> temp;
        for (unsigned y = 0; y < taille ; ++y){
            cellule cell;
            temp.push_back(cell);
        }
        mat.push_back(temp);
    }
    return mat;
}
