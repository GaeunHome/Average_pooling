#include <stdlib.h>
#include <stdio.h>
#define maxsize 100
 
int main()
{
    int row, col;
    scanf("%d%d", &row, &col);
    double first[maxsize][maxsize], second[maxsize][maxsize];
    double sum;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            scanf("%lf", &first[i][j]);
        }
    }
    for(int i=0; i<row; i++)
    {
        int count = 0;
        sum = 0;
        for(int j=0; j<col; j++)
        {
            for(int dx=-1; dx<=1; dx++)
            {
                for(int dy=-1; dy<=1; dy++)
                {
                    int k = i + dx;
                    int l = j + dy;
                    if( k>=0 && k<row && l>=0 && l<col )
                    {
                        sum += first[k][l];
                        count++;
                    }
                }
            }
            second[i][j] = sum / count;
            count = 0;
            sum = 0;
        }
    }
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(j!=col-1)
                printf("%.3f ", second[i][j]);
            else
                printf("%.3f", second[i][j]);
        }
        if(i!=row-1)
            printf("\n");
    }
}
