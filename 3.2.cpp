#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int const n=1000;

void sito(bool *A, int dl){
	int i=0, j=0;
	
	for(i=0; i<dl; i++){
		A[i]=true;
	}
	
	A[0]=false;
	A[1]=false;
	
	for(i=2; i<dl; i++){
		if(A[i]){
			j=i+i;
			while(j<dl){
				A[j]=false;
				j+=i;
			}
		}
	}	
}

bool czy_w_zbiorze(char a, int *A, int dl){
	int i=0;
	for(i=0; i<dl; i++){
		if(A[i]==a) return true;
	}
	return false;
}

int main(int argc, char** argv) {
	ifstream we("C:/cpp/hasla.txt");
	string hasla[n];
	string a="";
	char l=0;
	int i=0, zakres_l_pierwszych=300, j=0;
	int l_pierwsze[zakres_l_pierwszych];
	bool A[zakres_l_pierwszych];
	bool flaga=true;
	sito(A, zakres_l_pierwszych);
	
	for(i=0; i<n; i++){
		we>>hasla[i];
	}
	
	j=0;
	for(i=0; i<zakres_l_pierwszych; i++){
		if(A[i]){
			l_pierwsze[j]=i;
			j++;
		}
	}
	
	for(i=0; i<n; i++){
		a=hasla[i];
		flaga=true;
		for(j=0; j<a.size(); j++){
			l=a[j];
			if(!czy_w_zbiorze(l, l_pierwsze, zakres_l_pierwszych)) flaga=false;
		}
		if(flaga) cout<<a<<endl;
	}
	
	return 0;
}
