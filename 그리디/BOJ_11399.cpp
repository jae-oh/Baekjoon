#include <bits/stdc++.h>
using namespace std;

/*
#걸리는 시간이 짧은 사람이 앞 순서로 가야한다.
*/

int n,cnt=0,ans=0;
int arr[1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        cnt += arr[i];
        ans += cnt;
    }
    cout << ans;
}