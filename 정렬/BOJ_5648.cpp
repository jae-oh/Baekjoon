#include <bits/stdc++.h>
using namespace std;

//string으로 받아서 string STL안에 있는 reverse함수를 써서도 가능

int n;
long long arr1[1000005],arr2[1000005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr1[i];
    }

    for(int i=0;i<n;i++){
        int cnt=0;
        while(arr1[i]%10 == 0){
            arr1[i] /= 10;
        }
        arr2[i] = arr1[i];
        while(arr1[i] > 0){
            arr1[i] /= 10;
            cnt++;
        }
        cnt--;
        while(cnt >=0){
            arr1[i] += (arr2[i]%10)*pow(10,cnt);
            cnt--;
            arr2[i] /= 10;
        }
    }

    sort(arr1,arr1+n);
    for(int i=0;i<n;i++)
        cout << arr1[i] << '\n';
}