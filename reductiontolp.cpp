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
        //res=cols;
        eq=MORE_EQUAL;
      //  var=rows;
    }
    else
    {
       // res=rows;
        eq=LESS_EQUAL;
        //var=cols;
    }



    if(gamerA)
    {
        B = new double[cols];
        C = new double[rows];
        EQ = new char[cols];

        A=new double*[cols];
        for (int i=0; i<cols; ++i)
            A[i] = new double[rows];


        for (int i=0; i<rows; ++i)
        for (int j=0; j<cols; ++j)
        {
            //std::cout<<matrix[i][j]<<"  ";
            //FIXME
            A[i][j]=matrix[j][i];
        }

        for (int i=0;i<cols;++i)
        {
            B[i]=1;
            EQ[i]=eq;
        }

        for (int i=0; i<rows; ++i)
        {
            C[i]=1;
        }
    }
    else
    {
        B = new double[rows];
        C = new double[cols];
        EQ = new char[rows];

        A=new double*[rows];
        for (int i=0; i<rows; ++i)
            A[i] = new double[cols];

        for (int i=0; i<rows; ++i)
        for (int j=0; j<cols; ++j)
        {
            //std::cout<<matrix[i][j]<<"  ";
            //FIXME
            A[i][j]=matrix[i][j];
        }

        for (int i=0;i<rows;++i)
        {
            B[i]=1;
            EQ[i]=eq;
        }

        for (int i=0; i<cols; ++i)
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
}

