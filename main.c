#include <stdio.h>
#include "my_mat.h"

void printOptions()
{
    printf("\n\n");
    printf("Choose the desired operation : \n");
    printf("A- Enter new graph \n");
    printf("B- Check weither there is an edge between i and j \n");
    printf("C- Shortest path between i and j  \n");
    printf("D- Exist  \n");
}

void main()
{

    int mat[3][3] = {{0, 2, 3},
                     {10, 2, 3},
                     {2, 0, 4}};

    char choice = ' ';
    int i, j;

    while (choice != 'D')
    {

        // printOptions();

        scanf(" %c", &choice);

        switch (choice)
        {
        case 'A':
            scanNewMatrix();
            break;

        case 'B':
            // printf("enter i and j : \n");
            scanf("%d %d", &i, &j);
            // printf("\n");

            if (isTherePath(i, j))
                printf("True\n");
            else
                printf("False\n");
            break;

        case 'C':
            // printf("enter i and j");
            scanf("%d %d", &i, &j);
            // printf("shortest path is %d", shortestPath(i, j));

            printf("%d\n", shortestPath(i, j));
            break;

        case 'K':
            printMatrix();
            break;

        default:
            break;
        }
    }
}