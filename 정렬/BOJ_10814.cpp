#include <bits/stdc++.h>
using namespace std;

int n;
tuple<int,int,string> t[100005];

bool cmp(tuple<int,int,string>& a, tuple<int,int,string>& b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i=0;i<n;i++){
        int age;
        int score;
        string name;

        cin >> age >> name;
        t[i] = make_tuple(age,i,name);
    }
    sort(t,t+n,cmp);

    for(int i=0;i<n;i++)
        cout << get<0>(t[i]) << ' ' << get<2>(t[i]) << '\n';
}

bool cmp(tuple<int,int,string>& a, tuple<int,int,string>& b){
    if(get<0>(a) < get<0>(b)) return true;
    else if(get<0>(a) == get<0>(b)){
        if(get<1>(a) < get<1>(b)) return true;
        else return false;
    }
    else return false;
}

/*다른 사람 코드 : tuple처음 값이 똑같다면 다음 값으로 비교한다는 성질을 활용하여 간결하게 코드 작성
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<tuple<int, int, string> >v;
    for(int i=0; i<N ;i++)
    {
        int a;
        string b;
        cin >> a >> b;
        v.push_back(make_tuple(a, i, b));
    }
    sort(v.begin(), v.end());
    for(int i=0; i<N; i++)
        cout << get<0>(v[i]) << ' '<< get<2>(v[i]) << '\n';
}

*/