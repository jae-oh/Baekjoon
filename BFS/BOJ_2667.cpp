#include <bits/stdc++.h>
using namespace std;

int n,cnt;
int board[30][30];
int vis[30][30];
queue<pair<int,int>> Q;
vector<int> vec;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char ch;
            cin >> ch;
            if(ch=='0')
                board[i][j] = 0;
            else
                board[i][j] = 1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] && !vis[i][j]){
                cnt=0;
                Q.push({i,j});
                vis[i][j] = 1;
                while(!Q.empty()){
                    pair<int,int> cur = Q.front();
                    Q.pop();
                    cnt++;
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.first +dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx<0||nx>=n||ny<0||ny>=n)
                            continue;
                        if(vis[nx][ny] || !board[nx][ny])
                            continue;
                        Q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
                vec.push_back(cnt);
            }
        }
    }

    cout << vec.size() << '\n';
    sort(vec.begin(),vec.end());
    for(auto i : vec)
        cout << i << '\n';
}