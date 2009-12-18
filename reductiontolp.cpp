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


/*
matrix[0][0]=50;
matrix[0][1]=15;
matrix[0][2]=20;
matrix[1][0]=25;
matrix[1][1]=40;
matrix[1][2]=30;
matrix[2][0]=10;
matrix[2][1]=30;
matrix[2][2]=60;
*/
    if(gamerA)
    {
        A=new double*[var];

        for (int i=0; i<var; ++i)
            A[i] = new double[res];

        for (int i=0; i<var; ++i)
        for (int j=0; j<res; ++j)
        {
            std::cout<<matrix[i][j]<<"  ";
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
    }
    else
    {
        A=new double*[var];

        for (int i=0; i<var; ++i)
            A[i] = new double[res];

        for (int i=0; i<res; ++i)
        for (int j=0; j<var; ++j)
        {
            std::cout<<matrix[i][j]<<"  ";
            //FIXME
            A[i][j]=matrix[i][j];
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
    }

    return 0;
}

bool ReductionToLP::solve()
{
    Simplex simplex (var,res, C, B, A,min, EQ);
    simplex.solve();
    return 0;
}

