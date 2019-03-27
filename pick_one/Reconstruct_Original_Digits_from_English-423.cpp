//
// Created by m on 3/27/19.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


string originalDigits(string s) {
    unordered_map<char,int> char_count;
    vector<int> nums(10,0);
    string str_out;

    for(auto c:s)
        char_count[c]++; //map

    nums[0] = char_count['z'];
    nums[2] = char_count['w'];
    nums[4] = char_count['u'];
    nums[6] = char_count['x'];
    nums[8] = char_count['g'];
    nums[3] = char_count['h'] - nums[8];
    nums[7] = char_count['s'] - nums[6];
    nums[5] = char_count['f'] - nums[4];
    nums[1] = char_count['o'] - nums[0] - nums[2] - nums[4];
    nums[9] = char_count['i'] - nums[5] - nums[6] - nums[8];

    for (int i = 0; i < 10; ++i)
    {
        while(nums[i] > 0)
        {
            str_out += ('0' + i);
            nums[i]--;
        }
    }
    return str_out;
}

int main()
{
    string s = "owoztneoerzero";

    cout << originalDigits(s) << endl;
    return 0;
}