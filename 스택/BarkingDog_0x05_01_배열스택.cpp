#include <bits/stdc++.h>

using namespace std;

//배열을 이용해서 스택을 만들 때에는 pos라는 인덱스는 마지막값 한단계 위를 가리키고 있어야 한다.

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x);
void pop();
int top();
void test();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    return 0;
}

void push(int x){
    dat[pos++] = x;
}

void pop(){
    pos--;
}

int top(){
    return dat[pos-1];
}

void test(){
    push(5); push(4); push(3);
    cout << top() << '\n'; // 3
    pop(); pop();
    cout << top() << '\n'; // 5
    push(10); push(12);
    cout << top() << '\n'; // 12
    pop();
    cout << top() << '\n'; // 10
}