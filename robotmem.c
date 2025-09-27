#include <stdio.h>
#include <stdlib.h>

int find(int n, int m, int **A, int **memo);
int max(int a, int b);
int solve(int n, int m, int **A);
void path(int n, int m, int **A, int **memo);

int solve(int n, int m, int **A)
{
    int **l, i, count, j;
    l = malloc(n * sizeof(int *));
    if (!l) //if not L
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
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            l[i][j] = -1;
        }
    }

    count = find(n - 1, m - 1, A, l); //coins  count

    printf("The path is : \n"); //Printing the path
    path(n - 1, m - 1, A, l);   //calling the path
    printf("\n");

    for (i = 0; i < n; i++)
    {
        free(l[i]); //disengaging the value we got
    }
    free(l); //disengaging the value we got
    return count;
}

int find(int n, int m, int **A, int **memo) //reccursion with memoization
{
    int result;
    if (memo[n][m] != -1)
    {
        return memo[n][m];
    }
    if (n == 0 && m == 0)
    {
        result = A[n][m];
    }
    else if (n == 0 && m != 0)
    {
        result = (find(n, m - 1, A, memo) + A[n][m]);
    }
    else if (n != 0 && m == 0)
    {
        result = (find(n - 1, m, A, memo) + A[n][m]);
    }
    else
    {
        result = (max(find(n, m - 1, A, memo), find(n - 1, m, A, memo)) + A[n][m]);
    }
    memo[n][m] = result;
    return result;
}

int max(int a, int b) //Finding the maximum number
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
void path(int n, int m, int **A, int **memo) //finding the path
{
    if (n == 0 && m != 0)
    {
        path(n, m - 1, A, memo);
    }
    else if (n != 0 && m == 0)
    {
        path(n - 1, m, A, memo);
    }
    else if (n != 0 && m != 0)
    {
        if (memo[n][m - 1] >= memo[n - 1][m])
        {
            path(n, m - 1, A, memo);
        }
        else
        {
            path(n - 1, m, A, memo);
        }
    }
    if (A[n][m] == 1)
    {
        printf("C(%d,%d)/%d --->", n + 1, m + 1, memo[n][m]);
    }
    else
    {
        printf(".(%d,%d)/%d --->", n + 1, m + 1, memo[n][m]);
    }
}
