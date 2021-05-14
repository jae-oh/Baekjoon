#include <bits/stdc++.h>
using namespace std;

int n,m,k,r,c;
int board[50][50],st[15][15];

void rotate();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    while(k--){
        bool isattach = true;

        cin >> r >> c;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin >> st[i][j];
        
        for(int dir=0;dir<4;dir++){//4방향
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){ //board의 각 좌표를 시작지점으로 함
                    isattach = true;
                    for(int tmp_i=0 ; tmp_i<r;tmp_i++){ //i,j를 시작지점으로 한 곳에서 스티커를 붙일 수 있는지 확인
                        for(int tmp_j=0 ; tmp_j<c;tmp_j++){
                            if(i+r > n || j+c > m || board[i+tmp_i][j+tmp_j] + st[tmp_i][tmp_j] > 1){ //만약 범위를 벗어나거나 하나라도 1이 넘으면 못붙임
                                isattach =false;
                                break;
                            }
                        }
                    }
                    if(isattach){//만약에 붙일 수 있으면 스티커를 붙임
                        for(int tmp_i=0 ; tmp_i<r;tmp_i++)
                            for(int tmp_j=0 ; tmp_j<c;tmp_j++)
                                board[i+tmp_i][j+tmp_j] += st[tmp_i][tmp_j];
                        break;
                    }
                }
                if(isattach)
                    break;
            }
            if(isattach)//붙였으면 break;
                break;
            rotate();//스티커를 붙이지 못하였으면 90도로 회전해서 한번더 확인
        }
        
    }
    int ans=0;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(board[i][j] == 1)
                ans++;

    cout << ans;
}

void rotate(){
    int tmp[15][15];

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            tmp[j][r-i-1] =  st[i][j];
        }
    }

    swap(r,c);

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            st[i][j] = tmp[i][j];
}