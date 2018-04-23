/**
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

bool containsDuplicate(vector<int>& nums)
{
    if (nums.empty())
        return false;
    unordered_map<int,int> hash_table;
    for (int i = 0; i < nums.size(); ++i)
    {
        if(hash_table.count(nums[i]))
            return true;
        else
            hash_table[nums[i]] = 1;
    }
    return false;
}

int main()
{
    int nums[] = {2,2};
    vector<int> numbers(nums, nums+ sizeof(nums)/ sizeof(nums[0]));
    cout << "The numbers contain duplicate number?" << endl;
    cout << containsDuplicate(numbers) << endl;
}