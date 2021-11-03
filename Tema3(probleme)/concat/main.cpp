
#include <bits/stdc++.h>
using namespace std;

bool comp(string a,string b)
{
    return a+b<b+a;
}
string largestConcat(vector<string>& v) {
    sort(v.begin(),v.end(),comp);
    string sol="";
    if(v[0]=="0")
        return "0";
    for(auto it:v)
        sol+=it;
    return sol;
}

int main() {
    int N;
    vector<string> v;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        string number;
        cin >> number;
        v.push_back(number);
    }
    cout << largestConcat(v) << "\n";
    return 0;
}

