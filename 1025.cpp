#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct record{
	long long int id;
	int score, frank, lnum, lrank;
};
bool cmp1(record a, record b){
	if(a.score>b.score)
		return a.score>b.score;
	else if(a.score==b.score&&a.id<b.id)
		return a.id<b.id;
	return false;
}
int main(){
	int n,cnt=0,r=1;;
	vector<record> a;
	cin>>n;
	for(int i= 0;i<n;i++){
		int num,t=cnt,k=1,score;
		long long int id;
		record temp;
		cin>>num;
		for(int j=0;j<num;j++){
			cin>>id>>score;
			temp.id = id;
			temp.score = score;
			temp.lnum = i+1;
			cnt++;
			a.push_back(temp);
		}
		sort(a.begin()+t,a.end(),cmp1);
		a[t].lrank =k;
		for(int j=t;j<cnt-1;j++){
			if(a[j].score!=a[j+1].score)
				k = j-t+2;
			a[j+1].lrank=k;

		}
	}
	sort(a.begin(), a.end(),cmp1);
	cout<<cnt<<endl;
	a[0].frank = r;
	for(int i=0;i<a.size()-1;i++){
		if(a[i].score!=a[i+1].score)
			r = i+2;
		a[i+1].frank = r;
		printf("%013lld ",a[i].id);//important
		cout<<a[i].frank<<" "<<a[i].lnum<<" "<<a[i].lrank<<endl;
	}
	printf("%013lld ",a[a.size()-1].id);
	cout<<a[a.size()-1].frank<<" "<<a[a.size()-1].lnum<<" "<<a[a.size()-1].lrank<<endl;
	system("pause");
	return 0;
}
