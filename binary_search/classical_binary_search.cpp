//
// Created by m on 8/4/18.
//

#include <iostream>
#include <vector>

using namespace std;


template <typename T>
int binarySearch(vector<T> &data, T key)
{
    int low = 0;
    int high = data.size()-1;
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        if(data[mid] == key)
            return mid;
        else if(data[mid] < key)
        {
            low = mid+1;
        } else
        {
            high = mid-1;
        }
    }
    return -1;
}

int main()
{
    int a[10] = {0, 2, 5, 6, 9, 12, 13, 15, 22, 34};
    vector<int> data(a, a+10);
    int result = binarySearch(data, 13);
    cout << result << endl;
    return 0;
}