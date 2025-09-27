#include <stdio.h>
#include <stdlib.h>

int find(int n, int m, int **A, int **memo);
int max(int a, int b);
int solve(int n, int m, int **A);
void path(int n, int m, int **A);


int solve(int n, int m, int **A)//finding the Maximum number of coins to pick up
{
    int count, i, j;
    count = 0;
    for (j = 0; j < m; j++)
    {
        count += A[0][j];
        A[0][j] = count;
    }

    count = 0;
    for (i = 0; i < n; i++)
    {
        count += A[i][0];
        A[i][0] = count;
    }
    for (i = 1; i < n; i++)
    {
        count = 0;
        for (j = 1; j < m; j++)
        {
            count = A[i][j] + max(A[i][j - 1], A[i - 1][j]);
            A[i][j] = count;
        }
    }
    printf("The path is : \n");
    path(n - 1, m - 1, A);
    printf("\n");
    return A[n - 1][m - 1];
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void path(int n, int m, int **A)//Finding the path using reccursion 
{
    static int a, b;//Creating 2 static variables
    if (n == 0 && m != 0)//Checking if n is 0 and m is not 0
    {
        path(n, m - 1, A);
    }
    else if (n != 0 && m == 0)//Checking if n is not  0 and m is  0
    {
        path(n - 1, m, A);
    }
    else if (n != 0 && m != 0)//Checking if both n and m equal to 0
    {
        if (A[n][m - 1] >= A[n - 1][m])
        {
            path(n, m - 1, A);
        }
        else
        {
            path(n - 1, m, A);
        }
    }

    if (n != 0 || m != 0)
    {
        if ((A[n][m] - A[a][b]) == 1)
        {
            printf("C(%d,%d)/%d --->", n + 1, m + 1, A[n][m]);
        }
        else
        {
            printf(".(%d,%d)/%d --->", n + 1, m + 1, A[n][m]);
        }
    }
    else if (n == 0 && m == 0)
    {
        if (A[0][0] == 1)
        {
            printf("C(%d,%d)/%d --->", n + 1, m + 1, A[n][m]);
        }
        else
        {
            printf(".(%d,%d)/%d --->", n + 1, m + 1, A[n][m]);
        }
    }
    a=n;
    b=m;
}
