#include <bits/stdc++.h>
using namespace std;

int n;

void func1(int a);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    func1(n);

}

void func1(int a){
    string str="";
    for(int i=0;i<n-a;i++){
        str.push_back('_');
        str.push_back('_');
        str.push_back('_');
        str.push_back('_');
    }
    if(a==0){
        cout << str << "\"����Լ��� ������?\"\n";
        cout << str << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        cout << str << "��� �亯�Ͽ���.\n";
        return;
    }
    cout << str << "\"����Լ��� ������?\"\n";
    cout << str << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    cout << str << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    cout << str << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    func1(a-1);
    cout << str << "��� �亯�Ͽ���.\n";
}