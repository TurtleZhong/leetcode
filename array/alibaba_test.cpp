/**
 * 阿里巴巴诸葛八卦阵兵力最大最小题（深度优先搜索）
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

/**
 * Input:
 * 4
 * 4
 * 1 2 3 0
 * 2 3 0 0
 * 0 0 0 1
 * 19 0 0 1
 *
 * output:
 * 19
 * 2
 */


using namespace std;

bool inBorder(const int &x, const int &y, int rows, int cols)
{
    if(x >= 0 && x <= rows -1 && y >=0 && y <= cols-1)
        return true;
    else
        return false;
}


vector<int> getMilitaryStrength(const vector<vector<int>> &grid)
{
    vector<int> results(2);
    vector<int> nums;
    int rows = grid.size();
    int cols = grid[0].size();

    int grid_label[rows][cols];
    for (int k = 0; k < rows; ++k)
    {
        for (int i = 0; i < cols; ++i)
        {
            grid_label[k][i] = 0;
        }
    }
    int label = -1;


    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            int sum = 0;
            if(grid[i][j] > 0 && grid_label[i][j] == 0) //! which means have num
            {

                stack<pair<int,int>> neighbors;
                neighbors.push(pair<int,int>(i,j));
                label--;

                while(!neighbors.empty())
                {
                    pair<int,int> curr = neighbors.top();
                    int x = curr.first;
                    int y = curr.second;
                    sum+= grid[x][y];
//                    cout << "x = " << x << " y = " << y << endl;
                    grid_label[x][y] = label;
                    neighbors.pop();

                    if(inBorder(x-1,y-1,rows,cols) && grid[x-1][y-1] > 0 && grid_label[x-1][y-1] == 0 )
                    {
                        neighbors.push(pair<int,int>(x-1,y-1));
                        grid_label[x-1][y-1] = label;
                    }
                    if(inBorder(x-1,y,rows,cols) && grid[x-1][y] > 0 && grid_label[x-1][y] == 0 )
                    {
                        neighbors.push(pair<int,int>(x-1,y));
                        grid_label[x-1][y] = label;
                    }
                    if(inBorder(x-1,y+1,rows,cols) && grid[x-1][y+1] > 0 && grid_label[x-1][y+1] == 0 )
                    {
                        neighbors.push(pair<int,int>(x-1,y+1));
                        grid_label[x-1][y+1] = label;
                    }
                    if(inBorder(x,y-1,rows,cols) && grid[x][y-1] > 0 && grid_label[x][y-1] == 0 )
                    {
                        neighbors.push(pair<int,int>(x,y-1));
                        grid_label[x][y-1] = label;
                    }
                    if(inBorder(x,y+1,rows,cols) && grid[x][y+1] > 0 && grid_label[x][y+1] == 0 )
                    {
                        neighbors.push(pair<int,int>(x,y+1));
                        grid_label[x][y+1] = label;
                    }
                    if(inBorder(x+1,y+1,rows,cols) && grid[x+1][y+1] > 0 && grid_label[x+1][y+1] == 0 )
                    {
                        neighbors.push(pair<int,int>(x+1,y+1));
                        grid_label[x+1][y+1] = label;
                    }
                    if(inBorder(x+1,y,rows,cols) && grid[x+1][y] > 0 && grid_label[x+1][y] == 0 )
                    {
                        neighbors.push(pair<int,int>(x+1,y));
                        grid_label[x+1][y] = label;
                    }
                    if(inBorder(x+1,y-1,rows,cols) && grid[x+1][y-1] > 0 && grid_label[x+1][y-1] == 0 )
                    {
                        neighbors.push(pair<int,int>(x+1,y-1));
                        grid_label[x+1][y-1] = label;
                    }

                }
                nums.push_back(sum);
//                cout << sum << endl;
            }

        }
    }
    sort(nums.begin(),nums.end());
    results[0] = nums[nums.size()-1];
    results[1] = nums[0];
    return results;
}

int main()
{
    int res_size;
    int* res;

    int _A_rows = 0;
    int _A_cols = 0;
    scanf("%d", &_A_rows);
    scanf("%d", &_A_cols);

    int** _A = (int**)malloc(_A_rows*sizeof(int*));
    int _A_init_i=0;
    for(_A_init_i=0 ; _A_init_i<_A_rows ; ++_A_init_i)
    {
        _A[_A_init_i] = (int*)malloc(_A_cols*(sizeof(int)));
    }

    int _A_i, _A_j;
    for(_A_i = 0; _A_i < _A_rows; _A_i++) {
        for(_A_j = 0; _A_j < _A_cols; _A_j++) {
            int _A_item;
            scanf("%d", &_A_item);

            _A[_A_i][_A_j] = _A_item;
        }
    }
    /**
     * change to vector
     */
    vector<vector<int>> grid;

    for (int i = 0; i < _A_rows; ++i)
    {
        vector<int> each_rows(_A_cols);
        for (int j = 0; j < _A_cols; ++j)
        {
            each_rows[j] = _A[i][j];
        }
        grid.push_back(each_rows);
        each_rows.clear();
    }

//    for (int l = 0; l < grid.size(); ++l)
//    {
//        for (int i = 0; i < grid[0].size(); ++i)
//        {
//            cout << grid[l][i] << " ";
//        }
//    }
//    cout << endl;

    vector<int> results;
    results = getMilitaryStrength(grid);
    for (int k = 0; k < results.size(); ++k)
    {
        cout << results[k] << endl;
    }

    return 0;
}