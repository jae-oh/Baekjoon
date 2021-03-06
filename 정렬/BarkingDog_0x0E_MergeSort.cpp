#include <bits/stdc++.h>
using namespace std;

//merge sort
//1.stable sort
//2.not in place sorting 알고리즘

int n;
int arr[10000001];
int tmp[10000001];

void merge(int st, int en);
void merge_sort(int st, int en);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    merge_sort(0,n);
    for(int i=0;i<n;i++)
        cout << arr[i] << ' ';
}

void merge(int st, int en){
    int mid = (st+en) / 2;
    int lidx = st;
    int ridx = mid;
    for(int i=st;i<en;i++){
        if(lidx == mid) tmp[i] = arr[ridx++];
        else if(ridx == en) tmp[i] = arr[lidx++];
        else if(arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
        else tmp[i] = arr[ridx++];
    }
    for(int i=st;i<en;i++)
        arr[i] = tmp[i];
}
void merge_sort(int st, int en){
    if(st+1 == en)
        return;
    int mid=(st+en)/2;
    merge_sort(st,mid);
    merge_sort(mid,en);
    merge(st,en);
}