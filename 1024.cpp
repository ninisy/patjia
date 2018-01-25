#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool ispalin(string a){
	for(int i=0;i<a.size()/2;i++){
		if(a[i] != a[a.size()-i-1])
			return false;
	}
	return true;
}
string sum(string a, string b){
	int flag1 = 0,tt=0;
	string ssum;
	for(int i=a.size()-1;i>=0;i--){
		tt = (a[i]-'0')+(b[i]-'0')+flag1;
		if(tt>=10){
			flag1 = 1;
			tt = tt-10;
		}else
			flag1=0;
		ssum.push_back(tt+'0');
	}
	if(flag1==1)
		ssum.push_back(1+'0');
	reverse(ssum.begin(),ssum.end());
	return ssum;
}
int main(){
	string n,m,s="";
	int k,t=0;
	bool flag=false;
	cin>>n>>k;
	m=n;
	
	while(!ispalin(n)&&t<k){
		t++;
		reverse(m.begin(),m.end());
		s = sum(n,m);
		if(ispalin(s)){
			flag = true;
			cout<<s<<endl;
			cout<<t<<endl;
			break;
		}
		n = s;
		m = n;
	}
	if(!flag){
		cout<<n<<endl;
		cout<<t<<endl;
	}
	system("pause");
	return 0;
}
