#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	string n;
	string a[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	cin>>n;
	long long int s =0;
	vector<int> b;
	
	for(int i = 0;i<n.length();i++){
		s = s + (n[i]-'0');
	}
	do{
		b.push_back(s%10);
		s = s/10;
	}while(s!=0);
	cout<<a[b[b.size()-1]];
	for(int i = b.size()-2;i>=0;i--){
		cout<<" "<<a[b[i]];
	}
	system("pause");
	return 0;
}
