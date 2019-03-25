/**
 * Write a function that takes a string as input and returns the string reversed.
 * Example:
 * Given s = "hello", return "olleh".
 */

#include <iostream>
#include <string>

using namespace std;


string reverseString(string s)
{
    string::iterator begin = s.begin();
    string::iterator end = s.end()-1;
    while (begin < end)
    {
        swap(*begin,*end);
        begin++;
        end--;
    }
    return s;
}

int main()
{
    cout << reverseString("1234") << endl;
    return 0;
}
