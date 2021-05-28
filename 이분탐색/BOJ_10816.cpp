#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[500005];

int binarySearch(int target,int len);
int lowerBound(int target,int len); // target하고 같은 값 중 가장 작은 인덱스
int upperBound(int target,int len); // target하고 같은 값 중 가장 큰 인덱스

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> m;

    sort(arr,arr+n);

    while(m--){
        int target;
        cin >> target;

        if(arr[lowerBound(target,n)] == target){
            cout << upperBound(target,n) - lowerBound(target,n) << ' ';
        }else cout << 0 << ' ';
    }
}

int binarySearch(int target,int len){
    int st=0;
    int en=len-1;

    while(st <= en){
        int mid = (st+en)/2;
        
        if(arr[mid] == target) return 1;
        else if(arr[mid] > target) en = mid-1;
        else st = mid+1;
    }
    return 0;
}

/*
주의 사항 : 밑에 lowerBound, upperBound함수는 증가수열에서 모순이 생기지 않게 왼쪽에 삽입하는 함수이다.
#여기서 오른쪽에 삽입하는 함수를 구현할려면
1)mid = (st+en+1)/2
2)if(arr[mid] >= target) st = mid;
3)else en = mid-1;
로 바꾸어 주어야 한다.
*/

int lowerBound(int target,int len){
    int st=0;
    int en=len; //en이 len-1이 아닌 이유는 만약 arr안의 모든 값보다 더 큰 값이 들어오면 len에 삽입시켜야 모순이 안일어나기 때문이다.

    while(st < en){ // st와 en이 같을 때, 그 값이 target과 같으면 target과 같은 값 중 가장 작은 인덱스를 가지고, target과 다르면 아무것도 아니다.
        int mid = (st+en)/2;

        if(arr[mid] >= target) en = mid;
        else st = mid+1;
    }
    return st; //st와 en이 같아지면 return;
}

int upperBound(int target,int len){
    int st=0;
    int en=len;

    while(st < en){ // st와 en이 같을 때, 그 값이 target과 같으면 target과 같은 값 중 가장 큰 인덱스를 가지고, target과 다르면 아무것도 아니다.
        int mid = (st+en)/2;

        if(arr[mid] > target) en = mid;
        else st = mid+1;
    }
    return st; //st와 en이 같아지면 return;
}
