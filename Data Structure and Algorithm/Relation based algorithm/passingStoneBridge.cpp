#include<iostream>
using namespace std;

#define MAX_SCROLL 11
#define MAX_BRIDGE 21

char scroll[MAX_SCROLL];
char bridges[2][MAX_BRIDGE];

int cnt;

void solve(int k, int AorD, int p)
{
    if(scroll[k] == '\0'){
        ++cnt;
        return;
    }

    int next = AorD == 1 ? 0:1;
    for(int i=p; bridges[AorD][i] != '\0'; i++){
        if(bridges[AorD][i] == scroll[k]){
            solve(k+1, next, i+1);
        }
    }
}

int main()
{
    int ntc = 3;

    while(--ntc){
        cin >> scroll;
        cin >> bridges[0] >> bridges[1];

        solve(0, 0, 0);
        solve(0, 1, 0);
        cout << cnt << endl;        
        cnt = 0;
    }
}
