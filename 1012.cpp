#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
bool cmp1(double a,double b){
	return a>b;
}
int main(){
	int n,m;
	cin>>n>>m;
	string *id = new string [n];
	int *C = new int[n],*M = new int [n],*E = new int[n];
	int *CC = new int[n],*MM = new int [n],*EE = new int[n];
	double *A = new double[n],*AA = new double[n];
	for(int i=0;i<n;i++){
		cin>>id[i]>>C[i]>>M[i]>>E[i];
		A[i] = (C[i]+M[i]+E[i])/3.0;
		CC[i]=C[i];MM[i]=M[i];EE[i]=E[i];AA[i]=A[i];
	}
	sort(CC,CC+n,cmp);
	sort(MM,MM+n,cmp);
	sort(EE,EE+n,cmp);
	sort(AA,AA+n,cmp1);
	string idd;
	for(int i = 0;i<m;i++){
		cin>>idd;
		int rc=0,rm=0,re=0,ra=0,mmin = 2001;
		bool flag = false;
		for(int j =0;j<n;j++){
			if(idd.compare(id[j])==0){
				for(int l = 0;l<n;l++){
					if(C[j]==CC[l]){
						rc = l+1;
						if(mmin>rc)
							mmin = rc;
						break;
					}
				}
				for(int l = 0;l<n;l++){
					if(M[j]==MM[l]){
						rm = l+1;
						if(mmin>rm)
							mmin = rm;
						break;
					}
				}
				for(int l = 0;l<n;l++){
					if(E[j]==EE[l]){
						re = l+1;
						if(mmin>re)
							mmin = re;
						break;
					}
				}
				for(int l = 0;l<n;l++){
					if(A[j]==AA[l]){
						ra = l+1;
						if(mmin>ra)
							mmin = ra;
						break;
					}
				}
			
			flag = true;
			break;
			}else
				continue;
		}
		if(!flag)
			cout<<"N/A"<<endl;
		else{
			if(ra==mmin){
				cout<<mmin<<" "<<"A"<<endl;
				continue;
			}
			else if(rc==mmin){
				cout<<mmin<<" "<<"C"<<endl;
				continue;
			}
			else if(rm==mmin){
				cout<<mmin<<" "<<"M"<<endl;
				continue;
			}
			else{
				cout<<mmin<<" "<<"E"<<endl;
				continue;
			}
		}
	}
	system("pause");
	return 0;

}
