#include <bits/stdc++.h>
using namespace std;

int n,m,st,en;
int arr[100005];

int BinarySearch(int target, int len);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n);
    
    cin >> m;

    while(m--){
        int a;
        cin >> a;

        cout << BinarySearch(a,n) << '\n';
    }
}

int BinarySearch(int target, int len){
    int st = 0;
    int en = len -1;

    while(st <= en){
        int mid = (st+en)/2;
        if(arr[mid] == target) return 1;
        else if(arr[mid] > target) en = mid-1;
        else st = mid+1; //
    }
    return 0;
}