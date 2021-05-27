#include <bits/stdc++.h>
using namespace std;

int n,m,start,last;
int arr[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    start = 0;
    last = n;

    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n);
    
    cin >> m;

    while(m--){
        int a;
        int mid = (start+last)/2;
        cin >> a;

        while(1){
            if(a == arr[mid]){
                cout << 1 << '\n';
                break;
            }else if(a > arr[mid]){
                start = mid+1;
            }else{ // a < arr[mid]
                last = mid-1;
            }

            if(start == last){
                cout << 0 << '\n';
                break;
            }
        }
    }
}