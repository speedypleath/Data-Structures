#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream in("ksecv.in");
ofstream out("ksecv.out");
vector<vector<int>> m;
vector<int> v;
stack<pair<int,int>> s;
int n,k;
int main()
{
    in>>n>>k;
    v.resize(n);
    m.resize(2);
    m[0].resize(n);
    m[1].resize(n);
    in>>v[0];
    m[0][0] = v[0];
    for(int i=1;i<n;i++){
        in>>v[i];
        m[0][i] = max(v[i],m[0][i-1]);
    }
    int mx;
    for(int i=1;i<k;i++){
        fill(m[i&1].begin(), m[i&1].end(), 10000000);
        for(int j=i;j<n;j++){
            int mn = m[(i-1)&1][j-1];
            while(!s.empty()&&(s.top().second<=v[j])){
                mn = min(mn, s.top().first);
                s.pop();
            }
            if(s.empty()||(s.top().first+s.top().second>=mn+v[j]))
                s.push(make_pair(mn,v[j]));
            m[i&1][j] = s.top().first+s.top().second;
        }
        while(!s.empty())
            s.pop();
    }
    out<<m[(k-1)&1][n-1];
    return 0;
}
