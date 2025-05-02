#include <iostream>
using namespace std;

bool ch[100];
bool xopt[100];
int n, w;
int gtri[100];
int klg[100];
int fopt = 0;

int tonggtri(){
	int tong=0;
	for(int i=0; i<n; i++){
		tong += gtri[i]*ch[i];
	}
	return tong;
}

int tongklg(){
	int tong = 0;
	for(int i=0; i<n; i++){
		tong += klg[i]*ch[i];
	}
	return tong;
}

void ktaocauhinh(){
	cin>>n>>w;
	for(int i=0; i<n; i++){
		ch[i] = 0;
		cin>>gtri[i];
	}
	for(int i=0; i<n; i++){
		cin>>klg[i];
	}
}

bool iscauhinhcuoi(){
	for(int i=0; i<n; i++){
		if(!ch[i]) return 0;
	}
	return 1;
}

void sinhcauhinh(){
	int x = n-1;
	while(ch[x]==1){
		ch[x] = !ch[x];
		x--;
	}
	ch[x] = !ch[x];
}

bool kt(){
	if(tongklg()>w) return 0;
	if(tonggtri()>fopt) return 1;
	else return 0;
}

void update(){
	for(int i=0; i<n; i++){
		xopt[i] = ch[i];
	}
}

int main(){
	ktaocauhinh();
	while(!iscauhinhcuoi()){
		if(kt()){
			fopt = tonggtri();
			update();
		} 
		sinhcauhinh();
	}
	if(kt()){
		fopt = tonggtri();
		update();
	} 
	cout<<fopt<<endl;
	for(int i=0; i<n; i++){
		cout<<xopt[i]<<" ";
	}
	return 0;
}