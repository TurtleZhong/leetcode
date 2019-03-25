#include <iostream>
#include <map>
#include <vector>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Core>

using namespace std;

int main()
{

    double tx = 0.01;
    double ty = 0.02;
    Eigen::Vector2d x(tx, tx);
    Eigen::Vector2d y(ty, ty);
    Eigen::Matrix2d A;
    A << x,y;
    cout << "A = \n" << A << endl;



    int N;
    cin >> N;
    int normal= 0;
    int guai = 1;
    map<int,vector<int>> hash_map;
    for (int i = 0; i < N; ++i)
    {
        int t,x;
        cin >> t >> x;
        if(t == 1 && x ==1)
        {
            guai++;
        }
        if(x-1 == i && t==2)
            guai++;
        if(hash_map.count(x))
        {
            vector<int> &values = hash_map[x];
            values.push_back(t-1);
        }
        else
        {
            vector<int> values;
            values.push_back(t-1);
            hash_map[x]=values;
        }
    }

    cout << normal << " " << guai << endl;
    return 0;
}