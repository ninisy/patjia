#include<iostream>
#include<string>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int t,*f = new int [n](),*c = new int [n](),*l = new int [n]();
	string father,child;
	for(int i = 0;i<m;i++){
		cin>>father>>t;
		c[stoi(father)-1] = t;
		for(int j= 0;j<t;j++){
			cin>>child;
			f[stoi(child)-1] = stoi(father)-1;
		}
	}
	int max = 0;
	for(int i = 1;i<n;i++){
		l[i] = l[f[i]]+1;
		if(max<l[i])
			max = l[i];
	}
	
	for(int i = 0; i<=max;i++){
		int num = 0;
		for(int j = 0;j<n;j++){
			if(l[j]==i&&c[j]==0)
				num ++;
		}
		if(i!=max)
			cout<<num<<" ";
		else
			cout<<num<<endl;
	}

	system("pause");
	return 0;
}
