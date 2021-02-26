#include <bits/stdc++.h>

using namespace std;

int func2(int arr[], int n){
    for(int i = 0 ; i<n;i++){
        for(int j=i+1 ; j<n ;j++){
            if(arr[i] + arr[j] == 100)
                return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr1[3] = {1,52,48};
    int arr2[2] = {50,42};
    int arr3[4] = {4,13,63,87};

    cout << func2(arr1,3) << "\n";
    cout << func2(arr2,2) << "\n";
    cout << func2(arr3,4) << "\n";
}

/*
바킹독 풀이
-시간복잡도가 내가 짠 코드는 O(n의 제곱)이지만, 이 풀이는 O(n)이 걸린다

int freq[101]; //더해지면 100이 되는 수가 있는지 확인하는 배열 (전역으로 선언해서 0으로 자동 초기화)
int func2(int arr[], int n){
    for(int i=0 ; i<n ;i++){
        if(freq[100-arr[i]]) //freq배열의 100-arr[i] 인덱스가 1이라면 더해지면 100이 되는 수가 있다는 말이니까 1을 반환
            return 1;
        freq[arr[i]] = 1;
    }
    return 0;
}

*/ 