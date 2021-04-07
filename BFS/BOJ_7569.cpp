#include <bits/stdc++.h>
using namespace std;

int m,n,h; // m:상자의 가로칸수 n:상자의 세로칸수 h:쌓아올려지는 상자의 수
int board[105][105][105];
int dist[105][105][105]; //걸리는 시간 계산
int dx[6] = {0,0,1,0,-1,0};
int dy[6] = {0,0,0,1,0,-1};
int dz[6] = {1,-1,0,0,0,0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<tuple<int,int,int>> Q;

    cin >> m >> n >> h;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin >> board[i][j][k];
                dist[i][j][k] = -1; // 익지않은 토마토거나 토마토가 없을 경우
                if(board[i][j][k] == 1){
                    Q.push({i,j,k}); //익은 토마토들의 위치를 Q에 넣고 모두 BFS 돌림
                    dist[i][j][k] = 0; // 익어있는 토마토의 시간만 0으로 초기화(거리가 0이기 때문에)
                }
            }
        }
    }

    while(!Q.empty()){
        tuple<int,int,int> cur = Q.front();
        Q.pop();
        for(int dir=0;dir<6;dir++){
            int nx = get<2>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<0>(cur) + dz[dir];
            if(nx<0||nx>m||ny<0||ny>n||nz<0||nz>h)
                continue;
            if(dist[nz][ny][nx] != -1 || board[nz][ny][nx] == -1) //토마토가 익었거나 토마토가 없는 칸이면 continue;
                continue;
            
            dist[nz][ny][nx] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            Q.push({nz,ny,nx});
        }
    }

    int mx = dist[0][0][0];
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(board[i][j][k] == 0 && dist[i][j][k] == -1){
                    cout << "-1";
                    return 0;
                }
                mx = max(dist[i][j][k],mx);
            }
        }
    }
    
    cout << mx;
}