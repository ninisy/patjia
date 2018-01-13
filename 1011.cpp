#include<iostream>
#include<string>
using namespace std;

int main(){
	double a[3],m = 0.0,sum=1;
	string c = "WTL";
	int t[3];
	for(int i = 0;i<3;i++){
		
		cin>>a[0]>>a[1]>>a[2];
		m = (a[0]>a[1])? a[0]:a[1];
		m = (m>a[2])?m:a[2];
		t[i] = (a[0]>a[1])? 0:1;
		t[i] = (m>a[2])?t[i]:2;
		sum = sum*m;
	}
	cout<<c[t[0]]<<" "<<c[t[1]]<<" "<<c[t[2]]<<" ";
	printf("%.2f",(sum*0.65-1)*2);

	system("pause");
	return 0;
}
