#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;

    while(n--){
        deque<int> dq;
        string str;
        bool isTrue = true;
        bool isDir = true; // true면 정방향 , false면 역방향
        char ch;
        int a;
        cin >> str >> a;
        cin >> ch;
        for(int i=0;i<a;i++){
            int k;
            cin >> k;
            dq.push_back(k);
            if(i!=a-1){
                cin >> ch;
            }
        }
        cin >> ch;
        for(int i=0;str[i]!='\0';i++){
            if(str[i] == 'R'){
                isDir = !isDir; //방향 바꾸기
            }else{ //str[i] == 'D'
                if(dq.empty()){
                    isTrue = false;
                    break;
                }
                if(isDir) //정방향
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }
        if(isTrue){
            cout << '[';
            if(isDir){
                while(!dq.empty()){
                    cout << dq.front();
                    if(dq.size() == 1)
                        break;
                    else
                        cout << ',';
                    dq.pop_front();
                }
            }else{
                while(!dq.empty()){
                    cout << dq.back();
                    if(dq.size() == 1)
                        break;
                    else
                        cout << ',';
                    dq.pop_back();
                }
            }
            cout << "]\n";
        }else{
            cout << "error\n";
        }
    }
}