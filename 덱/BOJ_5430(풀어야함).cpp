#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;

    while(n--){
        deque<int> dq;
        deque<int>::iterator iter1,iter2;
        string str;
        bool isTrue = true;
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

        for(int i=0;i<str.size();i++){
            if(str[i] == 'R'){
                
            }else{ //str[i] == 'D'
                if(dq.empty()){
                    isTrue = false;
                    break;
                }
                dq.pop_front();
            }
        }
        if(isTrue){
            cout << '[';
            for(int i=0;i<dq.size();i++){
                cout << dq[i];
                if(i==dq.size()-1) break;
                else cout << ',';
            }
            cout << "]\n";
        }else{
            cout << "error\n";
        }
    }
}