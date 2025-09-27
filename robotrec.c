#include <stdio.h>
#include <stdlib.h>

int solve(int n, int m, int **A);
int max(int a, int b);


int count = 0;
int solve(int n, int m, int **A)//staring a new definition | this is used for reccursion
{
    if (count == 0)//checking if the value of count is 0 (this is made so it can only be true once)
    {
        n--;//making the value of n =-1
        m--;//making the value of m =-1
        count++;//adding one to count so the current if never get accepted again
    }
    if (n == 0 && m == 0)
    {
        return A[n][m];
    }
    else if (n == 0 && m != 0)
    {
        return (solve(n, m - 1, A) + A[n][m]);
    }
    else if (n != 0 && m == 0)
    {
        return (solve(n - 1, m, A) + A[n][m]);
    }
    else
    {
        return (max(solve(n, m - 1, A), solve(n - 1, m, A)) + A[n][m]);
    }
}

int max(int a, int b)//Finding the maximum number
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