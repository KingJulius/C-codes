#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *data;
    int length;
    int size;
};

// For a unsorted & sorted arrays as inputs - O(n)
void setMembership(struct Array *arr, int val)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->data[i] == val)
        {
            printf("Exists at %d position of the set", i);
            return;
        }
    }
    printf("Doesn't Exist in Set");
}

// For a sorted arrays as inputs - O(n)
struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->data[i] < arr2->data[j])
            arr3->data[k++] = arr1->data[i++];
        else if (arr2->data[j] < arr1->data[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->data[k++] = arr1->data[i];
    arr3->length = k;
    arr3->size = k;
    return arr3;
}

// For a sorted arrays as inputs - O(n)
struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->data[i] < arr2->data[j])
            i++;
        else if (arr2->data[j] < arr1->data[i])
            j++;
        else if (arr1->data[i] == arr2->data[j])
        {
            arr3->data[k++] = arr1->data[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = k;
    return arr3;
}

// For a sorted arrays as inputs - O(n)
struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->data[i] < arr2->data[j])
            arr3->data[k++] = arr1->data[i++];
        else if (arr2->data[j] < arr1->data[i])
            arr3->data[k++] = arr2->data[j++];
        else
        {
            arr3->data[k++] = arr1->data[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->data[k++] = arr1->data[i];
    for (; j < arr2->length; j++)
        arr3->data[k++] = arr2->data[j];

    arr3->length = k;
    arr3->size = k;
    return arr3;
}

// O(n)
void Display(struct Array *ptr)
{
    if (ptr->length == 0)
        printf("Empty Array\n");
    for (int i = 0; i < ptr->length; i++)
        printf("%d", ptr->data[i]);
}

struct Array init()
{
    printf("\nInitializer...\n");
    struct Array array;
    printf("Enter size of array: ");
    scanf("%d", &array.size);

    array.data = (int *)malloc(array.size * sizeof(int));
    for (int i = 0; i < array.size; i++)
        array.data[i] = -1;

    printf("Enter length of array: ");
    scanf("%d", &array.length);

    printf("Enter the numbers: ");
    for (int i = 0; i < array.length; i++)
        scanf("%d", &array.data[i]);

    return array;
}

int main()
{
    struct Array arr1 = init();
    //struct Array arr2 = init();

    printf("The elements in Array 1:\n");
    Display(&arr1);

    //printf("\nThe elements in Array 2:\n");
    //Display(&arr2);

    // struct Array *ptr1 = Union(&arr1, &arr2);
    // printf("\nThe elements in Union Array:\n");
    // Display(ptr1);

    // struct Array *ptr1 = Intersection(&arr1, &arr2);
    // printf("\nThe elements in Intersection Array:\n");
    // Display(ptr1);

    //struct Array *ptr1 = Difference(&arr1, &arr2);
    //printf("\nThe elements in Difference Array:\n");
    //Display(ptr1);

    setMembership(&arr1, 5);

    return 0;
}