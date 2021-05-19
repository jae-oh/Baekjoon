#include <bits/stdc++.h>
using namespace std;

/*
#문제풀이 아이디어 : DFS
- 실수한 부분 : 양방향 그래프여서 list에 서로 넣어줘야한다.
*/

int n,m,ans=0;
list<int> l[105];
int isused[105];
stack<int> st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        l[a].push_back(b);
        l[b].push_back(a);
    }

    st.push(3);
    isused[3] = 1;
    while(!st.empty()){
        int cur = st.top();
        st.pop();
        ans++;
        for(auto j : l[cur]){
            if(!isused[j]){
                st.push(j);
                isused[j] = 1;
            }
        }
    }
    cout << ans-1;
}