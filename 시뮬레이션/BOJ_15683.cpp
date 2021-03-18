#include <bits/stdc++.h>

using namespace std;

int n,m;
int cnt; //최소 사각지대 개수
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int board1[10][10]; //원본
int board2[10][10]; //사본
vector<pair<int,int>> cctv;

bool OOB(int a,int b); //범위를 벗어났는지 확인하는 함수 (Out Of Boundary)
void upd(int x,int y,int dir);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board1[i][j];
            if(board1[i][j] != 6 && board1[i][j] != 0){
                cctv.push_back({i,j});
            }else if(board1[i][j] == 0){
                cnt++; //최소 사각지대 개수를 board1의 0의 개수로 초기화
            }
        }
    }

    for(long long i=0;i<(1<<(2*cctv.size()));i++){ //모든 cctv 방향의 경우의 수 개수만큼 반복 , 1<<(2*cctv.size())는 4의 cctv.size승
        int ans=0;//0 즉 사각지대를 세기 위한 변수
        int brute = i;

        for(int j=0;j<n;j++){
            for(int u=0;u<m;u++){
                board2[j][u] = board1[j][u]; //board2를 board1로 초기화
            }
        }

        for(int k=0;k<cctv.size();k++){ 
            int dir = brute%4; //방향설정
            brute /= 4; //방향설정
            int x= cctv[k].first;
            int y= cctv[k].second;

            if(board1[x][y] == 1){ //한쪽으로
                upd(x,y,dir);
            }else if(board1[x][y] == 2){ // 한쪽과 반대쪽
                upd(x,y,dir);
                upd(x,y,dir+2);
            }else if(board1[x][y] == 3){ // 직각
                upd(x,y,dir);
                upd(x,y,dir+1);
            }else if(board1[x][y] == 4){ // 세방향
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
            }else{ // 네방향
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
                upd(x,y,dir+3);
            }
        }

        for(int j=0;j<n;j++){
            for(int u=0;u<m;u++){
                if(board2[j][u] == 0)
                    ans++;
            }
        }
        if(cnt > ans)
            cnt = ans;
    }
    cout << cnt;

}

bool OOB(int a,int b){
    return a < 0 || a >= n || b <0 || b >=m;
}

void upd(int x,int y,int dir){ //dir방향으로 벽을 제외하고 모두 7로 바꿈
    dir %= 4; //왜냐하면 매개변수로 오는 dir가 4가 넘을 수도 있음
    while(1){
        x += dx[dir];
        y += dy[dir];
        if(OOB(x,y) || board2[x][y] == 6) return; // boundary 벗어났거나 벽을 만나면 return
        if(board2[x][y]) continue; // CCTV or 감시하고 있는 곳을 만나면 continue (바로 위에 조건문에서 6이면 return하니까 0이 아니면 CCTV 혹은 감시하고 있는 곳이다.)
        board2[x][y] = 7; //감시하고 있는곳을 7로 바꿔줌
    }
}