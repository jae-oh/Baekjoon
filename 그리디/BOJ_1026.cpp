#include <bits/stdc++.h>
using namespace std;

int n;
int arr1[51],arr2[51];

bool cmp(int a,int b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr1[i];
    for(int i=0;i<n;i++)
        cin >> arr2[i];
    sort(arr1,arr1+n);
    sort(arr2,arr2+n,cmp);
    int ans=0;
    for(int i=0;i<n;i++)
        ans += arr1[i]*arr2[i];
    cout << ans;
}

bool cmp(int a,int b){
    return a>b;
}

