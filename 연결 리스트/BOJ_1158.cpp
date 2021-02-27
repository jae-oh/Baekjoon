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
    cout << '<' ;
    while(!L.empty()){
        for(int i=0;i<k-1;i++){ //k-1로 하는 이유는 node1에서 k-1이동해야 node3이 되기때문에
            if(t == L.end())
                t = L.begin();
            t++;
            //list에 남아있는 원소가 1개였을 때 한번 ++했을 때에도 list.end일 수 있다. 그래서 뒤에 cout<<*t 구문 혹은 t=L.erase(t) 에서 없는데 출력/없는데 제거하라고 하니 오류가 난다.
            if(t == L.end())
                t = L.begin();
        }
        if(L.size() == 1){
            cout << *t;
            break;
        }
        cout << *t << ", "; //t가 가리키는 값 출력
        t = L.erase(t);
        
    }
    cout << '>' ;

    return 0;
}