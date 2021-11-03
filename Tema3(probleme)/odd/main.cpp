#include <iostream>

using namespace std;

int main()
{
    long long int n,k,t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>k;
        if(k*k<=n&&(n+k)%2==0)
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
    return 0;
}
