#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    printf("Enter an integer number: ");
    scanf("%d", &num);

    if (sqrt(num) == (int)sqrt(num))
    {
        printf("%d is a perfect square.\n", num);
    }
    else
    {
        printf("%d is not a perfect square.\n", num);
    }

    return 0;
}

/*
Output:
Enter an integer number: 25
25 is a perfect square.
*/