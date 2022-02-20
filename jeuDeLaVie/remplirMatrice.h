#ifndef REMPLIRMATRICE_H
#define REMPLIRMATRICE_H
#include "structCellule.h"
#include <vector>

std::vector<std::vector<cellule>> remplirMatriceAlea(std::vector<std::vector<cellule>> &,const unsigned &);
std::vector<std::vector<cellule>> remplirMatriceFloraison(std::vector<std::vector<cellule>> &);
std::vector<std::vector<cellule>> remplirMatriceCanon(std::vector<std::vector<cellule>> &);
std::vector<std::vector<cellule>> remplirMatriceFloraison2(std::vector<std::vector<cellule>> &);
std::vector<std::vector<cellule>> remplirMatricePlaneur(std::vector<std::vector<cellule>> &);
unsigned changeTailleMat5 (unsigned &);
std::vector<std::vector<cellule>> remplirMatriceAleaCentre(std::vector<std::vector<cellule>> &, const unsigned &,const unsigned &);
std::vector<std::vector<cellule>> creerMat (std::vector<std::vector<cellule>> &,const unsigned &);

#endif // REMPLIRMATRICE_H

