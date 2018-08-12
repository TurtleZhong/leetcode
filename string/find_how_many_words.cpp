//
// Created by m on 8/12/18.
//

#include <iostream>
#include <string>

using namespace std;


int findWordsNum(char *a)
{
    if(a== nullptr)
        return 0;
    else
    {
        int count = 0;
        for (int i = 0; a[i]!='\0'; ++i)
        {
            if(a[i] == ' ')
            {
                count++;
            }
        }
        count++;
        return count;
    }
}

int main()
{
    string str = "How are you!";
    char *a = (char*)str.c_str();
    cout << "words = " << findWordsNum(a) << endl;
    return 0;
}