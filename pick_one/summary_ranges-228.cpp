//
// Created by m on 3/24/19.
//

#include <iostream>
#include <vector>
using namespace std;

vector<string> summaryRanges(vector<int>& nums)
{
    vector<string> result;
    int num_size = static_cast<int>(nums.size());
    if(num_size == 0)
        return result;

    int window_left = nums[0];
    int window_right = window_left; //window left first position

    for (int i = 0; i < num_size; i++)
    {
        if(i+1 < num_size && (nums[i]+1 == nums[i+1]))
        {
            continue;
        } else
        {
            window_right = nums[i]; // update the window right
            string tmp;
            if(window_left == window_right)
                tmp+=to_string(window_left); // only one num
            else
            {
//                tmp = to_string(window_left) + "->" + to_string(window_right);
            }
            result.push_back(tmp);
            window_left = nums[i+1]; //update window left
        }

    }
    return result;
}

int main()
{
    vector<int> nums({0,1,2,4,5,7,8,9,11,12,15,16,18,20,21});
    vector<int> num1({0});
    vector<string> summary = summaryRanges(nums);

    for (auto &s : summary)
    {
        cout << s << ",";
    }
    cout << endl;

    return 0;
}