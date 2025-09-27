#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

int main()
{
    int n, m, **l, i, p, j;
    char ch;
    scanf("%d %d ", &n, &m);
    l = malloc(n * sizeof(int *));
    if (!l)                             //if not l
    {
        return -1;
    }
    for (i = 0; i < n; i++)
    {
        l[i] = malloc(m * sizeof(int));

        if (!l[i])
        {
            
            return -1;
        }
    }
    printf("%d %d", n, m);
    i = 0;
    j = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch == 'C') //if curent character is "C"
        {
            l[i][j] = 1; //Changing the value to 1
            j++;
        }
        else if (ch == '.')//if curent character is "."
        {
            l[i][j] = 0;//Changing the value to 0
            j++;
        }
        else if (ch == '\n')//If current character is newline (\n)
        {
            i++;
            j = 0;//Changing j to 0 
            continue;
        }
    }
    printf("\n");
    for (i = 0; i < n; i++)//itterating through the array
    {

        for (j = 0; j < m; j++)
        {
            if (l[i][j] == 0)//if current value is 0
            {
                printf(".");//Printing a dot (".")
            }
            else if (l[i][j] == 1)//if current value is 1
            {
                printf("C");//Printing a dot ("C")
            }
        }
        printf("\n");
    }

    printf("\n");
    printf("Maximum number of coins to pick up is : %d \n", solve(n, m, l));//printing the biggest number using solve
    for (i = 0; i < n; i++)//itterating though the array
    {
        free(l[i]);//freeing the array 
    }
    free(l);//freeing the array
    return 0;
}
