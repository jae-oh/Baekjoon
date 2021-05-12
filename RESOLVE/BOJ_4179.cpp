#include <bits/stdc++.h>
using namespace std;

/*
#문제풀이 아이디어
1.불이 붙은 곳 모두를 Queue에 넣고 BFS로 돌리면 몇분후에 지나갈 수 있는 곳이 불에 타는지 알 수 있다.
2.처음 isused배열에 몇분후에 탈지 저장해둔다.
3.그 다음 지훈이의 위치에서 BFS를 돌린다.
4.이 때, 조건은
    1)지훈이가 갈수 있는 곳은 '.'이다. 
    2)지훈이가 방문했던 곳은 가면 안된다(isused와 isused2를 함께 사용하기 때문에 무한 루프에 빠질 수 있다.)
    3)지훈이가 갈 수 있는 곳은 불에 타기전에 갈 수 있다. 이 때, isused = 0이면 isused < isused2 +1 조건이 항상 만족하므로 못간다. 그러므로 isused!=0일 때('.'이지만 불이 평생 안붙을 곳) isused < isused2 +1을 해줘야한다.
*/

char board[1005][1005];
int isused[1005][1005],isused2[1005][1005],visited[1005][1005];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
pair<int,int> jihun;
queue<pair<int,int>> Q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] == 'J'){
                jihun = {i,j};
                isused2[i][j] =1;
            }

            if(board[i][j] == 'F'){
                Q.push({i,j});
                isused[i][j] =1;
            }
        }
    }
    
    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx<0 || nx >= n || ny <0 || ny >= m)
                continue;
            if(isused[nx][ny] || board[nx][ny] != '.')
                continue;
            
            Q.push({nx,ny});
            isused[nx][ny] = isused[cur.first][cur.second] + 1;
        }
    }

    Q.push(jihun);
    visited[jihun.first][jihun.second];

    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx<0 || nx >= n || ny <0 || ny >= m){
                cout << isused2[cur.first][cur.second];
                return 0;
            }
            if((isused[nx][ny] <= isused2[cur.first][cur.second] +1 && isused[nx][ny] != 0) || board[nx][ny] != '.'|| visited[nx][ny])
                continue;
            
            Q.push({nx,ny});
            isused2[nx][ny] = isused2[cur.first][cur.second] +1;
            visited[nx][ny] =1;
        }
    }

    cout << "IMPOSSIBLE";
}