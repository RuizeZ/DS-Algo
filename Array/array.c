#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int *p;
    int length;
    int size;
};
void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.p[i]);
    }
    printf("\n");
}
void append(struct Array *arr, int num)
{
    if (arr->length < arr->size)
    {
        arr->p[arr->length] = num;
        arr->length++;
    }
}
void insert(struct Array *arr, int index, int num)
{
    if (index >= 0 && index < arr->size && arr->length < arr->size)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->p[i] = arr->p[i - 1];
        }
        arr->p[index] = num;
        arr->length++;
    }
}
int delete(struct Array *arr, int index)
{
    int val = -1;
    if (index >= 0 && index < arr->length)
    {
        val = arr->p[index];
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->p[i] = arr->p[i + 1];
        }
        arr->length--;
    }
    return val;
}
int main(int argc, char const *argv[])
{
    struct Array arr;
    arr.size = 10;
    arr.p = (int *)malloc(arr.size * sizeof(int));
    arr.length = 5;
    for (int i = 0; i < arr.length; i++)
    {
        arr.p[i] = i;
    }
    append(&arr, 10);
    display(arr);
    insert(&arr, 0, 100);
    display(arr);
    printf("%d\n", delete (&arr, 1));
    display(arr);
    return 0;
}
