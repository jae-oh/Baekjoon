#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

char board[1001][1001];
int dist1[1001][1001];
int dist2[1001][1001];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<pair<int, int>> Q1;
    queue<pair<int,int>> Q2;
    pair<int, int> jihun; //처음 지훈이가 있는 좌표

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == '.'){ //갈 수 있는 곳은 -1로 초기화
                dist1[i][j] = -1;
                dist2[i][j] = -1;
            }
            if (board[i][j] == 'F') //불부터 시작, 불이 여러개 있어도 모두 Queue에 넣어 같이 시작하기
                Q1.push({i, j});
            if (board[i][j] == 'J')
                Q2.push({i,j});
        }
    }

    while (!Q1.empty())
    { //모든 불에 대해 거리구하기
        pair<int, int> cur = Q1.front();
        Q1.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist1[nx][ny] >= 0)
                continue;

            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({nx, ny});
        }
    }

    while (!Q2.empty())
    {
        pair<int, int> cur = Q2.front();
        Q2.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m){ //지훈이가 범위를 벗어났다는 것은 탈출했다는 뜻!!!!!
                cout << dist2[cur.X][cur.Y]+1;
                return 0;
            }
            if (dist2[nx][ny] >= 0)
                continue;
            if (dist1[nx][ny] <= dist2[cur.X][cur.Y] +1 && dist1[nx][ny] != -1) //불이 갇혀있어서 둘다 -1일 때, 지훈이는 갈 수 있다.
                continue;

            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE\n"; //위에 범위 벗어났다는 조건을 지나서 여기까지 온다면 탈출을 하지 못했다는 뜻
}