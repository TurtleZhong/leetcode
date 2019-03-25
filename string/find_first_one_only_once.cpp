//
// Created by m on 8/12/18.
//

#include <iostream>
#include <string>

using namespace std;

char getChar(char *str)
{
    if(str == nullptr)
    {
        return 0;
    }

    unsigned char count[256] = {0};

    char *p = nullptr;
    char buffer[256];
    char *q = buffer;
    for (p=str; *p != '\0'; ++p)
    {
        count[(unsigned char)*p]++;
        if(count[(unsigned char)*p] == 1)
        {
            *q = *p;
            q++;
        }

    }
    for (p = buffer; p < q; ++p)
    {
        if(count[(unsigned char)*p] == 1)
            return *p;
    }

}

int main()
{
    char str[] = "hello";
    char a = getChar(str);
    cout << a << endl;
    return 0;
}