#include <stdio.h>
// Recursive function to find the factorial of a number
long int factorial(int n)
{
    // Base case: n is 0 or 1
    if (n == 0 || n == 1)
    {
        return 1;
    }
    // Recursive case: n is greater than 1
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Factorial of %d = %ld\n", num, factorial(num));
    return 0;
}

/*
Output:
Enter a positive integer: 5
Factorial of 5 = 120
*/