#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}
