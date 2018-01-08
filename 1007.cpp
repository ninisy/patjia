#include<iostream>
using namespace std;

int main(){
	int k;
	cin>>k;
	int *a = new int[k],l =0,r = k-1,t = 0,tempindex=0,sum = -1;
	for(int i=0;i<k;i++){
		cin>>a[i];
		t = t+a[i];
		if(t<0){
			t=0;
			tempindex = i+1;
		}
		else if(t>sum){
			sum = t;
			l= tempindex;
			r = i;
		}
	}
	if(sum<0) sum = 0;
	cout<<sum<<" "<<a[l]<<" "<<a[r]<<endl;
	system("pause");
	return 0;
}
