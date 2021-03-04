#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[51][51];
int vis[51][51];
int k,tN;//k :배추가 심어져 있는 위치의 개수, tN : 테스트케이스 수
int n,m; // 행, 열
int x,y; // 배추 위치
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<pair<int,int>> Q;

    cin >> tN;

    while(tN--){
        int count=0;
        cin >> m >> n >> k;
        while(k--){
            cin >> y >> x;
            board[x][y] = 1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 0 && board[i][j] == 1){
                    vis[i][j] = 1;
                    Q.push({i,j});
                    count++;
                    while(!Q.empty()){
                        pair<int,int> cur = Q.front();
                        Q.pop();
                        for(int dir=0;dir<4;dir++){
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx<0||nx>=n||ny<0||ny>=m)
                                continue;
                            if(vis[nx][ny] == 1||board[nx][ny]==0)
                                continue;
                            vis[nx][ny] = 1;
                            Q.push({nx,ny});
                        }
                    }
                }
            }
        }
        cout<<count<<'\n';
        for(int i=0;i<51;i++)//초기화를 잘해주자!
            for(int j=0;j<51;j++){
                board[i][j] = 0;
                vis[i][j] = 0;
            }
    }

}

