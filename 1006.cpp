#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct record{
	string id;
	int in;
	int out;
};

int main(){
	int n,max = 0,min = 999999999,mini=0,maxi=0;
	cin>>n;
	record *a = new record [n];
	string iin,oout;
	for(int i =0;i<n;i++){
		cin>>a[i].id>>iin>>oout;
		a[i].in = (iin[0]*10+iin[1])*3600+(iin[3]*10+iin[4])*60+(iin[6]*10+iin[7]);
		a[i].out = (oout[0]*10+oout[1])*3600+(oout[3]*10+oout[4])*60+(oout[6]*10+oout[7]);
		if(min>a[i].in){
			min = a[i].in;
			mini = i;
		}
		if(max<a[i].out){
			max = a[i].out;
			maxi = i;
		}
	}
	cout<<a[mini].id<<" "<<a[maxi].id<<endl;

	system("pause");
	return 0;
}
