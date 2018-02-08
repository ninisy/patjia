#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(string a, string b){
	string u1, u2;
	u1 = a+b;
	u2 = b+a;
	for(int i=0;i<u1.size();i++){
		if(u1[i] != u2[i])
			return u1[i]<u2[i];
	}
	return false;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<string> number;
	string tmp;
	for(int i=0;i<n;i++){
		cin>>tmp;
		number.push_back(tmp);
	}
	sort(number.begin(), number.end(), cmp);
	/*for(int i=0;i<number.size();i++){
		if(i==0&&number[i].size()!=)
			printf("%d",stoi(number[i]));
		else
			printf("%s",number[i].c_str());
	}*/
	string s;
	for(int i=0;i<number.size();i++)
		s += number[i];
	while(s.length()!=0 && s[0]=='0')
		s.erase(s.begin());
	if(s.length()!=0)
		cout<<s;
	else
		cout<<0;
	system("pause");
	return 0;
}
