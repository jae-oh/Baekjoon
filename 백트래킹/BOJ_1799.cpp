#include <bits/stdc++.h>
using namespace std;

/*이 문제는 체스판을 두가지로 나누어서 생각해야한다. 하얀색 발판, 검은색 발판
왜냐하면 하얀색 발판에 있는 비숍이 갈 수 있는 곳은 하얀색 발판뿐이고, 즉 하얀색 발판과 검은색 발판은 영향을 주지 않기때문이다.
이러한 특징때문에 10*10을 탐색하는 것을 5*5 두 번으로 탐색 가능하다.

비숍을 칸에 놓을 수 있는 경우의 수 : 놓는다/놓지 않는다 ==> 2가지
비숍을 놓을 수 있는 칸의 수 : 2 * N/2 * N/2
즉, 시간복잡도는 O(2^(N/2*N/2)) 이다.
*/
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
    func(n,col+2,bishopN,isbool); 
    //위의 종료조건으로 바로 가는 재귀함수를 한번더 두는 이유는, 모든 좌표를 다 확인하였지만 조건에 충족하지 않아서 반복문 안의 재귀함수로 들어가지 못한다면 그 때의 비숍 수의 값은 없어지기 때문이다.

}

//https://j2wooooo.tistory.com/80 참조하기