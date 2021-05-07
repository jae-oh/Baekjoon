#include <bits/stdc++.h>
using namespace std;

long long n,m,ans=0;
long long arr[1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m; //n은 카드 개수 , m은 합체 수
    for(int i=0;i<n;i++)
        cin >> arr[i];

    while(m--){
        long long a;
        sort(arr,arr+n);
        a = arr[0] + arr[1];
        arr[0] = a;
        arr[1] = a;
    }

    for(int i=0;i<n;i++){
        ans += arr[i];
    }

    cout << ans;
}