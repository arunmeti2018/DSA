#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[20], n, k, i, j;

    printf("\nEnter the size of array");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 1; i < n; i++)
    {
        k = a[i];
        for (j = i - 1; j >= 0 && k < a[j]; j--)
        {
            a[j + 1] = a[j];

            a[j] = k;
        }
    }
    printf("After sorting\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}