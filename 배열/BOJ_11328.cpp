#include <bits/stdc++.h>

using namespace std;

int freq1[26];
int freq2[26];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string a;
        string b;

        cin >> a >> b;

        fill(freq1,freq1+sizeof(freq1)/sizeof(int),0);
        fill(freq2,freq2+sizeof(freq2)/sizeof(int),0);

        for(auto i : a)
            freq1[i-'a']++;
        
        for(auto i : b)
            freq2[i-'a']++;

        //equal(배열1 첫번째, 배열1 마지막,배열2 첫번째, 배열2 마지막); -> 일치하면 true , 불일치하면 false 반환
        equal(freq1,freq1+sizeof(freq1)/sizeof(int),freq2,freq2+sizeof(freq2)/sizeof(int)) ? cout << "Possible\n" : cout << "Impossible\n";
    }
}