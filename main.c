#include <stdio.h>
#include "my_mat.h"



void main()
{

    char choice = ' ';
    int i, j;

    while (choice != 'D')
    {

        scanf(" %c", &choice);

        switch (choice)
        {
        case 'A':
            scanNewMatrix();
            break;

        case 'B':
            scanf("%d %d", &i, &j);

            if (isTherePath(i, j))
                printf("True\n");
            else
                printf("False\n");
            break;

        case 'C':
            scanf("%d %d", &i, &j);
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