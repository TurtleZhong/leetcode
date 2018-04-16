/**
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.
 * Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 *
 * Example
 * Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
 * Output: True
 * Explanation:
 * 1234
 * 5123
 * 9512
 */

#include <iostream>
#include <vector>
using namespace std;


bool isToeplitzMatrix(vector<vector<int>>& matrix)
{
    bool isTMatrix = true;
    int rows = matrix.size();
    int cols = matrix[0].size();
    for(int i = 0; i < rows - 1; i++)
    {
        for(int j = 0; j < cols - 1; j++)
        {
            int key = matrix[i][j];
            int row = i + 1;
            int col = j + 1;
            while (row < rows && col < cols)
            {
                if(!isTMatrix)
                    return false;
                isTMatrix &= (key == matrix[row][col]);
                row++;
                col++;
            }
        }
    }
    return isTMatrix;
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

    cout << "Mstrix is T matrix?\n" << isToeplitzMatrix(matrix) << endl;

    return 0;
}