/// Finding a Single Missing Element in a sorted Array
#include <stdio.h>
#include <stdlib.h>

// O(n)
void MissingElement(int *arr, int tot_size)
{
    // Using Sum of n natural numbers formula
    int num_of_elements = tot_size / sizeof(int);
    int last_ele = arr[num_of_elements - 1];
    int tot_sum = (last_ele * (last_ele + 1)) / 2;
    printf("%d ", tot_sum);

    int summer = 0;
    for (int i = 0; i < num_of_elements; i++)
        summer += arr[i];
    printf("%d ", summer);
    printf("\n%d is the missing element from the array", tot_sum - summer);
}

// O(n)
void MissingElement2(int *arr, int tot_size)
{
    int l = 6;
    int h = 17;
    int n = tot_size / sizeof(int);
    int diff = l - 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - i != diff)
        {
            printf("%d is the element that is missing\n", i + diff);
            break;
        }
    }
}

int main()
{
    // int arr1[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
    // MissingElement(arr1, sizeof(arr1));

    int arr2[] = {6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17};
    MissingElement2(arr2, sizeof(arr2));
    return 0;
}