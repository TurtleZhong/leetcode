/**
 * Given an array of integers and an integer k,
 * find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j]
 * and the absolute difference between i and j is at most k.
 *
 * Input: [1,2,3,1], k = 3
 * Output: true
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    map<int,int> hashMap;
    for (int i = 0; i < nums.size(); ++i)
    {
        if(hashMap.count(nums[i]) && i - hashMap[nums[i]] <= k)
            return true;
        else
            hashMap[nums[i]] = i;
    }
    return false;
}

int main()
{
    vector<int> nums({1,2,3,1});
    cout << containsNearbyDuplicate(nums, 3) << endl;
}