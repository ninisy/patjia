#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,m,e,max =-1;
	double c,*a = new double[1000](),*b = new double[1000000]();
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>e>>c;
		a[e] = a[e] + c;
		if(max<e)
			max = e;
	}
	cin>>m;
	int mmax = max;
	for(int i = 0;i<m;i++){
		cin>>e>>c;
		for(int j = 0;j<=max;j++){
			b[j+e] = c*a[j]+b[j+e];
			if(j+e>mmax)
				mmax = j+e;
		}
	}
	int num=0;
	for(int i = 0;i<=mmax;i++){
		if(b[i]!=0)
			num++;
	}
	cout<<num;
	for(int i = mmax;i>=0;i--){
		if(b[i]!=0)
			printf(" %d %.1f",i,b[i]);
	}
	system("pause");
	return 0;
}
