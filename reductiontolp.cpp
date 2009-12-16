#include "reductiontolp.h"

ReductionToLP::ReductionToLP(double **matrix, int cols, int rows, bool gamerA)
{
    this->matrix=matrix;
    this->gamerA=gamerA;
    this->cols=cols;
    this->rows=rows;
}
