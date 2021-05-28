#include <bits/stdc++.h>
using namespace std;

int n,m,cnt=0;
vector<int> v;
int arr[500005],vis[500005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);

    while(m--){
        int target;
        cin >> target;

        if(binary_search(arr,arr+n,target)){
            cnt++;
            vis[lower_bound(arr,arr+n,target) -arr] = 1;
        }
    }
    if(n == cnt)
        cout << 0;
    else{
        cout << n - cnt << '\n';
        for(int i=0;i<n;i++)
            if(!vis[i])
                cout << arr[i] << ' ';
    }
    
}