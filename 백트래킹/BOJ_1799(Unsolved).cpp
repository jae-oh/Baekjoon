#include <bits/stdc++.h>
using namespace std;

int n,maxN[2];
int board[12][12];
int isused1[1000]; //좌측하단에서 우측상단으로 가는 대각선(/)
int isused2[1000]; //좌측상단에서 우측하단으로 가는 대각선(\)

void func(int row,int col,int bishopN,int isbool); //isbool은 흰색 체스판, 블랙 체스판 나누기 위해 주는 변수

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> board[i][j];
    func(0,0,0,0);
    func(0,1,0,1);
    cout << maxN[0] + maxN[1];
}

void func(int row,int col,int bishopN,int isbool){
    if(row >= n){ //row가 커져서 범위를 벗어나면 return;
        if(bishopN >= maxN[isbool])
            maxN[isbool] = bishopN;
        return ;
    }
    for(int i=row;i<n;i++){
        for(int j=col;j<n;j+=2){
            if(j+2 >= n){
                if((col+2)%2==0) col =1;
                else col =0;
            }
            if(!isused1[i+j] && !isused2[i-j+n-1]&&board[i][j] == 1){ // 같은 /대각선에 있는 좌표들은 x+y로 표현가능하고, 같은 \대각선에 있는 좌표들은 x-y로 표현가능하다.(x-y+n-1)을 해주는 이유는 음수가 되지 않게 하기 위해
                int next_row=i;
                int next_col=j+2;
                if(next_col >= n){
                    next_row++;
                    if(next_col%2==0) next_col=1;
                    else next_col=0;
                }
                isused1[i+j] = 1;
                isused2[i-j+n-1] = 1;
                func(next_row,next_col,bishopN+1,isbool);
                isused1[i+j] = 0;
                isused2[i-j+n-1] = 0;
            }
        }
    }
}

//https://j2wooooo.tistory.com/80 참조하기