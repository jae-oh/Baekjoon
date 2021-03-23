#include <bits/stdc++.h>
using namespace std;

int n,idx=0;
int freq[2000005];
int arr[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        if(temp >= 0)
            freq[temp]++;
        else
            freq[1000000+abs(temp)]++;
    }

    for(int i=2000004;i>1000000;i--)
        if(freq[i])
            for(int j=0;j<freq[i];j++)
                arr[idx++] = 1000000-i;
    for(int i=0;i<=1000000;i++)
        if(freq[i])
            for(int j=0;j<freq[i];j++)
                arr[idx++] = i;
 
    for(int i=0;i<n;i++)
        cout << arr[i] << '\n';
}