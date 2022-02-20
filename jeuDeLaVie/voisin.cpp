#include "structCellule.h"
#include <vector>

using namespace std;

void trouverVoisin (vector<vector<cellule>> & mat){
    for (unsigned li = 0; li < mat.size(); ++li){
        for (unsigned col = 0; col < mat[li].size(); ++col){
            unsigned cpt = 0;
            // cas n°1 : la cellule ne se situe pas sur un bord
            if ((li > 0) && (li < (mat.size() - 1)) && (col > 0) && (col < (mat[0].size() - 1))){
                for (unsigned y = li - 1; y <= li + 1; ++y){
                    for (unsigned x = col - 1; x <= col + 1; ++x){
                        if ((x != col || y != li) && mat[y][x].etat){
                            ++cpt;
                        }
                    }
                }
            }
            // cas n°2 : bordure haute
            else if ((li == 0) && !((col == 0) || (col == mat[0].size() -1))){
                for (unsigned y = li; y <= li + 1; ++y){
                    for (unsigned x = col - 1; x <= col + 1; ++x){
                        if ((x != col || y != li) && mat[y][x].etat){
                            ++cpt;
                        }
                    }
                }
            }
            // cas n°3 : bordure basse
            else if ((li == mat.size() - 1) && !((col == 0) || (col == mat[0].size() -1))){
                for (unsigned y = li - 1; y <= li; ++y){
                    for (unsigned x = col - 1; x <= col + 1; ++x){
                        if ((x != col || y != li) && mat[y][x].etat){
                            ++cpt;
                        }
                    }
                }
            }
            // cas n°4 : bordure gauche
            else if ((col == 0) && !((li == 0) || (li == mat.size() -1))){
                for (unsigned y = li - 1; y <= li +1; ++y){
                    for (unsigned x = col; x <= col + 1; ++x){
                        if ((x != col || y != li) && mat[y][x].etat){
                            ++cpt;
                        }
                    }
                }
            }
            // cas n°5 : bordure droite
            else if ((col == mat.size() - 1) && !((li == 0) || (li == mat.size() -1))){
                for (unsigned y = li - 1; y <= li +1; ++y){
                    for (unsigned x = col - 1; x <= col; ++x){
                        if ((x != col || y != li) && mat[y][x].etat){
                            ++cpt;
                        }
                    }
                }
            }
            // cas n°6 : angle supérieur gauche
            else if ((li == 0) && (col == 0)){
                if (mat[0][1].etat){
                    ++cpt;
                }
                if (mat[1][0].etat){
                    ++cpt;
                }
                if (mat[1][1].etat){
                    ++cpt;
                }
            }
            // cas n°7 : angle supérieur droit
            else if ((li == 0) && (col == mat[0].size() - 1)){
                if (mat[li][col-1].etat){
                    ++cpt;
                }
                if (mat[li+1][col-1].etat){
                    ++cpt;
                }
                if (mat[li+1][col].etat){
                    ++cpt;
                }
            }
            // cas n°8 : angle inferieur gauche
            else if ((li == mat.size() - 1) && (col == 0)){
                if (mat[li-1][col].etat){
                    ++cpt;
                }
                if (mat[li-1][col+1].etat){
                    ++cpt;
                }
                if (mat[li][col+1].etat){
                    ++cpt;
                }
            }
            // cas n°9 : angle inferieur droit
            else if ((li == mat.size() - 1) && (col == mat[0].size() - 1)){
                if (mat[li-1][col].etat){
                    ++cpt;
                }
                if (mat[li-1][col-1].etat){
                    ++cpt;
                }
                if (mat[li][col-1].etat){
                    ++cpt;
                }
            }
            mat[li][col].nbVoisin = cpt;
        }
    }
}
