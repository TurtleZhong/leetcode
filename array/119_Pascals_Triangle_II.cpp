/**
 * Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
 * Note that the row index starts from 0.
 * Could you optimize your algorithm to use only O(k) extra space?
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex)
{
    vector<int> last_row(1,1);
    vector<int> curr_row(last_row);
    if(rowIndex < 1)
        return last_row;
    else
    {
        for (int row = 1; row < rowIndex+1; ++row)
        {
            curr_row.push_back(1);
            for (int col = 1; col < row; ++col)
            {
                curr_row[col] = last_row[col]+last_row[col-1];
            }
            last_row = curr_row;
        }
    }
    return curr_row;
}

int main()
{
    vector<int> results = getRow(3);
    for (int i = 0; i < results.size(); ++i)
    {
        cout << results[i] << " ";
    }
    cout << endl;
}