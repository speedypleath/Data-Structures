#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream in("curatenie.in");
ofstream out("curatenie.out");
vector<pair<int,int>> sol;
int mp[500000];
int tree(int srd[], int rsd[], int first, int last)
{
    static int i = 0;
    if (first > last)
        return 0;
    int cur = rsd[i++];
    if (first == last)
        return cur;
    int j = mp[cur];
    sol[cur-1].first = tree(srd, rsd, first, j - 1);
    sol[cur-1].second = tree(srd, rsd, j + 1, last);
    return cur;
}
int main()
{
    int n;
    in>>n;
    int rsd[n],srd[n];
    sol.resize(n);
    for(int i=0;i<n;i++){
        in>>srd[i];
        mp[srd[i]] = i;
    }
    for(int i=0;i<n;i++)
        in>>rsd[i];
    tree(srd, rsd, 0, n - 1);
    for(auto x:sol)
        out<<x.first<<' '<<x.second<<endl;
    return 0;
}
