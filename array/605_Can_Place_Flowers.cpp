
#include <iostream>
#include <vector>



using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    int counts = 0;
    flowerbed.push_back(0);
    for (int i = 0; i < flowerbed.size()-1;)
    {
        if(flowerbed[i]==1)
            i+=2;
        else if(flowerbed[i] == 0 && flowerbed[i+1] == 0)
        {
            cout << "i = "  << i << endl;
            counts++;
            i+=2;
        } else
        {
            i+=3;
        }
    }
    flowerbed.pop_back();
    return n <= counts;
}


int main()
{
    vector<int> flowerbed({0,0,1,0,0,0});
    cout << canPlaceFlowers(flowerbed, 2) << endl;

    return 0;
}