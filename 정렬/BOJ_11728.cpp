#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr1[1000001];
int arr2[1000001];
int ans[2000001];
int idx1,idx2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> arr1[i];
    }

    for(int i=0;i<m;i++){
        cin >> arr2[i];
    }

    for(int i=0;i<n+m;i++){
        if(idx1 > n-1){
            for(int j=idx2;j<m;j++){
                ans[i++] = arr2[j];
            }
            break;
        }
        if(idx2 > m-1){
            for(int j=idx1;j<n;j++){
                ans[i++] = arr1[j];
            }
        }
        if(arr1[idx1] > arr2[idx2]){
            ans[i] = arr2[idx2++];
        }else{ //Merge sort는 stable sort이기 때문에, 가능하다면 값이 같을 때는 처음 arr의 원소가 먼저 들어가는 것으로 구현하는게 좋다.
            ans[i] = arr1[idx1++];
        }
    }

    for(int i=0;i<n+m;i++)
        cout << ans[i] << ' ';
}