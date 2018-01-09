#include<iostream>
using namespace std;

int main(){
	int n,level,t=0,tmp=0;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>level;
		
		if(tmp<level){
			t = t + (level-tmp)*6+5;
		}else
			t = t + (tmp-level)*4+5;
		tmp = level;
	}
	cout<<t;
	system("pause");
	return 0;
}
