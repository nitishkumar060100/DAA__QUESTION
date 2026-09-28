#include <stdio.h>

int findCelebrity(int C[3][3], int n)
{
    int candidate = 0;
    int i;

    // Step 1: Find a possible celebrity
    for (i = 1; i < n; i++)
    {
        if (C[candidate][i] == 1)
        {
            candidate = i;
        }
    }

    // Step 2: Verify the candidate
    for (i = 0; i < n; i++)
    {
        if (i != candidate)
        {
            // Celebrity should know nobody
            // Everyone should know the celebrity
            if (C[candidate][i] == 1 || C[i][candidate] == 0)
            {
                return -1;
            }
        }
    }

    return candidate;
}

int main()
{
    int C[3][3] = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 1}
    };

    int n = 3;
    int celebrity;

    celebrity = findCelebrity(C, n);

    if (celebrity == -1)
    {
        printf("No Celebrity exists\n");
    }
    else
    {
        printf("Celebrity is: ");

        if (celebrity == 0)
            printf("A\n");
        else if (celebrity == 1)
            printf("B\n");
        else
            printf("C\n");
    }

    return 0;
}