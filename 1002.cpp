#include<iostream>
using namespace std;

int main(){
	int k1,k2,e,max=0;
	float c;
	float a[1000]={0};
	cin >> k1;
	
	for(int i = 0;i<k1;i++){
		cin>>e>>c;
		if(max<e)
			max = e;
		a[e] = a[e]+c;
	}
	cin >> k2;
	for(int i = 0;i<k2;i++){
		cin>>e>>c;
		if(max<e)
			max = e;
		a[e] = a[e]+c;
	}
	//cout<<(max+1);
	int m = max+1;
	for(int i = max;i>=0;i--){
		if(a[i]==0)
			m--;
	}
	cout << m;
	for(int i = max;i>=0;i--){
		if(a[i]!=0.0)//这里必须是0.0
			printf(" %d %.1f",i,a[i]);
	}
	cout<<endl;

	system("pause");
	return 0;
}
