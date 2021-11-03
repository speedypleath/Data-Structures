
#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100005];
long long d[2][100005];

stack <pair <long long, long long> > st;

int main()
{
    freopen("ksecv.in", "r", stdin);
    freopen("ksecv.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n ; ++i) scanf("%d", &a[i]);

    int Max = 0;
    for(int i = 1; i <= n ; ++i){
        Max = max(Max, a[i]);
        d[1][i] = Max;
    }
    for(int j = 2; j <= k ; ++j){
        int l = j & 1;

        for(int i = j; i <= n ; ++i){
            long long Min = d[1 - l][i - 1];

            while(!st.empty() && st.top().second <= a[i]){
                Min = min(Min, st.top().first);
                st.pop();
            }

            if(st.empty() || st.top().first + st.top().second >= Min + a[i]) st.push({Min, a[i]});

            d[l][i] = st.top().first + st.top().second;
        }
        while(!st.empty()) st.pop();
    }

    printf("%lld", d[k & 1][n]);



    return 0;
}
