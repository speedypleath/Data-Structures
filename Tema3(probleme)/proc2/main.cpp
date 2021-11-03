#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream in("proc2.in");
ofstream out("proc2.out");
int main()
{
    int n,m;
    priority_queue<int,vector<int>,greater<int>> go;
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> wait;
    in>>n>>m;
    for(int i=1;i<=n;i++)
        go.push(i);
    for (int i=0;i<m;i++){
        int a,b;
        in>>a>>b;
        while(!wait.empty() && wait.top().first<=a){
            pair<int,int> x = wait.top();
            wait.pop();
            go.push(x.second);
        }
        int x = go.top();
        go.pop();
        out <<x<<'\n';
        wait.push(make_pair(a+b,x));
    }
    return 0;
}
