#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    string c;
    deque<int> D;

    cin >> n;

    while(n--){
        cin >> c;
        if(c == "push_front"){
            cin >> x;
            D.push_front(x);
        }else if(c == "push_back"){
            cin >> x;
            D.push_back(x);
        }else if(c == "pop_front"){
            if(D.empty()){
                cout << "-1\n";
                continue;
            }
            cout << D.front() << "\n";
            D.pop_front();
        }else if(c == "pop_back"){
            if(D.empty()){
                cout << "-1\n";
                continue;
            }
            cout << D.back() << "\n";
            D.pop_back();
        }else if(c == "size"){
            cout << D.size() << "\n";
        }else if(c == "empty"){
            cout << D.empty() << "\n";
        }else if(c == "front"){
            if(D.empty()){
                cout << "-1\n";
                continue;
            }
            cout << D.front() << "\n";
        }else if(c == "back"){
            if(D.empty()){
                cout << "-1\n";
                continue;
            }
            cout << D.back() << "\n";
        }else{
            break;
        }
    }
}