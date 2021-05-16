#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool comp(string& a, string& b)
{
	if (a.size() > b.size())
		return false;

	for (int j = 0; j < a.size(); j++)
	{
		if (a[j] != b[j])
			return false;
	}

	return true;
}

int main()
{
	int m;
	cin >> m;
	vector<string> data(m);
	for (int i = 0; i < m; i++)
		cin >> data[i];

	vector<int> len(m);

	for (int i = 0; i < m; i++)
	{
		len[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (comp(data[j], data[i]))
				len[i] = max(len[i], len[j] + 1);
		}
	}

	int res = len[0];
	for (int j = 0; j < m; j++)
		res = max(res, len[j]);

	cout << res;
	return 0;
}
