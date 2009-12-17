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

    int var;
    int res;
    double *C;
    double *B;
    double **A;
    bool min;
    char *EQ;

public:
    ReductionToLP(double **matrix, int cols, int rows, bool gamerA);
    bool convert();
    bool solve();
};

#endif // REDUCTIONTOLP_H
