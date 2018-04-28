/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> m;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        m[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); ++i) {
        int t = target - nums[i];
        if (m.count(t) && m[t] != i) {
            res.push_back(i);
            res.push_back(m[t]);
            break;
        }
    }
    return res;
}



int main()
{
    vector<int> nums({2, 7, 11, 15});
    return 0;
}