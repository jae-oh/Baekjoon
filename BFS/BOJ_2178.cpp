#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[101][101];
int dist1[101][101]; // 방문한 곳을 저장하는 vis를 대체하여 dist1라는 배열을 -1로 초기화하여 방문한지 여부와 거리를 계산한다.
int n,m; //행,열 그리고 도착지 : (n-1,m-1)
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<pair<int,int>> Q;

    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a;
            cin >> a;
            dist1[i][j] = -1; //dist1 -1로 초기화
            if(a == '1'){
                board[i][j] = 1;
            }else if(a=='0'){
                board[i][j] = 0;
            }
        }
    }
    dist1[0][0] = 1;
    Q.push({0,0});
    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx <0 || nx >=n||ny<0||ny>=m) //범위 밖일 때, continue
                continue;
            if(dist1[nx][ny] != -1 || board[nx][ny] != 1) //dist1[nx][ny]가 -1이 아니면 방문한곳, board[nx][ny]가 1이 아니면 갈 수 없는곳
                continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y]+1;
            Q.push({nx,ny});
        }
    }
    
    cout << dist1[n-1][m-1];
}
