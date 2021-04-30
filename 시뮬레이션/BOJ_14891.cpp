#include <bits/stdc++.h>
using namespace std;

/* 
//다른 사람 정담
-flag와 재귀를 이용하여 풀었다. 
-내 코드보다 간결하고 이해하기 쉽다.
-다음에는 이렇게 풀어보자

#include<iostream>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;

int wheel[4][8], k;
int v[4];
void move_clock(int num) {
	int temp = wheel[num][7];
	for (int i = 7; i >= 1 ; i--) {
		wheel[num][i] = wheel[num][i - 1];
	}
	wheel[num][0] = temp;
}

void move_counter(int num) {
	int temp = wheel[num][0];
	for (int i = 0; i < 8; i++) {
		wheel[num][i] = wheel[num][i + 1];
	}
	wheel[num][7] = temp;
}

void move(int num, int dir) {
	int r_flag = 0, l_flag = 0;
	
	if (num == 3) {
		if (!v[num - 1] && wheel[num - 1][2] != wheel[num][6]) l_flag = 1;
	}
	else if (num == 0) {
		if (!v[num + 1] && wheel[num + 1][6] != wheel[num][2]) r_flag = 1;
	}
	else {
		if (!v[num - 1] && wheel[num - 1][2] != wheel[num][6]) l_flag = 1;
		if (!v[num + 1] && wheel[num + 1][6] != wheel[num][2]) r_flag = 1;
	}
	v[num] = 1;
	if (l_flag) move(num - 1, dir * -1);
	if (r_flag) move(num + 1, dir * -1);

	if (dir == 1) move_clock(num);
	else if (dir == -1)move_counter(num);
}

int main() {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) scanf("%1d", &wheel[i][j]);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		fill(v, v + 4, 0);
		int num, dir;
		scanf("%d%d", &num, &dir);
		num -= 1;
		move(num, dir);
	}
	for (int i = 0; i < 4; i++) {
		if (wheel[i][0] == 1) sum += pow(2, i);
	}
	cout << sum;
}
*/

int wheel[5][8],top[5];
int testN;

void rotate(int num,int dir);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=1;i<5;i++){
        for(int j=0;j<8;j++){
            char ch;
            cin >> ch;
            if(ch=='1')
                wheel[i][j] = 1;
            else
                wheel[i][j] = 0;
        }
    }
    cin >> testN;
    while(testN--){
        int w_num,w_dir,nw_dir;
        int isrotate[5]; //톱니바퀴가 하나씩 움직이는게 아니라 동시에 움직이므로 isrotate에 움직이는 바퀴를 저장해둔 뒤, 한번에 회전시킨다.
        queue<pair<int,int>> Q;
        fill(isrotate,isrotate+5,0);

        cin >> w_num >> w_dir;
        isrotate[w_num] = w_dir;
        if(w_dir==1)    nw_dir = -1; //옆 톱니바퀴가 회전할때는, 지금과 방향이 반대이기 때문에, 다음 방향을 반대로 지정해준다.
        else    nw_dir = 1;

        if(w_num == 1){
            for(int i=1;i<5;i++){
                if(i==4)    break;

                if(wheel[i][(top[i]+2)%8] == wheel[i+1][(top[i+1]+6)%8]) //만약 맞물리는 지점이 동일한 극이면 멈춰준다.
                    break;
                else{
                    isrotate[i+1] = nw_dir;
                }

                if(nw_dir==1)   nw_dir=-1;
                else    nw_dir=1;
            }

        }else if(w_num == 2){
            if(wheel[1][(top[1]+2)%8] != wheel[2][(top[2]+6)%8])
                isrotate[1] = nw_dir;

            for(int i=2;i<5;i++){
                if(i==4)    break;

                if(wheel[i][(top[i]+2)%8] == wheel[i+1][(top[i+1]+6)%8])
                    break;
                else{
                    isrotate[i+1] = nw_dir;
                }

                if(nw_dir==1)   nw_dir=-1;
                else    nw_dir=1;
            }

        }else if(w_num == 3){
            if(wheel[3][(top[3]+2)%8] != wheel[4][(top[4]+6)%8])
                isrotate[4] = nw_dir;

            for(int i=3;i>0;i--){
                if(i==1)    break;

                if(wheel[i][(top[i]+6)%8] == wheel[i-1][(top[i-1]+2)%8])
                    break;
                else{
                    isrotate[i-1] = nw_dir;
                }

                if(nw_dir==1)   nw_dir=-1;
                else    nw_dir=1;
            }

        }else{
            for(int i=4;i>0;i--){
                if(i==1)    break;

                if(wheel[i][(top[i]+6)%8] == wheel[i-1][(top[i-1]+2)%8])
                    break;
                else{
                    isrotate[i-1] = nw_dir;
                }

                if(nw_dir==1)   nw_dir=-1;
                else    nw_dir=1;
            }
        }

        for(int i=1;i<5;i++){ //isrotate의 값을 바탕으로 동시에 회전 시켜준다.
            if(isrotate[i] == 1 || isrotate[i] == -1)
                rotate(i,isrotate[i]);
        }
    }

    int ans=0;
    if(wheel[1][top[1]] == 1)
        ans += 1;
    if(wheel[2][top[2]] == 1)
        ans += 2;
    if(wheel[3][top[3]] == 1)
        ans += 4;
    if(wheel[4][top[4]] == 1)
        ans += 8;
    
    cout << ans;


}

void rotate(int num,int dir){
    if(dir == -1){
        if(top[num]+1 > 7)
            top[num] = 0;
        else top[num]++;
    }else if (dir==1){
        if(top[num] -1 <0)
            top[num] = 7;
        else top[num]--;
    }else{
        return;
    }
}