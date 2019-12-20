#include <iostream>

using namespace std;

int a[19+2][19+2];

int Search_right(int color, int row, int col, int cnt)
{
    for(;color == a[row][col+1];col++) ++cnt;

    return (cnt == 5) ? 1:0; 
}

int Search_right_down(int color, int row, int col, int cnt)
{
    for(;color==a[row+1][col+1];row++, col++) ++cnt;
    
    return (cnt == 5) ? 1:0;
}

int Search_down(int color, int row, int col, int cnt)
{
    for(;color == a[row+1][col];row++) ++cnt;

    return (cnt ==5)? 1: 0;
}

int Search_right_up(int color, int row, int col, int cnt)
{
    for(;color == a[row-1][col+1]; --row, ++col) ++cnt;

    return (cnt == 5)? 1:0;
}


int main()
{
    for(int i=1;i<19;i++){
        for(int j=1;j<19;j++){
            cin >> a[i][j];
        }
    }
    // end of input

    for(int i=1;i<19;i++){
        for(int j=1;j<19;j++){
            if(a[i][j] != 0){

                if(a[i][j-1] != a[i][j] && Search_right(a[i][j], i, j, 1) == 1){
                    cout << a[i][j] << " " << i << " " << j << endl;
                }
                if(a[i-1][j-1] != a[i][j] && Search_right_down(a[i][j], i, j, 1) == 1){
                    cout << a[i][j] << " " << i << " " << j << endl;
                }
                if(a[i-1][j] != a[i][j] && Search_down(a[i][j], i, j, 1) == 1){
                    cout << a[i][j] << " " << i << " " << j << endl;
                }
                if(a[i+1][j-1] != a[i][j] && Search_right_up(a[i][j], i, j, 1) == 1){
                    cout << a[i][j] << " " << i << " " << j << endl;
                }                
            }
        }
    }

}