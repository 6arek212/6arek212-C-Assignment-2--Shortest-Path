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

int graph[N][N] = {
    {0, 3, INT_MAX, 7},
    {8, 0, 2, INT_MAX},
    {5, INT_MAX, 0, 1},
    {2, INT_MAX, INT_MAX, 0}};

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
    if (graph[i][j] && graph[i][j] != INT_MAX)
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
                // if (temp[k - 1][i][j] != 0 && temp[k - 1][i][k] != 0 && temp[k - 1][k][j] != 0)
                //     temp[k][i][j] = min(temp[k - 1][i][j], temp[k - 1][i][k] + temp[k - 1][k][j]);

                // else if (temp[k - 1][i][j] != 0 && (temp[k - 1][i][k] == 0 || temp[k - 1][k][j] == 0))
                //     temp[k][i][j] = temp[k - 1][i][j];

                // else if (temp[k - 1][i][j] == 0 && (temp[k - 1][i][k] != 0 && temp[k - 1][k][j] != 0))
                //     temp[k][i][j] = temp[k - 1][i][k] + temp[k - 1][k][j];

                // else
                //     temp[k][i][j] = 0;

                if (temp[k - 1][i][k] == INT_MAX || temp[k - 1][k][j] == INT_MAX)
                    temp[k][i][j] = temp[k - 1][i][j];

                else
                    temp[k][i][j] = min(temp[k - 1][i][j], temp[k - 1][i][k] + temp[k - 1][k][j]);
            }
        }
    }

    if (temp[N - 1][i][j] != INT_MAX && temp[N - 1][i][j] != -1)
        return temp[N - 1][i][j];
    return -1;
}
