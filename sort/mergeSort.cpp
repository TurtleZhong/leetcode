//
// Created by m on 8/9/18.
//

#include <iostream>

using namespace std;

void merge(int *a, int low, int mid, int high, int *tmp)
{
    int i,j,k;
    i = low;
    j = mid + 1;
    k = 0;
    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while (i <= mid)
    {
        tmp[k++] = a[i++];
    }
    while (j <= high)
    {
        tmp[k++] = a[j++];
    }
    k = 0;
    while (low <= high)
    {
        a[low++] = tmp[k++];
    }
}


void mergeSort(int *a, int low, int high, int *tmp)
{
    int mid = low + (high-low) /2;
    if(low < high)
    {
        mergeSort(a, low, mid, tmp);
        mergeSort(a, mid+1, high, tmp);
        merge(a,low,mid,high,tmp);
    }

}

int main()
{

    int a[10] = {3, 4, 5, 7, 1, 0, 4, 12, 34, 23};
    int *tmp = new int[10];
    mergeSort(a,0,9,tmp);
    for (int i = 0; i < 10; ++i)
    {
        cout << tmp[i] << endl;
    }
    return 0;
}
