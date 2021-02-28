#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x; //명령어 개수, push할 원소 값
    string c; //명령어
    queue<int> q;

    cin >> n;

    for(int i=0; i<n ;i++){
        cin >> c;

        if(c == "push"){
            cin >> x;
            q.push(x);
            continue;
        }else if(c == "pop"){
            if(q.empty()){ //Queue가 비어있을 때, pop이나 front,back을 해주면 error가 난다.
                cout << -1 << "\n";
                continue;
            }
            cout << q.front();
            q.pop();
        }else if(c == "size"){
            cout << q.size();
        }else if(c == "empty"){
            cout << q.empty();
        }else if(c == "front"){
            if(q.empty()){
                cout << -1 << "\n";
                continue;
            }
            cout << q.front();
        }else if(c == "back"){
            if(q.empty()){
                cout << -1 << "\n";
                continue;
            }
            cout << q.back();
        }else{
            break;
        }
        cout << "\n";
    }

}