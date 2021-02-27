#include <bits/stdc++.h>

using namespace std;

//STL list는 환형 연결리스트를 제공하지 않는다. 그러므로 마지막일 때, 처음 노드로 가도록 만들어줘야한다.
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    list<int> L;
    int n,k; // n : 순열 길이, k : k번째 사람제거

    cin >> n >> k;

    for(int i=1;i<n+1;i++){
        L.push_back(i);
    }

    list<int>::iterator t = L.begin();

    while(!L.empty()){
        for(int i =0 ;i<k-1;i++){ //k-1로 하는 이유는 node1에서 k-1이동해야 node3이 되기때문에
            if(t == L.end())
                t = L.begin();
            t++;
        }
        cout << *t << ' '; //t가 가리키는 값 출력
        t=L.erase(t);
    }

    for(auto i : L)
        cout << i << ' ';

    return 0;
}