/**
 * reshape the matrix;
 */
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
{
    int rows = (int)nums.size();
    int cols = (int)nums[0].size();
    if(rows * cols != r  * c)
        return nums;
    else
    {
        vector<vector<int>> nums_copy;
        nums_copy.resize(r);
        for (int k = 0; k < r; ++k)
        {
            nums_copy[k].resize(c);
        }
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                int index = i * cols + j;
                nums_copy[index / c][index % c] = nums[i][j];
            }

        }
        return nums_copy;
    }
}

int main()
{
    vector<int> cols;
    vector<vector<int> >matrix;
    cols.push_back(1);
    cols.push_back(2);
    matrix.push_back(cols);
    cols.clear();
    cols.push_back(2);
    cols.push_back(1);
    matrix.push_back(cols);

    vector<vector<int> >matrix_reshape = matrixReshape(matrix, 4, 1);
    for (int i = 0; i < matrix_reshape.size(); ++i)
    {
        for (int j = 0; j < matrix_reshape[0].size(); ++j)
        {
            cout << matrix_reshape[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
