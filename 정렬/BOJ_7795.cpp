#include <bits/stdc++.h>
using namespace std;

int n;
int arr1[20005],arr2[20005];

bool cmp(const int a,const int b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(n--){
        int n,m,cnt=0;

        cin >> n >> m;
        fill(arr1,arr1+n,0);
        fill(arr2,arr2+m,0);
        
        for(int i=0;i<n;i++)
            cin >> arr1[i];

        for(int i=0;i<m;i++)
            cin >> arr2[i];
        
        sort(arr1,arr1+n,cmp);
        sort(arr2,arr2+m,cmp);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr1[i] > arr2[j]){
                    cnt += m-j;
                    break;
                }
            }
        }

        cout << cnt << '\n';
    }
}

bool cmp(const int a,const int b){
    if(a > b) return true;
    else return false;
}