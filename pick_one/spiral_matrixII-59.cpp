//
// Created by m on 3/26/19.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    if( n == 0 )    {
        vector<vector<int> > ans;
        return ans;
    }
    vector<vector<int> > ans(n, vector<int>(n, 0));
    int row = -1,col = -1,num = 1,direction = 2;
    while( num <= n * n )
        switch( direction ) {
            case 2:
            {
                row++;
                col++;
                while( col < n && ans[row][col] == 0 )
                    ans[row][col++] = num++;
                direction = 3;
                break;
            }
            case 3:
            {
                col--;
                row++;
                while( row < n && ans[row][col] == 0 )
                    ans[row++][col] = num++;
                direction = 4;
                break;
            }
            case 4:
            {
                row--;
                col--;
                while( col >= 0 && ans[row][col] == 0 )
                    ans[row][col--] = num++;
                direction = 1;
            }
                break;
            case 1:;
                {
                    col++;
                    row--;
                    while( row >= 0 && ans[row][col] == 0 )
                        ans[row--][col] = num++;
                    direction = 2;
                }
                break;
            default:
                break;
        }
    return ans;
}


int main()
{
    vector<vector<int>> result = generateMatrix(4);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << result[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}