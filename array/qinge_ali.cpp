//
// Created by m on 9/7/18.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string input = "singer_周杰|周杰伦|刘德华|王力宏;song_冰雨|北京欢迎你|七里香;actor_周杰伦|孙俪";
string command = "请播放周杰伦的七里香给我听";


void SplitString(const string& s, vector<string>& v, const string& c)
{
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}

int main()
{
    string data;
//    cin >> data;
//    cout << "data = " << data << endl;

    vector<string> objects;
    SplitString(input, objects, ";");

//    for (int i = 0; i < objects.size(); ++i)
//    {
//        cout << objects[i] << endl;
//    }

    map<string, vector<string>> hash_map;

    for (int j = 0; j < objects.size(); ++j)
    {
        string &object = objects[j];
        vector<string> two_parts;
        SplitString(object, two_parts, "_");
        string value = two_parts[0];
        vector<string> keys;
        SplitString(two_parts[1], keys, "|");
        for (int i = 0; i < keys.size(); ++i)
        {

            if(hash_map.count(keys[i]))
            {
                auto &values = hash_map[keys[i]];
                values.push_back(value);
            } else
            {
                vector<string> values;
                values.push_back(value);
                hash_map[keys[i]] = values;
            }

        }
    }

    for (auto it = hash_map.begin(); it!=hash_map.end(); ++it)
    {
        cout << it->first << ":";
        for (int i = 0; i < it->second.size(); ++i)
        {
            cout << (it->second)[i] << " ";
        }
        cout << endl;
    }


    string command_copy = command;
    vector<string> two_parts;
    SplitString(command_copy, two_parts, "的");
    string key1 = two_parts[0].erase(0,9);
    auto it = hash_map.find(key1);
    vector<string> values = it->second;
    sort(values.begin(), values.end());

    stringstream ss;

    ss << key1 << "/";
    for (int k = 0; k < values.size(); ++k)
    {
        ss << values[k];
        if(k != values.size()-1)
            ss << ",";
    }

    string tmp;
    ss >> tmp;
    cout << tmp;

    string key_tmp1 = two_parts[1];
    vector<string> parts;
    SplitString(key_tmp1, parts, "给");
    string key2  = parts[0];


    auto it1 = hash_map.find(key2);
    vector<string> values1 = it1->second;
    sort(values1.begin(), values1.end());
    stringstream ss1;

    cout << endl;

    ss1 << key2 << "/";
    for (int k = 0; k < values1.size(); ++k)
    {
        ss1 << values1[k];
        if(k != values1.size()-1)
            ss1 << ",";
    }

    string tmp2;
    ss1 >> tmp2;
    cout << tmp2;

    return 0;
}