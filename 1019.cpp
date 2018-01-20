#include<iostream>
#include<vector>
using namespace std;

bool isp(vector<int> a){
	
	for(int i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-i-1]){
			return false;
		}
	}
	return true;
}
int main(){
	long long int n,b;
	vector<int> a;
	cin>>n>>b;
	do{
		a.push_back(n%b);
		n /= b;
	}while(n!=0);
	if(isp(a))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	cout<<a[a.size()-1];
	for(int i=a.size()-2;i>=0;i--){
		cout<<" "<<a[i];
	}
	system("pause");
	return 0;
}
