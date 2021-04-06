#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(n--){
        stack<char> st;
        string str;
        bool isVps =true;
        cin >> str;
        for(int i=0;str[i]!='\0';i++){
            if(str[i] == '('){
                st.push('(');
            }else{ //str[i] == ')'
                if(st.empty()){
                    isVps = false;
                    break;
                }
                st.pop();
            }
        }
        if(st.empty() && isVps)
            cout << "YES\n";
        else cout << "NO\n";
    }
}