#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
void yici(string s,long long a,long long c); 
void erci(string s,long long a,long long c);
int main(){
	cout<<"�����뺯������:";
	string hs;
	cin>>hs;
	if(hs=="һ�κ���"){
		cout<<"�����뺯��:";
		string hs1;
		cin>>hs1;
		long long a,b;
		cout<<"������ȡֵ��Χ:";
		cin>>a>>b;
		yici(hs1,a,b);
	}else if(hs=="���κ���"){
		cout<<"�����뺯��:";
		string hs1;
		cin>>hs1;
		long long a,b;
		cout<<"������ȡֵ��Χ:";
		cin>>a>>b;
		erci(hs1,a,b);
	}else if(hs=="�ֶκ���"){	
		long long a,m,n;
		cout<<"������ֶθ���:";
		cin>>a;
		string hs1;
		for(int i=1;i<=a;i++){
			long long max=-10000000000000000;
			cout<<"�������"<<i<<"�ֶεĺ���:";
			cin>>hs1;
			cout<<"������˷ֶεĺ���ȡֵ��Χ:";
			cin>>m,n;
			if(max>n){
				MessageBox(0,"Erro!!!","Erro!!!",64+MB_OK);
				return 0;
			}
			max=n;
			int len=hs1.size(),cnt=0;
			for(int i=0;i<len;i++){
				if(hs1[i]=='x'){
					cnt++;
				}
				if(hs1[i]=='^'){
					cnt++;
				}
			}
			if(cnt==1||cnt==0){
				yici(hs1,m,n);
			}else if(cnt>1){
				erci(hs1,m,n);
			}
		} 
	}
	Sleep(1000000000); 
}
void yici(string s,long long a,long long c){
	long long k=0,b=0,pos=1,cnt=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='x'){
			cnt++;
		}
	}
	if(cnt>1){
		MessageBox(0,"Erro","Erro",64+MB_OK);
	}else{
		for(int  i=0;i<len;i++){
			if(pos==1&&s[i]>='0'&&s[i]<='9'){
				k=k*10+s[i]-'0';
			}else if(s[i]=='x'){
				pos=2;
			}else if(pos==2&&s[i]>='0'&&s[i]<='9'){
				b=b*10+s[i]-'0';
			}
		}
		if(k==0&&cnt>=1)	k++;
		for(int i=a;i<=c;i++){
			if(cnt==1){
				cout<<"��x="<<i<<"ʱ";
				cout<<"y="<<k*i+b<<endl;
			}else if(cnt==0){
				cout<<"��x="<<i<<"ʱ";
				cout<<"y="<<k+b<<endl;
			}	
		}
		}
}
void erci(string s,long long a,long long x){
	long long k=0,b=0,pos=1,c=0,cnt=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='x'){
			cnt++;
		}
	}
	if(cnt>2){
		MessageBox(0,"Erro","Erro",64+MB_OK);
	}else{
		for(int  i=0;i<len;i++){
			if(pos==1&&s[i]>='0'&&s[i]<='9'){
				k=k*10+s[i]-'0';
			}else if(s[i]=='x'){
				pos++;
			}else if(s[i]=='^'){
				pos++;
			}else if(pos==2&&s[i]>='0'&&s[i]<='9'&&s[i-1]!='^'){
				b=b*10+s[i]-'0';
			}else if(pos==3&&s[i]>='0'&&s[i]<='9'){
				c=c*10+s[i]-'0';
			}
		}
		if(k==0&&cnt>=1)	k++;
		if(k==0&&cnt==2)	b++;
		for(int i=a;i<=x;i++){
			if(cnt==2){
				cout<<"��x="<<i<<"ʱ";
				cout<<"y="<<k*i*i+b*i+c<<endl;
			}else if(cnt==1){
				cout<<"��x="<<i<<"ʱ";
				cout<<"y="<<k*i*i+b+c<<endl;
			}else if(cnt==0){
				cout<<"��x="<<i<<"ʱ";
				cout<<"y="<<k+b+c<<endl;
			}
		}
	}
}
