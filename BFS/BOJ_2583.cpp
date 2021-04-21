#include <bits/stdc++.h>
using namespace std;

int m,n,k,cnt;
int board[105][105];
int vis[105][105];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> Q;
vector<int> vec;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n >> k;
    while(k--){
        int x1,x2,y1,y2;

        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=y1;i<y2;i++){
            for(int j=x1;j<x2;j++){
                if(board[i][j]) continue;
                board[i][j] = 1;
                vis[i][j] = 1;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]){
                cnt=0;
                Q.push({i,j});
                vis[i][j] = 1;
                while(!Q.empty()){
                    pair<int,int> cur = Q.front();
                    cnt++;
                    Q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx<0||nx>=m||ny<0||ny>=n)
                            continue;
                        if(vis[nx][ny] || board[nx][ny])
                            continue;
                        Q.push({nx,ny});
                        //cout << nx << ny << ' ';
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
        cout << i << ' ';
}