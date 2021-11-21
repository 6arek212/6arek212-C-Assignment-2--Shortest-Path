#include "my_mat.h"
#include <stdio.h>
#include <limits.h>
#include <stdio.h>

int graph[N][N];

void scanNewMatrix()
{
    // printf("\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            // printf("enter the weight between %d , %d \n", i, j);
            scanf(" %d", &graph[i][j]);
            // printf("\n");
        }
}

void printMatrix()
{
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isTherePath(int i, int j)
{
    if (graph[i][j])
        return 1;
    return 0;
}

int min(int x, int y)
{
    if (x <= y)
        return x;
    return y;
}

//floydWarshall
int shortestPath(int i, int j)
{

    int temp[N][N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp[0][i][j] = graph[i][j];
        }
    }

    for (int k = 1; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (temp[k - 1][i][j] != 0 && temp[k - 1][i][k] != 0 && temp[k - 1][k][j] != 0)
                    temp[k][i][j] = min(temp[k - 1][i][j], temp[k - 1][i][k] + temp[k - 1][k][j]);

                else if (temp[k - 1][i][j] != 0 && (temp[k - 1][i][k] == 0 || temp[k - 1][k][j] == 0))
                    temp[k][i][j] = temp[k - 1][i][j];

                else if (temp[k - 1][i][j] == 0 && (temp[k - 1][i][k] != 0 && temp[k - 1][k][j] != 0))
                    temp[k][i][j] = temp[k - 1][i][k] + temp[k - 1][k][j];

                else
                    temp[k][i][j] = 0;
            }
        }
    }

    return temp[N - 1][i][j];
}

// int main(int argc, char const *argv[])
// {
//     int mat[N][N] = {
//         {0, 3, 0, 7},
//         {8, 0, 2, 0},
//         {5, 0, 0, 1},
//         {2, 0, 0, 0}};

//     printf("\n %d \n", shortestPath(1, 2));

//     return 0;
// }
