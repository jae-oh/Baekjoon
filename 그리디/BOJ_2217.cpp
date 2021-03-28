#include <bits/stdc++.h>
using namespace std;

int n,maxi=0;
int arr[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]*(n-i));
    }
    cout << maxi;
}