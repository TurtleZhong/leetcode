#include <iostream>
#include <vector>
#include <string>

using namespace std;


long** Solve(long N, long M, int map_size_row, int map_size_cols, long** map, int* result_size_rows, int* result_size_cols)
{
    vector<vector<long>> map_dp;

    for (int i = 0; i < map_size_row; ++i)
    {
        vector<long> map_dp_row;
        map_dp_row.reserve(map_size_cols);
        for (int j = 0; j <map_size_cols ; ++j)
        {
            map_dp_row.push_back(map[i][j]);
        }
        map_dp.push_back(map_dp_row);
    }
    vector<vector<long>> last_map_dp = map_dp;

    for (int k = 0; k < M-1; ++k)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                long min_value = INT32_MAX;
                for (int l = 0; l < N; ++l)
                {
                    if(l!=i && l!=j)
                    {
                        long tmp = last_map_dp[i][l] + map[l][j];
                        if(tmp < min_value)
                            min_value = tmp;
                    }

                }
                map_dp[i][j] = min_value;
            }
        }
        last_map_dp = map_dp;
    }

    long **result = new long*[N];
    for (int m = 0; m < map_dp.size(); ++m)
    {
        for (int i = 0; i < map_dp[0].size(); ++i)
        {
            result[m][i] = map_dp[m][i];
        }
    }
    *result_size_rows = map_size_row;
    *result_size_cols = map_size_cols;

    return result;
}


int main()
{
    int res_size_rows, res_size_cols;
    long** res;

    long _N;
    scanf("%ld", &_N);
    long _M;
    scanf("%ld", &_M);
    int _map_rows = 0;
    int _map_cols = 0;
    scanf("%d", &_map_rows);
    scanf("%d", &_map_cols);

    long** _map = (long**)malloc(_map_rows*sizeof(long*));
    int _map_init_i=0;
    for(_map_init_i=0 ; _map_init_i<_map_rows ; ++_map_init_i)
    {
        _map[_map_init_i] = (long*)malloc(_map_cols*(sizeof(long)));
    }

    int _map_i, _map_j;
    for(_map_i = 0; _map_i < _map_rows; _map_i++) {
        for(_map_j = 0; _map_j < _map_cols; _map_j++) {
            long _map_item;
            scanf("%ld", &_map_item);

            _map[_map_i][_map_j] = _map_item;
        }
    }

    res = Solve(_N, _M, _map_rows, _map_cols, _map, &res_size_rows, &res_size_cols);
    int res_i, res_j;
    for(res_i = 0; res_i < res_size_rows; res_i++) {
        for(res_j = 0; res_j < res_size_cols; res_j++) {
            printf("%ld ", res[res_i][res_j]);
        }
        printf("\n");
    }

    return 0;
}
