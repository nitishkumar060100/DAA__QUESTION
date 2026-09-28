#include <stdio.h>

int main()
{
    int base, power;
    int result = 1;

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter power: ");
    scanf("%d", &power);

    for (int i = 1; i <= power; i++)
    {
        result = result * base;
    }

    printf("Answer = %d\n", result);

    return 0;
}