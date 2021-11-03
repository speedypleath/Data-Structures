#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream in("paranteze.in");
ofstream out("paranteze.out");
int n;
stack<pair<char,int>> s;
bool deschis(char c)
{
    if(c=='{'||c=='('||c=='[')
        return 1;
    return 0;
}
bool corect(char c)
{
    if(s.top().first=='{')
        return c=='}';
    else if(s.top().first=='[')
        return c==']';
    else if(s.top().first=='(')
        return c==')';
    return 0;
}
int main()
{
    in>>n;
    int mx=0;
    char c;
    s.push(make_pair('a',0));
    for(int i=1;i<=n;i++){
        in>>c;
        if(corect(c)&&!deschis(c)){
            s.pop();
            mx = max(mx,i-s.top().second);
        }
        else
            s.push(make_pair(c,i));
    }
    out<<mx;
    return 0;
}
