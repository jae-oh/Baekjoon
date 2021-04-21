#include <bits/stdc++.h>
using namespace std;

int testN;
int board[305][305];
int dist[305][305];
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {-2,-1,1,2,-2,-1,1,2};
queue<pair<int,int>> Q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> testN;

    while(testN--){
        pair<int,int> start_L,end_L;
        int n;

        cin >> n;
        cin >> start_L.first >> start_L.second >> end_L.first >> end_L.second;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j] = -1;

        Q.push({start_L.first,start_L.second});
        dist[start_L.first][start_L.second] = 0;
        while(!Q.empty()){
            pair<int,int> cur = Q.front();
            Q.pop();

            for(int dir=0;dir<8;dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if(nx<0||nx>=n||ny<0||ny>=n)
                    continue;
                if(dist[nx][ny] >= 0)
                    continue;
                
                Q.push({nx,ny});
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
            }
        }
        cout << dist[end_L.first][end_L.second] << '\n';
    }
}