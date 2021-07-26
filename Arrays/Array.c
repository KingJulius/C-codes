#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *data;
    int size;
    int length;
};

void Display(struct Array *ptr)
{
    printf("The elements in the array are:");
    for (int i = 0; i < ptr->size; i++)
        printf("%d ", ptr->data[i]);
}

struct Array init(int length)
{
    if (length > 0)
    {
        struct Array new_arr;
        new_arr.data = (int *)malloc(sizeof(int) * length * 2);
        for (int i = 0; i < length; i++)
            new_arr.data[i] = i + 100;
        for (int i = length; i < length * 2; i++)
            new_arr.data[i] = -1;
        new_arr.length = length;
        new_arr.size = length * 2;
        return new_arr;
    }
}

int Get(struct Array *ptr, int index)
{
    if (index <= ptr->length && index >= 0)
        return ptr->data[index];
    else
        return -1;
}

void Append(struct Array *ptr, int val)
{
    if (ptr->length < ptr->size)
    {
        ptr->data[ptr->length++] = val;
    }
}

int main()
{
    struct Array arr = init(5);
    struct Array *ptr = &arr;
    Display(ptr);
    
    //printf("%d ", Get(ptr, 0));
    
    Append(ptr, 300);
    Display(ptr);

    return 0;
}