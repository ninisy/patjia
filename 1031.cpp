#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	
	cin>>s;
	int len = s.length(),max,n2;
	if(len<5||len>80)
		return 0;
	max = (len+2)/3;
	n2 = len+2-2*max;
	for(int i=0;i<max-1;i++){
		//printf("%s",s[i]);
		cout << s[i];
		for(int j=0;j<n2-2;j++)
			printf(" ");
		//printf("%s",s[len-i-1]);
		cout<<s[len-i-1]<<endl;
	}
	for(int i = max-1;i<len-max+1;i++)
		cout<<s[i];
		//printf("%s",s[i]);
	system("pause");
	return 0;
}
