#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct node{
	int poptime,endtime;
	queue<int> q;
};
int main(){
	int n,m,k,g,index=0,tmp;
	cin>>n>>m>>k>>g;
	/*node *window = new node [n];
	int *time = new int [k],*result = new int[k];
	bool *sorry = new bool[k];*/
	vector<int> time(k),result(k);
	vector<node> window(n);
	vector<bool> sorry(k, false);
	for(int i=0;i<n;i++){
		window[i].endtime = 0;
	}//得加这个呢，不然输出是错的。
 	for(int i = 0;i<k;i++){
		cin>>time[i];
	}
	for(int i= 0;i<m;i++){
		for(int j = 0;j<n;j++){
			if(index<k){
				window[j].q.push(time[index]);
				if(window[j].endtime>=540)
					sorry[index] = true;
				window[j].endtime += time[index];
				if(i==0)
					window[j].poptime = window[j].endtime;
				result[index] = window[j].endtime;
				index++;
			}
		}
	}
	while(index<k){
		int temptime = window[0].poptime,tempwin = 0;
		for(int i=1;i<n;i++){
			if(window[i].poptime<temptime){
				tempwin = i;
				temptime = window[i].poptime;
			}
		}
		if(window[tempwin].endtime >= 540)
			sorry[index] = true;
		window[tempwin].q.pop();
		window[tempwin].q.push(time[index]);
		window[tempwin].poptime += window[tempwin].q.front();
		
		window[tempwin].endtime +=time[index];
		result[index] = window[tempwin].endtime;
		index++;
	}
	for(int i = 0;i<g;i++){
		cin>>tmp;
		if(sorry[tmp-1])
			cout<<"Sorry"<<endl;
		else
			printf("%02d:%02d\n",(result[tmp-1]+480)/60,(result[tmp-1]+480)%60);//必须是02d
		}
	system("pause");
	return 0;
}
