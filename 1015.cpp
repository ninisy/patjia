#include<iostream>
#include<string>
#include<vector> 
#include<math.h>
using namespace std;
int toten(int a,int radix){
	int b = 0;
	vector<int> s;
	while(a!=0){
		s.push_back(a%radix); 
		a /=radix;
	}
	for(int i= 0;i<s.size();i++){
		b = s[i]+b*radix;
	}
	return b;
}
bool isprime(int a){
	if(a<=1) return false;//这里很重要
	for(int i=2;i*i<=a;i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}
/*bool isprime(int n) {  
    if(n <= 1) return false;  
    int sqr = int(sqrt(n * 1.0));  
    for(int i = 2; i <= sqr; i++) {  
        if(n % i == 0)  
            return false;  
    }  
    return true;  
}  */

int main(){
	int a,b;
	
	while(1){
		bool flag1=false,flag2=false;
		cin>>a;
		if(a<0)
			break;
		cin>>b;
		if(isprime(a))
			flag1=true;
		if(isprime(toten(a,b)))
			flag2=true;
		if(flag1==false){
			cout<<"No"<<endl;
			continue;
		}else if(flag2==true){
			cout<<"Yes"<<endl;
			continue;
		}
		else{
			cout<<"No"<<endl;
			continue;
		}

	}
	system("pause");
	return 0;
}
