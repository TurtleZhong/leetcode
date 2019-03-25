//
// Created by m on 9/9/18.
//

#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

string encoding(string &in)
{

    map<char,string> encode_map;
    int count = 0;
    encode_map[in[0]] = "0";
    string out("0");
    for (string::iterator it = in.begin()+1;it!= in.end(); it++)
    {
        if(encode_map.count(*it))
        {
            out += encode_map[*it];
        } else
        {
            count++;
            stringstream ss;
            ss << count;
            string tmp;
            ss >> tmp;
            encode_map[*it] = tmp;
            out+=tmp;
        }
    }
    return out;
}

bool isEqual(string &s1, string &s2)
{
    if(s1.length()!=s2.length())
        return false;
    string s1_out = encoding(s1);
    string s2_out = encoding(s2);
    return (s1_out == s2_out);

}





int Solve(string &s, string &t)
{
    int t_length = t.length();
    int s_length = s.length();
    if(t_length > s_length)
        return 0;
    int out_nums = 0;
    string encode_t = encoding(t);
    cout << "t_encod = " << encode_t << endl;
    for (int i = 0; i <= s_length - t_length; ++i)
    {
        string tmp(s.substr(i, t_length));
        cout << "tmp = " << tmp << endl;
        if(encoding(tmp) == encode_t)
            out_nums++;
    }


    return out_nums;
}

int main()
{

    string s,t;
//    cin >> s;
//    cin >> t;
    s = "ababcb";
    t = "xyx";
    cout << s << endl << t << endl;

    cout << encoding(t) << endl;
    cout << isEqual(s,t) << endl;
    cout << Solve(s,t) << endl;

    return 0;
}