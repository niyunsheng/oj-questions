#include<cstdio>
#include<iostream> 
#include<string>

using namespace std;
int main() {
	string password = "NOIP@CCF";
	string tmp;
	string a;
	while(true){
		cin >> a;
		if( a == "Y"){
			cin >> tmp;
			if (tmp == password){
				printf("Success\n");
				break;
			}else{
				printf("Sorry\n");
			}
		}else{
			break;
		}
	}
	
	return 0;
}
