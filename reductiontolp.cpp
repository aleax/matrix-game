#include "reductiontolp.h"

ReductionToLP::ReductionToLP(double **matrix, int cols, int rows, bool gamerA)
{
    this->matrix=matrix;
    this->gamerA=gamerA;
    this->cols=cols;
    this->rows=rows;
}

bool ReductionToLP::convert()
{
    char eq=EQUAL;
    min=gamerA;

    if(gamerA)
    {
        res=cols;
        eq=MORE_EQUAL;
        var=rows;
    }
    else
    {
        res=rows;
        eq=LESS_EQUAL;
        var=cols;
    }

    B = new double[res];
    C = new double[var];
    EQ = new char[res];

    A=new double*[var];
    for (int i=0; i<var; ++i)
        A[i] = new double[res];

    for (int i=0; i<var; ++i)
    for (int j=0; j<res; ++j)
    {
        //FIXME
        A[i][j]=matrix[j][i];
    }

    for (int i=0;i<res;++i)
    {
        B[i]=1;
        EQ[i]=eq;
    }

    for (int i=0; i<var; ++i)
    {
        C[i]=1;
    }

    return 0;
}

bool ReductionToLP::solve()
{
    Simplex simplex (var,res, C, B, A,min, EQ);
    simplex.solve();
}

