//
// Created by m on 8/8/18.
//
#include <iostream>

using namespace std;


void mergeSortedArray(int *a, int len1, int *b, int len2, int *tmp)
{
    int i,j,k;
    i = j = k = 0;
    while (i < len1 && j<len2)
    {
        if(a[i] <= b[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = b[j++];
    }

    // append the left
    while (i<len1)
    {
        tmp[k++] = a[i++];
    }
    while (j<len2)
    {
        tmp[k++] = b[j++];
    }
}


class ABC
{
public:
    ABC()
    {
        cout << "kong" << endl;
    };
    explicit ABC(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    };

    void print()
    {
        cout << a << b << c << endl;
    }

public:
    int a;
    int b;
    int c;
};

class myClass
{
public:
    myClass()
    {
        abc = ABC(1,2,3);
        cout << "construct" << endl;
    }
    void print()
    {
        cout << abc.a << abc.b << abc.c <<  endl;
    }
private:
    ABC abc;
};

int main()
{


    myClass test;
    test.print();


    int a[9] = {4, 6, 7, 9};
    int b[] = {1, 2, 5, 8, 10, 12};



    int *merge = new int[10];
    cout << "size of merge = " << sizeof(a) << endl;
    mergeSortedArray(a, 4, b, 6, merge);

    for (int i = 0; i < 10; ++i)
    {
        cout << merge[i] << " ";
    }
    cout << endl;


    return 0;

}
