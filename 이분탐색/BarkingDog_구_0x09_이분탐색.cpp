#include <bits/stdc++.h>
using namespace std;

/*
1)binary_search(범위 처음,범위 끝+1,찾으려는 값)
- 찾으려는 값이 있으면 true, 없으면 false로 반환
2)lower_bound(범위 처음,범위 끝+1,찾으려는 값)
- 찾으려는 key값보다 같거나 큰 숫자의 첫 index 반환
3)upper_bound(범위 처음,범위 끝+1,찾으려는 값)
- 찾으려는 key값보다 큰 숫자의 첫 index를 반환

#주의
1)lower_bound,upper_bound함수는 배열이면 포인터, vector면 iterator로 반환된다.
2)그렇기에 인덱스를 얻으려면 배열은 lower_bound() - 배열이름 을 해줘야하고, vector는 lower_bound() - v.begin 을 해줘야한다.
*/

int n;
int arr[8] = {2, 2, 3, 3, 5, 7, 8, 9};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sort(arr,arr+8);

    if(binary_search(arr,arr+8,5))
        cout << "5 in arr\n";
    else
        cout << "5 not in arr\n";
    
    cout << "lower_bound(4) : " << lower_bound(arr,arr+8,10) - arr << '\n'; // 4가 들어갈 index(만약 4가 다수가 있다면 처음 4의 인덱스)
    cout << "upper_bound(9) : " << upper_bound(arr,arr+8,9) - arr; // 6이 들어갈 index(만약 6이 다수가 있다면 마지막 6의 오른쪽 인덱스)
}