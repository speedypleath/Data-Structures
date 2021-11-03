#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream in("timbre.in");
ofstream out("timbre.out");
int main()
{
    int n,m,k;
    in>>n>>m>>k;
    vector<pair<int,int>> interval;
    interval.resize(m);
    for(int i=0;i<m;i++)
        in>>interval[i].first>>interval[i].second;
    sort(interval.begin(),interval.end(),greater<pair<int,int>>());
    priority_queue<int, vector<int>, std::greater<int>> c;
    int n2=n,sum=0,i=0;
    while(n2>0){
        while(i<m&&interval[i].first>=n2)
            c.push(interval[i++].second);
        n2 -= k;

        sum += c.top();
        c.pop();
    }
    out<<sum;
    return 0;
}
