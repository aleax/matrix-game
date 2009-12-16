#ifndef REDUCTIONTOLP_H
#define REDUCTIONTOLP_H

#include "simplex.h"

using namespace simplex;

class ReductionToLP
{
protected:
    double **matrix;
    bool gamerA;
    int cols,rows;
public:
    ReductionToLP(double **matrix, int cols, int rows, bool gamerA);
};

#endif // REDUCTIONTOLP_H
