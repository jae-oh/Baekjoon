#include <bits/stdc++.h>
using namespace std;

int n,maxN,max_locN;
int board[105][105];
int isused[105][105];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            if(maxN < board[i][j])
                maxN = board[i][j];
        }
    }

    for(int testN=0;testN<maxN;testN++){
        int locN=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                isused[i][j] = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!isused[i][j] && board[i][j] > testN){
                    queue<pair<int,int>> Q;
                    Q.push({i,j});
                    isused[i][j] = 1;
                    locN++;
                    while(!Q.empty()){
                        pair<int,int> cur = Q.front();
                        Q.pop();
                        for(int dir=0;dir<4;dir++){
                            int nx= cur.first +dx[dir];
                            int ny= cur.second + dy[dir];

                            if(nx<0||nx>=n||ny<0||ny>=n)
                                continue;
                            if(isused[nx][ny] || board[nx][ny] <= testN)
                                continue;
                            
                            Q.push({nx,ny});
                            isused[nx][ny] = 1;
                        }
                    }
                }
            }
        }

        if(locN > max_locN)
            max_locN = locN;
    }

    cout << max_locN;
}