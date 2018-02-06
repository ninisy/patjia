#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct inf{
	string name, id;
	int grade;
};
bool cmp1(inf a, inf b){
	return a.grade>b.grade;
}
int main(){
	int n;
	scanf("%d",&n);
	vector<inf> female, male;
	string gender;
	for(int i=0;i<n;i++){
		inf temp;
		cin>>temp.name>>gender>>temp.id>>temp.grade;
		if(gender=="M")
			male.push_back(temp);
		else
			female.push_back(temp);
	}
	sort(male.begin(), male.end(), cmp1);
	sort(female.begin(), female.end(), cmp1);
	bool flag = true;
	if(female.size()==0){
		printf("Absent\n");
		flag=false;}
	else
		cout<<female[0].name<<" "<<female[0].id<<endl;
	if(male.size()==0){
		printf("Absent\n");
		flag = false;}
	else
		cout<<male[male.size()-1].name<<" "<<male[male.size()-1].id<<endl;
	if(flag)
		printf("%d\n",female[0].grade - male[male.size()-1].grade);
	else
		printf("NA\n");
	system("pause");
	return 0;
}
