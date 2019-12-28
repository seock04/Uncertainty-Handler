#include <iostream>
using namespace std;

int data[100][100];
int N, M, H, W;
int res =0;

int main()
{
    cin >> N >> M;
    cin >> H >> W;

    for(int i =0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> data[i][j];
        }
    }

    for(int i=0;i<N-H+1;i++){
        for(int j=0;j<M-W+1;j++){
            int temp=0;
            for(int h=0;h<H;h++){
                for(int w=0;w<W;w++){
                   temp += data[i+h][j+w];
                }
            }
            if(temp > res) res = temp;
        }
    }
    cout << res << endl;
}