/**
 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> results;
    for (int row = 0; row < numRows; ++row)
    {
        vector<int> rows(row+1, 1);
        results.push_back(rows);

        if(row >=2)
        {
            for (int col = 1; col < row; ++col)
            {
                results[row][col] = results[row-1][col] + results[row-1][col-1];
            }
        }


    }
    return results;
}

int main()
{
    vector<vector<int>> results = generate(10);
    for (int i = 0; i < results.size(); ++i)
    {
        for (int j = 0; j < results[i].size(); ++j)
        {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
}