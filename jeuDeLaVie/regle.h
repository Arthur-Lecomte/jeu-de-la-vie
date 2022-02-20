#ifndef REGLE_H
#define REGLE_H
#include <vector>
#include "structCellule.h"

void regleBasique (std::vector<std::vector<cellule>> &);
void regleConway (std::vector<std::vector<cellule>> &);
void regleExpensionLente (std::vector<std::vector<cellule>> &);

#endif // REGLE_H
