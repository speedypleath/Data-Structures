#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i;
    string st,sol;
    cin>>n;
    cin>>st;
    for(i=0;i<n;i++){
        if(st[i]!='1'&&st[i]!='0')
        switch(st[i]){
        case '4':
        {
            sol += "322";
            break;
        }
        case '6':
        {
            sol += "53";
            break;
        }
        case '8':
        {
            sol += "7222";
            break;
        }
        case '9':
        {
            sol += "7332";
            break;
        }
        default:
            sol += st[i];
    }
    }
    sort(sol.begin(),sol.end(),greater<char>());
    cout<<sol<<endl;

    return 0;
}
