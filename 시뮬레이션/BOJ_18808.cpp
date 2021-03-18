#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int r, c;
int sticker[20][20];
int board[50][50];
int cnt=0;//스티커가 붙은 칸의 수

void rotate(); //90도 회전하는 힘수
bool pastable(int x, int y); // board의 (x,y)에 모눈종이의 (0,0)이 올라가게 스티커를 붙일 수 있는지 판단하는 함수. 가능할 경우 board를 갱신한 후 true를 반환

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int temp = 0; temp < k; temp++)
    {
        cin >> r >> c;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> sticker[i][j];
            }
        }
        for (int iter = 0; iter < 4; iter++)
        {
            bool is_paste = false;
            //모눈종이를 한칸씩 띄워가며 붙여보기
            for (int x = 0; x <= n - r; x++) //n-r이 0보다 작으면 실행이 안되고, 똑같으면 실행이 되야하기 때문에 <=으로 둔다.
            {
                if(is_paste)
                    break;
                for (int y = 0; y <= m - c; y++)
                {
                    if(pastable(x, y)){
                        is_paste=true;
                        break;
                    }                        
                }
            }
            if(is_paste)
                break;
            rotate();
        }

        fill(&sticker[0][0],&sticker[19][20],0); //fill(시작 위치, 끝나는 위치 +1, 초기화 값);
        
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(board[i][j])
                cnt++;

    cout << cnt;

}

bool pastable(int x, int y)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[x + i][y + j] == 1 && sticker[i][j] == 1)
                return false;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(sticker[i][j] == 1)
                board[x+i][y+j] =1;

        }
    }

    return true;
}

void rotate()
{
    int tmp[20][20];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            tmp[i][j] = sticker[i][j];

    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
            sticker[i][j] = tmp[r - 1 - j][i];

    swap(r, c);
}