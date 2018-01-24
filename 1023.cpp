#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	string n;
	//long long int n,m;
	vector<int> b;
	int a[10]={0};
	cin>>n;
	int flag=0;
	for(int i=n.size()-1;i>=0;i--){
		int temp=0;
		a[n[i]-'0']++;
		temp = (n[i]-'0')*2+flag;
		if(temp>=10){//大于等于！！！
			flag=1;
			temp = temp-10;
		}
		else{
			flag=0;
		}
		a[temp]--;
		b.push_back(temp);
	}
	if(flag==1)
		b.push_back(1);
	for(int i=0;i<10;i++){
		if(a[i]!=0){
			cout<<"No"<<endl;
			for(int j=b.size()-1;j>=0;j--){
				cout<<b[j];
			}
			system("pause");
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	for(int j=b.size()-1;j>=0;j--)
		cout<<b[j];
	system("pause");
	return 0;
}
