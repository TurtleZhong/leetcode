//
// Created by m on 8/10/18.
//

#include <iostream>

using namespace std;


int divide(int *a, int low, int high)
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


int findKthElement(int *a, int low, int high, int k)
{
    int kth = high+1-k;
    int index = divide(a, low, high);
    while (index != kth)
    {
        if(index < kth)
        {
            index = divide(a, index+1, high);
        } else
        {
            index = divide(a, low, index-1);
        }
    }
    return a[k];

}

int main()
{
    int a[] = {2, 3, 4, 7, 6, 9, 1};
    int kth = findKthElement(a, 0, 7-1, 2);
    cout << kth << endl;
    return 0;
}
