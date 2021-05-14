#include <bits/stdc++.h>
using namespace std;

int n,m,ans=64;
int board[10][10],isused[10][10],tmp_board[10][10];
vector<tuple<int,int,int>> cctv;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void sight(int row,int col,int dir);
void func(int k);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            tmp_board[i][j] = board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6)
                cctv.push_back({i,j,board[i][j]});
        }
    }
    func(0);
    cout << ans;
}

void sight(int row,int col,int dir){
    while(1){
        row += dx[dir];
        col += dy[dir];

        if(row <0 || row >= n || col <0 || col >=m) //한 방향의 끝으로 가기 때문에 한쪽끝이 나오면 끝남
            return;
        if(tmp_board[row][col] == 6) //벽만나면 끝남
            return;
        if(tmp_board[row][col] != 0) //CCTV로 이미 감시하고 있는 곳이나, CCTV이면 continue;
            continue;
        
        tmp_board[row][col] = -1;
    }
}
void func(int k){
    if(k == cctv.size()){
        int cnt=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(tmp_board[i][j] == 0)
                    cnt++;
        
        if(ans > cnt)
            ans = cnt;
        return;
    }
    int tmp[10][10];
    copy(&tmp_board[0][0],&tmp_board[0][0] + 100,&tmp[0][0]); 
    //copy(&복사할배열의 시작지점,&복사할 배열의 시작지점 + 데이터 수,&복사될 배열의 시작지점)
    if(get<2>(cctv[k]) == 1){
        sight(get<0>(cctv[k]),get<1>(cctv[k]),0);
        func(k+1);
        copy(&tmp[0][0],&tmp[0][0] + 100,&tmp_board[0][0]); //재귀가 끝나면 현재 단계의 배열로 다시 복사해줘야한다.
        sight(get<0>(cctv[k]),get<1>(cctv[k]),1);
        func(k+1);
        copy(&tmp[0][0],&tmp[0][0] + 100,&tmp_board[0][0]);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),2);
        func(k+1);
        copy(&tmp[0][0],&tmp[0][0] + 100,&tmp_board[0][0]);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),3);
        func(k+1);
        copy(&tmp[0][0],&tmp[0][0] + 100,&tmp_board[0][0]);
    }else if(get<2>(cctv[k]) == 2){
        sight(get<0>(cctv[k]),get<1>(cctv[k]),0);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),2);
        func(k+1);
        copy(&tmp[0][0],&tmp[0][0] + 100,&tmp_board[0][0]);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),1);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),3);
        func(k+1);
        copy(&tmp[0][0],&tmp[0][0] + 100,&tmp_board[0][0]);
    }else if(get<2>(cctv[k]) == 3){
        sight(get<0>(cctv[k]),get<1>(cctv[k]),0);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),1);
        func(k+1);
        copy(&tmp[0][0],&tmp[0][0] + 100,&tmp_board[0][0]);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),1);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),2);
        func(k+1);
        copy(&tmp[0][0],&tmp[0][0] + 100,&tmp_board[0][0]);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),2);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),3);
        func(k+1);
        copy(&tmp[0][0],&tmp[0][0] + 100,&tmp_board[0][0]);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),0);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),3);
        func(k+1);
        copy(&tmp[0][0],&tmp[0][0] + 100,&tmp_board[0][0]);
    }else if(get<2>(cctv[k]) == 4){
        sight(get<0>(cctv[k]),get<1>(cctv[k]),0);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),1);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),2);
        func(k+1);
        copy(&tmp[0][0],&tmp[0][0] + 100,&tmp_board[0][0]);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),1);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),2);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),3);
        func(k+1);
        copy(&tmp[0][0],&tmp[0][0] + 100,&tmp_board[0][0]);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),2);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),3);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),0);
        func(k+1);
        copy(&tmp[0][0],&tmp[0][0] + 100,&tmp_board[0][0]);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),3);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),0);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),1);
        func(k+1);
        copy(&tmp[0][0],&tmp[0][0] + 100,&tmp_board[0][0]);
    }else if(get<2>(cctv[k]) == 5){
        sight(get<0>(cctv[k]),get<1>(cctv[k]),0);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),1);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),2);
        sight(get<0>(cctv[k]),get<1>(cctv[k]),3);
        func(k+1);
        copy(&tmp[0][0],&tmp[0][0] + 100,&tmp_board[0][0]);
    }
}