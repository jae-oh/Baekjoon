#include <bits/stdc++.h>
using namespace std;

int n;
stack<pair<int,int>> st;

/*
#문제풀이 아이디어 : (스택 사용)
1.새로운 탑이 stack top보다 작으면 push를 해줌 (왜나하면 뒤에 더작은 탑이 나올 수도 있기 때문에)
2.새로운 탑이 stack top보다 크거나 같으면 더큰 top이 나올 때까지 pop해줌 (왜냐하면 새로운 탑이 stack에 있는 것보다 크거나 같으면 앞에있는건 무효이기 때문)
3.stack이 비워져있으면 0을 출력하고 push
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1;i<=n;i++){
        int height;
        cin >> height;
        while(!st.empty()){
            if(st.top().first <= height)
                st.pop();
            else{
                cout << st.top().second << ' ';
                st.push({height,i});
                break;
            }
        }
        if(st.empty()){
            cout << '0' << ' ';
            st.push({height,i});
        }
        
    }
}