//
// Created by m on 8/12/18.
//

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void reserveString(char *ch)
{
    cout << "ch.length = " << strlen(ch) << endl;
    char *p = ch;
    char *q = ch + strlen(ch)-1;
    for (; p < q; p++,q--)
    {
//        swap(*p, *q);
        *p = *p^*q;
        *q = *p^*q;
        *p = *p^*q;
    }
}

int main()
{
    char str[] = "How are you?";
    reserveString(str);
    cout << string(str) << endl;
    return 0;
}