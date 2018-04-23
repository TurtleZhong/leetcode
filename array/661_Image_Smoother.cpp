/**
 * Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray
 * scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself.
 * If a cell has less than 8 surrounding cells, then use as many as you can.
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& M)
{
    if(M.empty())
        return vector<vector<int>>();
    vector<vector<int>> result(M.size(), vector<int>(M[0].size(), 0));
    vector<pair<int,int>> filter_index({{-1,-1}, {0,-1}, {1,-1}, {-1,0}, {0,0}, {1,0}, {-1,1}, {0,1}, {1,1}});
    for (int i = 0; i < M.size(); ++i)
    {
        for (int j = 0; j < M[0].size(); ++j)
        {
            int sum = 0;
            int count = 0;
            for (auto index: filter_index)
            {
                int ii = i + index.first;
                int jj = j + index.second;
                if(ii >=0 && ii < M.size() && jj >= 0 && jj < M[0].size())
                {
                    sum+= M[ii][jj];
                    count++;
                }
            }
            result[i][j] = sum / count;
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> M({{1, 3, 1}, {1, 0, 1}, {1, 1, 1}});
    cout << M.size() << M[0].size() << endl;
    vector<vector<int>> result = imageSmoother(M);
    for (auto rows:result)
    {
        for (int i = 0; i < rows.size(); ++i)
        {
            cout << rows[i] << " ";
        }
        cout << endl;
    }
    return 0;
}