#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int* Pa = &a;
    int* Pb = &b;
    cout << do_some_awesome_work(Pa, Pb);
    return 0;
}
