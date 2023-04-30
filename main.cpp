#include <bits/stdc++.h>

using namespace std;

int usercnt;
int contestcnt;

map<string,int> touid;
map<int,string> toname;
map<int,string> toschool;

string t1name,t2name,t3name,t4name;
int t1id,t2id,t3id,t4id;

int main(){
	cout<<"请确认已去除 user.csv 第一行的数据类型和用户名空格(Y/N)"<<endl;
	string s; cin>>s; if(s != "Y") return 0;
	cout<<endl;
	freopen("user.csv","r",stdin);
	freopen("tmpuser.txt","w",stdout);
	string tmp;
	while(cin>>tmp){
		usercnt++;
		for(int i = 0;i<tmp.size();i++){
			if(tmp[i] == ',') cout<<" ";
			else cout<<tmp[i];
		}
		cout<<endl;
	}
	freopen("CON","r",stdin);
	freopen("CON","w",stdout);
	cin.clear(); cout.clear();
	freopen("tmpuser.txt","r",stdin);
	for(int i = 1;i<=usercnt;i++){
		int a; string b; cin>>a>>b;
		touid[b] = a;
	}
	freopen("CON","r",stdin);
	freopen("CON","w",stdout);
	cin.clear(); cout.clear();
	cout<<"请确认已去除 contest.csv 第一行和其他地方的数据类型和用户名空格(Y/N)"<<endl;
	cin>>s; if(s != "Y") return 0;
	cout<<endl;
	freopen("contest.csv","r",stdin);
	freopen("tmpuid.txt","w",stdout);
	while(cin>>tmp){
		contestcnt++;
		for(int i = 0;i<tmp.size();i++){
			if(tmp[i] == ',') cout<<" ";
			else cout<<tmp[i];
		}
		cout<<endl;
	}
	freopen("CON","r",stdin);
	freopen("CON","w",stdout);
	cin.clear(); cout.clear();
	freopen("tmpuid.txt","r",stdin);
	freopen("contestuid.txt","w",stdout);
	for(int i = 1;i<=contestcnt;i++){
		string a; cin>>a;
		cout<<touid[a]<<endl;
	}
	freopen("CON","r",stdin);
	freopen("CON","w",stdout);
	cin.clear(); cout.clear();
	cout<<"请输入四道题的名称"<<endl;
	cin>>t1name; cout<<endl;
	cin>>t2name; cout<<endl;
	cin>>t3name; cout<<endl;
	cin>>t4name; cout<<endl;
	cout<<"请输入四道题的ID"<<endl;
	cin>>t1id; cout<<endl;
	cin>>t2id; cout<<endl;
	cin>>t3id; cout<<endl;
	cin>>t4id; cout<<endl;
	freopen("md.bat","w",stdout);
	char out[100];
	for(int i = 1;i<=contestcnt;i++){
		sprintf(out,"FJ-%.3d",i);
		cout<<"md"<<" "<<out<<endl;
		cout<<"cd"<<" "<<out<<endl;
		cout<<"md"<<" "<<t1name<<endl;
		cout<<"md"<<" "<<t2name<<endl;
		cout<<"md"<<" "<<t3name<<endl;
		cout<<"md"<<" "<<t4name<<endl;
		cout<<"cd .."<<endl;
	}
	freopen("CON","r",stdin);
	freopen("CON","w",stdout);
	cin.clear(); cout.clear();
	cout<<"请运行 md.bat 新建选手文件夹(Y/N)"<<endl;
	cin>>s; if(s != "Y") return 0;
	freopen("stuinfo.csv","r",stdin);
	freopen("tmpstuinfo.txt","w",stdout);
	for(int i = 1;i<=usercnt;i++){
		cin>>tmp;
		for(int i = 0;i<tmp.size();i++){
			if(tmp[i] == ',') cout<<" ";
			else cout<<tmp[i];
		}
		cout<<endl;
	}
	freopen("CON","r",stdin);
	freopen("CON","w",stdout);
	cin.clear(); cout.clear();
	freopen("tmpstuinfo.txt","r",stdin);
	for(int i = 1;i<=usercnt;i++){
		int id; string cla; string name;
		cin>>id>>cla>>name;
		toschool[id] = cla;
		toname[id] = name;
	}
	freopen("CON","r",stdin);
	freopen("CON","w",stdout);
	cin.clear(); cout.clear();
	freopen("contestuid.txt","r",stdin);
	freopen("move.bat","w",stdout);
	char codename[300];
	for(int i = 1;i<=contestcnt;i++){
		int id; cin>>id;
		sprintf(out,"FJ-%.3d",i);
		sprintf(codename,"U%d_P%d_R************************_S*@*.cc.normal",id,t1id);
		cout<<"move "<<codename<<" "<<out<<"/"<<t1name<<endl;
		sprintf(codename,"U%d_P%d_R************************_S*@*.cc.normal",id,t2id);
		cout<<"move "<<codename<<" "<<out<<"/"<<t2name<<endl;
		sprintf(codename,"U%d_P%d_R************************_S*@*.cc.normal",id,t3id);
		cout<<"move "<<codename<<" "<<out<<"/"<<t3name<<endl;
		sprintf(codename,"U%d_P%d_R************************_S*@*.cc.normal",id,t4id);
		cout<<"move "<<codename<<" "<<out<<"/"<<t4name<<endl;
	}
	freopen("CON","r",stdin);
	freopen("CON","w",stdout);
	cin.clear(); cout.clear();
	freopen("contestuid.txt","r",stdin);
	freopen("namelist.csv","w",stdout);
	for(int i = 1;i<=contestcnt;i++){
		int uid; cin>>uid;
		printf("FJ-%.3d",i);
		cout<<",";
		cout<<toname[uid]<<",";
		cout<<toschool[uid]<<endl;
	}
	freopen("CON","r",stdin);
	freopen("CON","w",stdout);
	cin.clear(); cout.clear();
	freopen("rename.bat","w",stdout);
	for(int i = 1;i<=contestcnt;i++){
		sprintf(out,"FJ-%.3d",i);
		cout<<"cd "<<out<<endl;
		cout<<"cd "<<t1name<<endl;
		cout<<"ren *.* "<<t1name<<".cpp"<<endl;
		cout<<"cd .."<<endl;
		cout<<"cd "<<t2name<<endl;
		cout<<"ren *.* "<<t2name<<".cpp"<<endl;
		cout<<"cd .."<<endl;
		cout<<"cd "<<t3name<<endl;
		cout<<"ren *.* "<<t3name<<".cpp"<<endl;
		cout<<"cd .."<<endl;
		cout<<"cd "<<t4name<<endl;
		cout<<"ren *.* "<<t4name<<".cpp"<<endl;
		cout<<"cd .."<<endl;
		cout<<"cd .."<<endl;
	}
	freopen("CON","r",stdin);
	freopen("CON","w",stdout);
	cin.clear(); cout.clear();
	return 0;
}
