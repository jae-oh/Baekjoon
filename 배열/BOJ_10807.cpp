#include <bits/stdc++.h>
using namespace std;

int n,ans,cnt=0;
int arr[105];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> ans;
    for(int i=0;i<n;i++)
        if(arr[i] == ans)
            cnt++;
    cout << cnt;
}   