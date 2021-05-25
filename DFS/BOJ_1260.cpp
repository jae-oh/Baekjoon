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
    
    /*
    그래프를 스택DFS로 순회
    */

    st.push(v); //시작점을 stack에 넣어줌
    isused[v] = 1; //방문했다는 것을 표시
    cout << v << ' '; //시작점 출력

    while(!st.empty()){
        int cur = st.top();
        st.pop();
        for(int i=1;i<=n;i++){ 
            if(!isused[i] && board[cur][i]){
                cout << i << ' ';
                st.push(cur); //dfs이기 때문에 다시 돌아와서 다른 edge가 있는지 확인해야한다.
                st.push(i); 
                isused[i] = 1;
                break; //break;를 해줘야 깊이 들어갈 수 있다.
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