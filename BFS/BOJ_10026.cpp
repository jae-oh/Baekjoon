#include <bits/stdc++.h>
using namespace std;

int n,cnt1=0,cnt2=0;
int board1[105][105]; //적록색약X
int board2[105][105]; //적록색약
int vis1[105][105];
int vis2[105][105];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> Q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char ch;
            cin >> ch;

            if(ch == 'R'){
                board1[i][j] =1;
                board2[i][j] =1;
            }else if(ch == 'G'){
                board1[i][j] = 2;
                board2[i][j] = 1;
            }else{
                board1[i][j] = 3;
                board2[i][j] = 2;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!vis1[i][j]){
                cnt1++;
                Q.push({i,j});
                vis1[i][j] = 1;
                while(!Q.empty()){
                    pair<int,int> cur = Q.front();
                    Q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx<0||nx>=n||ny<0||ny>=n)
                            continue;
                        if(vis1[nx][ny] || board1[cur.first][cur.second] != board1[nx][ny])
                            continue;
                        
                        Q.push({nx,ny});
                        vis1[nx][ny] = 1;
                    }
                }
            }

            if(!vis2[i][j]){
                cnt2++;
                Q.push({i,j});
                vis2[i][j] = 1;
                while(!Q.empty()){
                    pair<int,int> cur = Q.front();
                    Q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx<0||nx>=n||ny<0||ny>=n)
                            continue;
                        if(vis2[nx][ny] || board2[cur.first][cur.second] != board2[nx][ny])
                            continue;
                        
                        Q.push({nx,ny});
                        vis2[nx][ny] = 1;
                    }
                }
            }
        }
    }

    cout << cnt1 << ' ' << cnt2;
}