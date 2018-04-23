/**
 * Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may not use the same element twice.
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
    int left = 0;
    int right = numbers.size() - 1;
    vector<int> results;
    results.reserve(2);
    while (left < right)
    {
        int sum = numbers[left]+numbers[right];
        if(sum == target)
        {
            results.push_back(left+1);
            results.push_back(right+1);
            return results;
        }
        else if(sum > target)
            right--;
        else
            left++;
    }
}
int main()
{
    int nums[] = {2,7,11,15};
    vector<int> numbers(nums, nums+ sizeof(nums)/ sizeof(nums[0]));
    vector<int> results = twoSum(numbers, 9);
    cout << "index = " << results[0] << " " <<  results[1] << endl;

    return 0;
}