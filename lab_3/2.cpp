#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int N, M, mines;
    cin >> N >> M >> mines;
    N += 2;
    M += 2;
    int* a = new int [N*M];
    int** field = new int* [N];
    for (int l = 0; l < N; ++l){
        field[l] = a + l*M;
    }
    int i, j;
    for (i = 0; i < N; ++i){
        for (j = 0; j < M; ++j){
            field[i][j] = 0;
        }
    }
    for (int k = 0; k < mines; ++k){
        cin >> i >> j;
        for (int f=0;f<9; ++f){
            if (field[i-1+f/3][j-1+f%3] != -1){
                ++field[i-1+f/3][j-1+f%3];
            }
        }
        field[i][j] = -1;
    }
    for (i = 1; i < N-1; ++i){
        for (j = 1; j < M-1; ++j){
            cout << field[i][j]<<' ';
        }
        cout << endl;
    }
    delete [] a;
    delete [] field;
    return 0;
}
