#include <bits/stdc++.h>

using namespace std;

const int MX = 1000005;
int dat[2*MX+1];
//head와 tail을 모두 MX로 두는 이유 : queue는 인덱스 한쪽방향으로 확장되는데, deque은 양방향에서 삽입과 삽입이 되므로 양방향으로 확장해줘야 해서.
int head = MX, tail = MX; 

void push_front(int x);
void push_back(int x);
void pop_front();
void pop_back();
int front();
int back();
void test();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    test();
}

void push_front(int x){
    dat[--head] = x;
}
void push_back(int x){
    dat[tail++] = x;
}
void pop_front(){
    head++;
}
void pop_back(){
    tail--;
}
int front(){
    return dat[head];
}
int back(){
    return dat[tail-1];
}
void test(){
    push_back(30); // 30
    cout << front() << '\n'; // 30
    cout << back() << '\n'; // 30
    push_front(25); // 25 30
    push_back(12); // 25 30 12
    cout << back() << '\n'; // 12
    push_back(62); // 25 30 12 62
    pop_front(); // 30 12 62
    cout << front() << '\n'; // 30
    pop_front(); // 12 62
    cout << back() << '\n'; // 62
}