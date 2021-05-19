#include <bits/stdc++.h>
using namespace std;

int n,m,v;
int board[1005][1005];
int isused[1005];
stack<int> st;
queue<int> Q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> v;
    while(m--){
        int a,b;
        cin >> a >> b;
        board[a][b] = 1;
        board[b][a] = 1;
    }

    st.push(v);
    isused[v] = 1;
    while(!st.empty()){
        int cur = st.top();
        st.pop();
        cout << cur << ' ';
        for(int i=1;i<=n;i++){ 
            if(!isused[i] && board[cur][i]){
                st.push(i);
                isused[i] = 1;
            }
        }
    }

    cout << '\n';
    fill(isused,isused+n+1,0);

    Q.push(v);
    isused[v] = 1;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        cout << cur << ' ';
        for(int i=1;i<=n;i++){
            if(!isused[i] && board[cur][i]){
                Q.push(i);
                isused[i]= 1;
            }
        }
    }
}