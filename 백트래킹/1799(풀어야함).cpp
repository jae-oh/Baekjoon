#include <bits/stdc++.h>
using namespace std;

int n,maxN,empty_loc; //empty_loc : 처음에 놓을 수 있는 공간의 수
int board[12][12],isused[12][12];

void func(int row,int col,int impossi_loc,int bishopN ); //놓을 수 없는 공간의 수

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            if(board[i][j])
                empty_loc++;
        }

    func(0,0,0,0);
    cout << maxN;
}

void func(int row,int col,int impossi_loc,int bishopN){
    if(impossi_loc == empty_loc){ //처음에 놓을 수 있는 공간이 모두 놓을 수 없는 공간으로 바뀌었을 때, 비숍 수 체크
        if(maxN < bishopN)
            maxN = bishopN;
        //cout << maxN << '\n';
        return ;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!isused[i][j] && board[i][j] == 1){
                isused[i][j] = 1;
                impossi_loc++;
                for(int k=1;k<n;k++){
                    if(i+k<n&&j+k<n){
                        isused[i+k][j+k]++;
                        if(board[i+k][j+k]==1&&isused[i+k][j+k] == 1) impossi_loc++;
                    }
                    if(i+k<n&&j-k>=0){
                        isused[i+k][j-k]++;
                        if(board[i+k][j-k]==1&&isused[i+k][j-k] == 1) impossi_loc++;
                    }
                    if(i-k>=0&&j-k>=0){
                        isused[i-k][j-k]++;
                        if(board[i-k][j-k]==1&&isused[i-k][j-k] == 1) impossi_loc++;
                    }
                    if(i-k>=0&&j+k<n){
                        isused[i-k][j+k]++;
                        if(board[i-k][j+k]==1&&isused[i-k][j+k] == 1) impossi_loc++;
                    }
                }

                //cout << impossi_loc << '\n';
                /*for(int a=0;a<n;a++){
                    for(int l=0;l<n;l++)
                        cout << isused[a][l] << ' ';
                    cout << '\n';
                }*/
                func(i,j,impossi_loc,bishopN+1);
                isused[i][j] = 0;
                impossi_loc--;
                for(int k=1;k<n;k++){
                    if(i+k<n&&j+k<n){
                        isused[i+k][j+k]--;
                        if(board[i+k][j+k]==1&&isused[i+k][j+k] == 0) impossi_loc--;
                    }
                    if(i+k<n&&j-k>=0){
                        isused[i+k][j-k]--;
                        if(board[i+k][j-k]==1&&isused[i+k][j-k] == 0) impossi_loc--;
                    }
                    if(i-k>=0&&j-k>=0){
                        isused[i-k][j-k]--;
                        if(board[i-k][j-k]==1&&isused[i-k][j-k] == 0) impossi_loc--;
                    }
                    if(i-k>=0&&j+k<n){
                        isused[i-k][j+k]--;
                        if(board[i-k][j+k]==1&&isused[i-k][j+k] == 0) impossi_loc--;
                    }
                }
            }
        }
    }
}