//
// Created by m on 9/21/18.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin>>t;
    vector<string> str_buff;
    for (int i = 0; i < t; ++i)
    {
        string tmp;
        cin >> tmp;
        str_buff.push_back(tmp);
    }

    vector<int> results;
    results.reserve(t);
    for (int j = 0; j < t; ++j)
    {
        string &x = str_buff[j];

        int l=0,r=x.length()-1;
        int minn=100000000;
        while(l<r){
            if(x[l]!=x[r]){
                if(x[l+1]==x[r]){
                    int u=0;
                    int p=l+1,q=r;
                    while(p<q){
                        if(x[p]!=x[q]){
                            u=1;
                            break;
                        }
                        p++;
                        q--;
                    }
                    if(u==0){
                        p=l;
                        while(p-1>=0&&x[p-1]==x[p])
                            p--;
                        minn=min(minn,p);
                    }
                }
                if(x[l]==x[r-1]){
                    int u=0;
                    int p=l,q=r-1;
                    while(p<q){
                        if(x[p]!=x[q]){
                            u=1;
                            break;
                        }
                        p++;
                        q--;
                    }
                    if(u==0)
                        minn=min(minn,r);
                }
                break;
            }
            l++;
            r--;
        }
        if(minn==100000000)
        {
            results.push_back(-1);
        }
        else
        {
            results.push_back(minn);
        }

    }

    for (int k = 0; k < results.size(); ++k)
    {
        cout << results[k] << endl;
    }
    return 0;
}