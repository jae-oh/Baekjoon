#include <bits/stdc++.h>
using namespace std;

int testN;
int dp_0[50],dp_1[50];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> testN;

    dp_0[0] = 1;
    dp_0[1] = 0;
    dp_1[0] = 0;
    dp_1[1] = 1;

    for(int i=2;i<41;i++){
        dp_0[i] =dp_0[i-1] + dp_0[i-2];
        dp_1[i] =dp_1[i-1] + dp_1[i-2];
    }

    while(testN--){
        int n;
        cin >> n;

        cout << dp_0[n] << ' ' << dp_1[n] << '\n';

    }
}