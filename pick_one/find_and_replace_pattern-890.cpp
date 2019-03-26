//
// Created by m on 3/25/19.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string encoding(string str)
{
    unordered_map <char, int> encoding_str;
    for (auto c : str)
    {
        if(encoding_str.count(c) == 0) //new character
        {
            encoding_str[c] = encoding_str.size();
        }
    }
    for (int i = 0; i < str.size(); ++i)
    {
        str[i] = encoding_str[str[i]]; //encoding
    }
    return str;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    string pattern_encode = encoding(pattern);
    vector<string> result;
    for (auto word : words)
    {
        if(encoding(word) == pattern_encode)
            result.push_back(word);
    }
    return result;
}

int main()
{
    vector<string> str{"abc","deq","mee","aqq","dkd","ccc"};
    vector<string> res = findAndReplacePattern(str, "cdd");
    for(auto s : res)
        cout << s << endl;

    return 0;
}