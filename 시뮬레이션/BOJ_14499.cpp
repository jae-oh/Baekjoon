#include <bits/stdc++.h>
using namespace std;

//동쪽(오른쪽으로) : 1 , 서쪽(왼쪽으로) : 2 , 북쪽(위로) : 3 , 남쪽(밑으로) : 4

int n,m,k;
int board[25][25];
int dice[6]; //0:위 ,1:뒤,2:아래,3:앞,4:오른쪽,5:왼쪽
pair<int,int> cur;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> cur.first >> cur.second >> k;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> board[i][j];

    while(k--){
        int dir;
        cin >> dir;
        //동쪽으로가면 , 오른쪽-> 아래 / 아래-> 왼쪽 / 왼쪽-> 위 / 위-> 오른쪽
        //swap(오른쪽, 아래) , swap(오른쪽, 왼쪽), swap(오른쪽, 위)
        //서쪽으로가면 , 왼쪽 -> 아래 / 아래 -> 오른쪽 / 오른쪽-> 위/ 위-> 왼쪽
        //swap(왼쪽, 아래) , swap(왼쪽, 오른쪽), swap(왼쪽 , 위)
        //북족으로가면 , 위 -> 뒤 / 뒤->아래 / 아래-> 앞 -/ 앞->위
        //swap(위, 뒤) , swap(위,아래) , swap(위, 앞)
        //남쪽으로가면, 위 -> 앞 / 앞 -> 아래/아래-> 뒤/뒤->위
        //swap(위,앞),swap(위,아래),swap(위, 뒤)
        if(dir == 1){
            if(cur.second+1>=m){
                continue;
            }
            cur.second++;
            swap(dice[4],dice[2]);
            swap(dice[4],dice[5]);
            swap(dice[4],dice[0]);
            if(!board[cur.first][cur.second]){
                board[cur.first][cur.second] = dice[2];
            }else{
                dice[2] = board[cur.first][cur.second];
                board[cur.first][cur.second] = 0;
            }
            cout << dice[0] << '\n';
        }else if(dir == 2){
            if(cur.second-1<0){
                continue;
            }
            cur.second--;
            swap(dice[5],dice[2]);
            swap(dice[5],dice[4]);
            swap(dice[5],dice[0]);
            if(!board[cur.first][cur.second]){
                board[cur.first][cur.second] = dice[2];
            }else{
                dice[2] = board[cur.first][cur.second];
                board[cur.first][cur.second] = 0;
            }
            cout << dice[0] << '\n';
        }else if(dir == 3){
            if(cur.first-1<0){
                continue;
            }
            cur.first--;
            swap(dice[0],dice[1]);
            swap(dice[0],dice[2]);
            swap(dice[0],dice[3]);
            if(!board[cur.first][cur.second]){
                board[cur.first][cur.second] = dice[2];
            }else{
                dice[2] = board[cur.first][cur.second];
                board[cur.first][cur.second] = 0;
            }
            cout << dice[0] << '\n';
        }else {
            if(cur.first+1>=n){
                continue;
            }
            cur.first++;
            swap(dice[0],dice[3]);
            swap(dice[0],dice[2]);
            swap(dice[0],dice[1]);
            if(!board[cur.first][cur.second]){
                board[cur.first][cur.second] = dice[2];
            }else{
                dice[2] = board[cur.first][cur.second];
                board[cur.first][cur.second] = 0;
            }
            cout << dice[0] << '\n';
        }
    }
    
}