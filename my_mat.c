#include "my_mat.h"
#include <stdio.h>
#include <limits.h>

// int graph[N][N] = {
//     {0, 3, 1, 0, 0, 2, 0, 0, 0, 0},
//     {3, 0, 1, 0, 0, 0, 0, 0, 0, 0},
//     {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 5, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 4, 1, 1},
//     {2, 0, 0, 0, 0, 0, 2, 0, 0, 0},
//     {0, 0, 0, 0, 0, 2, 0, 0, 0, 0},
//     {0, 0, 0, 5, 4, 0, 0, 0, 0, 2},
//     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 1, 0, 0, 2, 0, 0}};

int graph[N][N];

// = {
//     {0, 3, INT_MAX, 7},
//     {8, 0, 2, INT_MAX},
//     {5, INT_MAX, 0, 1},
//     {2, INT_MAX, INT_MAX, 0}}


void scanNewMatrix()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            scanf(" %d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
            {
                graph[i][j] = INT_MAX;
            }
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
    if (shortestPath(i, j) != -1)
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

    int temp[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp[i][j] = graph[i][j];
        }
    }

    for (int k = 1; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (temp[i][k] == INT_MAX || temp[k][j] == INT_MAX && temp[i][k] + temp[k][j] < temp[i][j])
                    temp[i][j] = temp[i][k] + temp[k][j];
            }
        }
    }

    if (temp[i][j] != 0 && temp[i][j] != INT_MAX)
        return temp[i][j];
    return -1;
}
