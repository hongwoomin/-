#include <iostream>
using namespace std;

int main(){
	
	int data[8];
	for (int i=0; i<7; i++){
		cin >> data[i]; 
	}
	for (int j=0; j<7; j++){
        for (int k = j + 1; k < 7; k++){
            if (data[j] > data[k]){
                int tmp = data[j];
                data[j] = data[k];
                data[k] = tmp;
            }
        }
    }
	//중복제거 
	int s_data[7];
	int g =0;
	s_data[g++] = data[0];
	for (int m =1; m<7; m++){
		if (data[m-1]!=data[m]){
			s_data[g++] = data[m];
		}
	}
	int straight = 0;
	for (int x=0; x<g-4; x++){
		if(s_data[x+1]-s_data[x]==1 && s_data[x+2]-s_data[x+1]==1 
		&& s_data[x+3]-s_data[x+2]==1 && s_data[x+4]-s_data[x+3]==1 ){
			straight = 1;
			break;
		}
	}
	if (straight){
			cout<< "YES";
		}
	else{
		cout << "No";
	}
	return 0;
}

