#include<iostream>
#include<string>
using namespace std;

int main() {
	string a, b, c;
	long long int tmp;
	cin >> a >> b;
	tmp = stoi(a) + stoi(b);
	c = to_string(tmp);
	int l = c.length();
	if (tmp < 0) {
		cout << "-";
		for (int i = 1; i < l; i++) {
			if ((l - i - 1) % 3 == 0&&(l - i - 1) / 3 != 0)
				cout << c[i] << ",";
			else
				cout << c[i];
		}
	}
	else{
			for (int i = 0; i < l; i++) {
				if ((l - i - 1) % 3 == 0&& (l - i - 1) / 3!=0)
					cout << c[i] << ",";
				else
					cout << c[i];
			}
		}
	

	system("pause");
	return 0;
}
