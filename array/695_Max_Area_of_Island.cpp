/**
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.)
 * You may assume all four edges of the grid are surrounded by water.
 * Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
 *
 * Example
 *  [[0,0,1,0,0,0,0,1,0,0,0,0,0],
     [0,0,0,0,0,0,0,1,1,1,0,0,0],
     [0,1,1,0,1,0,0,0,0,0,0,0,0],
     [0,1,0,0,1,1,0,0,1,0,1,0,0],
     [0,1,0,0,1,1,0,0,1,1,1,0,0],
     [0,0,0,0,0,0,0,0,0,0,1,0,0],
     [0,0,0,0,0,0,0,1,1,1,1,0,0],
     [0,0,0,0,0,0,0,1,1,0,0,0,0]]
     Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int maxAreaOfIsland(vector<vector<int>>& grid)
{
    vector<vector<int>> grid_label(grid);
    cout << grid_label.size() << " x " << grid_label[0].size() << endl;
    int label = 1;

    int rows = grid.size();
    int cols = grid[0].size();
    int max = 0;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            int count = 0;
            if(grid_label[i][j] == 1)
            {
                stack<pair<int,int>> neighbors;
                neighbors.push(make_pair(i, j));
                label++;
                count = 0;

                while(!neighbors.empty())
                {
                    pair<int,int> curr = neighbors.top();

                    int curr_x = curr.first;
                    int curr_y = curr.second;
                    if(grid_label[curr_x][curr_y] != label)
                    {
                        grid_label[curr_x][curr_y] = label;
                        count++;
                    }

                    neighbors.pop();

                    if(curr_x -1 >=0  && grid_label[curr_x-1][curr_y] == 1)
                        neighbors.push(make_pair(curr_x - 1, curr_y));
                    if(curr_x +1 < rows && grid_label[curr_x+1][curr_y]==1)
                        neighbors.push(make_pair(curr_x+1, curr_y));
                    if(curr_y - 1 >= 0 && grid_label[curr_x][curr_y-1] == 1)
                        neighbors.push(make_pair(curr_x, curr_y - 1));
                    if(curr_y + 1 < cols && grid_label[curr_x][curr_y+1] == 1)
                        neighbors.push(make_pair(curr_x, curr_y+1));
                }
            }
            if(max < count)
                max = count;
        }
    }
    /**
     * Show the label
     */
    for (int k = 0; k < rows; ++k)
    {
        for (int i = 0; i < cols; ++i)
        {
            cout << grid_label[k][i] << " ";
        }
        cout << endl;
    }
    return max;

}

int main()
{
    int array[8 ][13] ={{0,0,1,0,0,0,0,1,0,0,0,0,0},
                        {0,0,0,0,0,0,0,1,1,1,0,0,0},
                        {0,1,1,0,1,0,0,0,0,0,0,0,0},
                        {0,1,0,0,1,1,0,0,1,0,1,0,0},
                        {0,1,0,0,1,1,0,0,1,1,1,0,0},
                        {0,0,0,0,0,0,0,0,0,0,1,0,0},
                        {0,0,0,0,0,0,0,1,1,1,1,0,0},
                        {0,0,0,0,0,0,0,1,1,1,1,0,0}};
    int array1[1][1] = {{0}};

    vector<vector<int>> matrix;
    matrix.reserve(8);
    for (int i = 0; i < 8; ++i)
    {
        vector<int> row;
        row.reserve(13);
        for (int j = 0; j < 13; ++j)
        {
            cout << array[i][j] << " ";
            row.push_back(array[i][j]);
        }
        cout << endl;
        matrix.push_back(row);
    }

    vector<int> row;
    row.push_back(0);
    vector<vector<int>> matrix1;
    matrix1.push_back(row);

    cout << "The max area of is land is: " <<  maxAreaOfIsland(matrix) << endl;
}
