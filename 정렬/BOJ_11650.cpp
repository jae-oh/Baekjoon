#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> vec;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        vec.push_back({x,y});
    }
    sort(vec.begin(),vec.end());

    for(auto i:vec)
        cout << i.first << ' ' << i.second << '\n';
}