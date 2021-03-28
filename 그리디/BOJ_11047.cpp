#include <bits/stdc++.h>
using namespace std;

int n,k,cnt=0;
int coin[20];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> coin[i];
    for(int i=n-1;i>=0;i--){
        while(k>=coin[i]){
            k -= coin[i];
            cnt++;
        }
        if(k==0)
            break;
    }
    cout << cnt;
}