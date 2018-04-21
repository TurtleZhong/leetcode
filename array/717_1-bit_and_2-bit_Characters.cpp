/**
 * We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).
 * Now given a string represented by several bits. Return whether the last character must be a one-bit character or not.
 * The given string will always end with a zero.
 *
 * Example 1:
 * Input:
 * bits = [1, 0, 0]
 * Output: True
 * Explanation:
 * The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
 */

#include <iostream>
#include <vector>
using namespace std;

bool isOneBitCharacter(vector<int>& bits)
{
    bool flag = false;
    for (int i = 0; i < bits.size();)
    {
        if(bits[i]==1)
        {
            i = i+2;
            flag = false;
        } else
        {
            i = i+1;
            flag = true;
        }
    }
    return flag;
}

int main()
{
    int array[] = {1,0,1,1,1,0,0,0};
    vector<int> nums(array, array+8);
    cout << "The array is one-bit character?" << endl;
    if(isOneBitCharacter(nums))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}
