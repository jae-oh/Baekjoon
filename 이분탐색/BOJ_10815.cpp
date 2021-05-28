#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[500005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    sort(arr,arr+n);//항상 이분탐색 전에는 오름차순으로 정렬을 해주어야 한다!!

    cin >> m;

    while(m--){
        int target;
        cin >> target;

        if(binary_search(arr,arr+n,target))
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }
}