#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int const n=100;

int main(int argc, char** argv) {
	ifstream we("C:/cpp/hasla.txt");
	string hasla[n];
	string a="";
	char l=0;
	int i=0, j=0, licznik=0;
	bool flaga=false;
	
	for(i=0; i<n; i++){
		we>>hasla[i];
	}
	
	for(i=0; i<n; i++){
		a=hasla[i];
		if(a.size()>=12){
			flaga=false;
			for(j=0; j<a.size(); j++){
				l=a[j];
				if(l=='!' || l=='$' || l=='%')
					flaga=true;
			}
			if(flaga) licznik++;
		}
	}
	
	cout<<licznik;
	
	return 0;
}
