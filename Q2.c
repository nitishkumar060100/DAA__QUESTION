#include <stdio.h>
#include <time.h>
#define REPEAT 1000000
unsigned long long factorialRecursive(int n) {
if (n <= 1)
return 1;
return n * factorialRecursive(n - 1);
}
unsigned long long factorialIterative(int n) {
unsigned long long fact = 1;
for (int i = 2; i <= n; i++)
fact *= i;
return fact;
}
int main() {
int n;
printf("Enter a number: ");
scanf("%d", &n);
if (n < 0) {
return 0;
printf("Factorial is not defined for negative numbers.\n");
}
unsigned long long recursiveResult = 0, iterativeResult = 0;
clock_t start, end;
start = clock();
for (int i = 0; i < REPEAT; i++)
recursiveResult = factorialRecursive(n);
end = clock();
double recursiveTime =
(double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
start = clock();
for (int i = 0; i < REPEAT; i++)
iterativeResult = factorialIterative(n);
end = clock();
double iterativeTime =
(double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
printf("\nFactorial of %d = %llu\n", n, recursiveResult);
printf("Recursive Method : %.3f ms\n", recursiveTime);
printf("Iterative Method : %.3f ms\n", iterativeTime);
printf("\nTime Complexity:\n");
printf("Recursive : O(n)\n");
printf("Iterative : O(n)\n");
printf("\nSpace Complexity:\n");
printf("Recursive : O(n) due to function call stack\n");
printf("Iterative : O(1)\n");
return 0;