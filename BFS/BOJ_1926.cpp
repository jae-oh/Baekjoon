#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[501][501]; // 도화지
int vis[501][501];   // 방문한 곳
int n, m;            // 행, 열
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<pair<int, int>> Q; // pair 타입으로된 queue 생성
    int count =0; //그림개수
    int max_area =0; //가장 넓은 그림의 넓이
    int area = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) //도화지에서 시작점 찾기
        {
            if (vis[i][j] || !board[i][j])
                continue;
            vis[i][j] = 1;
            Q.push({i, j});
            count++;//그림 개수
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                area++;//Q.pop할때마다 넓이++
                
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) //범위 밖일 경우 continue
                        continue;
                    if (vis[nx][ny] || board[nx][ny] != 1) //이미 방문한 칸이거나 파란 칸이 아닐 경우 continue
                        continue;

                    vis[nx][ny] = 1; //(nx,ny)를 방문했다고 명시
                    Q.push({nx, ny});
                }
            }
            if(area > max_area)
                max_area = area;
            area=0;
        }
    }

    cout << count << '\n' << max_area;
   
}