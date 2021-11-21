#include "my_mat.h"
#include <stdio.h>
#include <limits.h>
#include <stdio.h>

int graph[N][N];

void scanNewMatrix()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            scanf(" %d", &graph[i][j]);
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

