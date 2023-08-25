#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int arr[10];
    int size;
    int length;
};

int binarySearchI(struct Array a, int target)
{
    int left = 0, right = a.length - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a.arr[mid] == target)
        {
            return mid;
        }
        else if (a.arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int binarySearchR(struct Array a, int target, int left, int right)
{
    if (left > right)
    {
        return -1;
    }
    int mid = (left + right) / 2;
    if (a.arr[mid] == target)
    {
        return mid;
    }
    else if (a.arr[mid] < target)
    {
        return binarySearchR(a, 1, mid + 1, right);
    }
    else
    {
        return binarySearchR(a, 1, left, mid - 1);
    }
}

int main(int argc, char const *argv[])
{
    struct Array a = {{1, 2, 3, 4, 5}, 10, 5};
    printf("Iterative: %d\n", binarySearchI(a, 1));
    printf("Recursion: %d\n", binarySearchR(a, 1, 0, a.length - 1));
    return 0;
}
