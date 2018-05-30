/*
 * Given a word, you need to judge whether the usage of capitals in it is right or not.
 * We define the usage of capitals in a word to be right when one of the following cases holds:
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital if it has more than one letter, like "Google".
 * Otherwise, we define that this word doesn't use capitals in a right way.
 */

#include <iostream>
#include <string>

using namespace std;

bool detectCapitalUse(string word)
{
    int count = 0;
    for (auto i : word) if (isupper(i)) ++count;
    return !count || count == word.size() || isupper(word[0]) && count == 1;
}


int main()
{
    cout << detectCapitalUse("mUSAAAA") << endl;
    return 0;
}