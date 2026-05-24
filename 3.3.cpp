#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int const n=1000;

int ile_z_s(string a){
	int i=0, w=0;
	char l=0;
	for(i=0; i<a.size(); i++){
		l=a[i];
		if(l=='!' || l=='$' || l=='%') w++;
	}
	return w;
}

int main(int argc, char** argv) {
	ifstream we("C:/cpp/hasla.txt");
	string hasla[n];
	string a="";
	char l=0;
	int i=0, j=0, temp=0;
	int l_znakow_spec[16];
	for(i=0; i<16; i++){
		l_znakow_spec[i]=0;
	}
	
	for(i=0; i<n; i++){
		we>>hasla[i];
	}
	
	for(i=0; i<n; i++){
		a=hasla[i];
		temp=l_znakow_spec[ile_z_s(a)];
		l_znakow_spec[ile_z_s(a)]=temp+1;
	}
	
	for(i=0; i<16; i++){
		cout<<i<<": "<<l_znakow_spec[i]<<endl;
	}
	
	for(i=0; i<n; i++){
		a=hasla[i];
		if(ile_z_s(a)==4) cout<<a;
	}
	
	return 0;
}
