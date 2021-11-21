#include "my_mat.h"
#include <stdio.h>
#include <limits.h>






    int graph[N][N] = {
        {0, 6, 5, 29, 4, 0, 12, 15, 46, 10},
        {6, 0, 32, 41, 35, 18, 15, 48, 41, 4},
        {5, 32, 0, 30, 21, 4, 48, 24, 30, 27},
        {29, 41, 30, 0, 48, 10, 29, 13, 31, 42},
        {4, 35, 2, 48, 0, 30, 24, 40, 22, 23},
        {0, 18, 14, 10, 30, 0, 1, 11, 8, 12},
        {12, 15, 48, 29, 24, 1, 0, 17, 45, 8},
        {15 ,48 ,24 ,13 ,40, 11, 17 ,0, 21 ,33},
        { 46 ,41, 30 ,31 ,22 ,8, 45, 21, 0 ,8},
        {10, 4, 27, 42, 23, 12, 8, 33, 8, 0}};


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
            else if (i == j)
                graph[i][j] = 0;
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
    if (i == j)
        return -1;

    int temp[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (temp[i][k] != INT_MAX && temp[k][j] != INT_MAX && temp[i][k] + temp[k][j] < temp[i][j])
                    temp[i][j] = temp[i][k] + temp[k][j];
            }
        }
    }

    if (temp[i][j] != 0 && temp[i][j] != INT_MAX)
        return temp[i][j];
    return -1;
}
