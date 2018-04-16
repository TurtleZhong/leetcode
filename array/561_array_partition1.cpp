/**
 * Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2),
 * ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
 *
 * Example1
 * Input: [1,4,3,2]
 * Output: 4
 * Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
 *
 * Note
 * n is a positive integer, which is in the range of [1, 10000].
 * All the integers in the array will be in the range of [-10000, 10000].
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

int arrayPairSum(vector<int>& nums)
{
    int sum = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i = i+2)
    {
        sum = sum + nums[i];
    }
    return sum;
}

int main()
{
    vector<int> nums;
    srand((unsigned)time(nullptr));
    for(int i = 0; i < 10; i++)
    {
        cout << rand()%10 << endl;
        nums.push_back(rand()%10);
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << arrayPairSum(nums) << endl;

    return 0;
}
