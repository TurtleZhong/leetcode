//
// Created by m on 8/6/18.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
void Swap(T &a, T &b)
{
    T c;
    c = a;
    a = b;
    b = c;
}
template <typename T>
void bubbleSort(T *data, int length)
{
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length-i-1; ++j)
        {
            if(data[j] > data[j+1])
                Swap(data[j], data[j+1]);
        }
    }
}

int main()
{
    int data[10] = {2, 4, 5, 7, 8, 3, 1, 0, 12, 6};
    bubbleSort(data,10);
    for (int i = 0; i < 10; ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}