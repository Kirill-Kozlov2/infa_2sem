#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int N;
    std::cin >> N;
    std::vector<int> coord(N + 1);
    coord[0] = 0;
    for (int j = 1; j <= N; ++j)
        std::cin >> coord[j];

    std::vector<int> d(N + 1, 0);
    std::vector<int> p(N + 1, 0);

    d[0] = 0;
    p[0] = 0;
    for (int j = 1; j <= N; j++)
    {
        p[j] = j;
        if (j == 1)
            d[j] = coord[j];
        else if (coord[j] + d[j - 1] > coord[j] + d[j - 2])
                d[j] = coord[j] + d[j - 1];
        else
            {
                d[j] = coord[j] + d[j - 2];
                p[j - 1] = 0;
                p[j - 2] = j - 2;
            }
    }
    std::cout << d[N] << '\n';
    for (int j = 1; j <= N; j++)
    {
        if (p[j] != 0)
            std::cout << j << ' ';
    }
    return 0;
}
