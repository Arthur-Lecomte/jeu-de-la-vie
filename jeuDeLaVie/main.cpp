#include <vector>
#include <ctime>
#include <random>
#include "structCellule.h"
#include "automateCellulaire.h"

using namespace std;

int main()
{
    srand(time(NULL));
    vector<vector<cellule>>matrice;
    automate(matrice);
    return 0;
}
