//
// Created by m on 8/9/18.
//

#include <iostream>

using namespace std;

// divide a array to two part!
int division(int *a, int low, int high)
{

    int base = a[low];
    while(low < high)
    {
        while(low < high && a[high] >= base)
        {
            high--;
        }
        a[low] = a[high];
        while(low < high && a[low] <= base)
        {
            low++;
        }
        a[high] = a[low];

    }
    a[low] = base;
    return low;
}

void quickSort(int *a, int low, int high)
{
    if(low <= high)
    {
        int mid = division(a, low, high);
        quickSort(a, low, mid-1);
        quickSort(a, mid+1, high);
    } else
        return;
}

int main()
{
    int a[] = {6, 8, 5, 11, 2, 9, 7};
    int len = sizeof(a)/ sizeof(a[0]);
//    division(a, 0, len-1);
    quickSort(a, 0, len-1);
    for (int i = 0; i < len; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}