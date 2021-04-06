#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1){
        string str;
        stack<char> st;
        int cnt=0;
        int push_cnt=0;
        
        cin >> str;
        if(str[0] == '-')   break;
        cout << ++n << ". ";
        for(int i=0;str[i]!='\0';i++){
            if(str[i] == '{'){
                st.push('{');
            }else{
                if(st.empty()){
                    cnt++;
                    st.push('{');
                    continue;
                }
                st.pop();
            }
        }
        
        cout << cnt + st.size()/2<< '\n';
    }
}