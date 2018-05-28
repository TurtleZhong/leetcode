/**
 *Given a string,
 * you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
 *
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverseWords(string s)
{
    string::iterator start = s.begin();
    string::iterator last_start = start;
    for (;start!=s.end(); start++)
    {
        if(*start == ' ')
        {
            //reverse
            reverse(last_start,start);
            if(*(start+1) != ' ')
            {
                last_start = start+1;
            }
        }
    }
    reverse(last_start, s.end());
    return s;
}

int main()
{
    cout << reverseWords("How are you?") << endl;
    return 0;
}