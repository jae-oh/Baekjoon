#include <bits/stdc++.h>

using namespace std;

int n;
int board[21][21];
int temp_board[21][21];

void add(int dir);
void rotate();
void reverse_rotate();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    int max = board[0][0]; //가장 큰 값을 가진 블록 초기화

    for(int temp=0;temp<1024;temp++){ //1024 : 4방향을 5번 모두 탐색하는 경우의 수, 4^5
        int brute=temp; //4가지 방향을 가지기 때문에, 4진수를 활용하기 위한 변수
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                temp_board[i][j] = board[i][j];
        
        for(int i=0;i<5;i++){ 
            int dir=brute%4; //%4로 4진수에 맞는 값 추출
            brute /= 4;//4로 나누어서 다음 4진수 값 대비
            add(dir);
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(temp_board[i][j] > max)
                    max = temp_board[i][j];
        
    }

    cout << max << '\n';

    
}

void add(int dir)
{
    for(int temp=0;temp<dir;temp++)
        rotate();//90도 회전 함수, 즉, 방향을 4방향으로 설정하지 말고 보드를 90도씩 회전하면서 한쪽으로 이동시킴
    
    for(int i=0;i<n;i++){
        int idx=0; //added배열에서 넣는 곳의 index
        int added[21];//한쪽으로 밀어서 합치는 새로운 배열을 이용하기 위한 배열
        bool isused[21];//조건에 한 번의 이동에서 합쳐진 블록은 또다시 합쳐지지 않기 때문에, 한번 합친 블록은 isused값을 true로 바꿔서 다시 합쳐지지 않도록 하기
        for(int k=0;k<21;k++){
            isused[k] = false;
            added[k] = 0;
        }
        for(int j=0;j<n;j++){
            if(temp_board[i][j]){
                if(temp_board[i][j] == added[idx] && !isused[idx]){
                    added[idx] *=2;
                    isused[idx] = true;
                }else{
                    added[++idx] = temp_board[i][j];
                }
            }
        }
        for(int iter=0;iter<n;iter++)
            temp_board[i][iter] = added[iter];
    }

    for(int temp=0;temp<dir;temp++)
        reverse_rotate(); 
    
}

void rotate()
{
    int tmp[21][21];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = temp_board[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp_board[i][j] = tmp[n - 1 - j][i];
}

void reverse_rotate(){
    int tmp[21][21];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = temp_board[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp_board[n - 1 - j][i] = tmp[i][j];
}