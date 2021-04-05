#include <bits/stdc++.h>
using namespace std;

//stack에는 현재보다 높거나 같은 탑을 남기고 현재 탑을 push한다. 만약에 현재 탑보다 작다면 그 다음올 탑들은 현재 탑에서 수신을 받기 때문이다.

int n;
int top[500005];
stack<pair<int,int>> s; // {top길이,index}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        if(s.empty()){ //이전 탑들에서는 현재보다 높거나 같은 길이의 탑이 없다는 뜻
            s.push({k,i});
            cout << '0' << ' ';
        }else if(k > s.top().first){ //현재 탑이 stack top보다 높을 경우
            while(!s.empty()){
                if(k > s.top().first) //stack에서 현재 탑보다 작은 탑이 나올 때까지 pop
                    s.pop();
                else{ //stack에서 현재 탑보다 높거나 같은 탑이 나올경우, 그 탑의 index 출력
                    cout << s.top().second << ' ';
                    break;
                }
            }
            if(s.empty())
                cout << '0' << ' ';
            s.push({k,i}); // 현재 탑 push (뒤에 탑은 현재 탑보다 작을 수 있기 때문에)
        }else{ // k < s.top().first , 현재 탑보다 높거나 같을 경우
            cout << s.top().second << ' ';
            s.push({k,i}); // 현재 탑 push (뒤에 탑은 현재 탑보다 작을 수 있기 때문에)
        }
    }
}