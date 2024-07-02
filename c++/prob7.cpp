#include <iostream>
using namespace std;

int main(){
	
	int y1,m1,d1,y2,m2,d2;
	cin>>y1>>m1>>d1>>y2>>m2>>d2;
	if ((y1*10000+m1*100+d1)<(y2*10000+m2*100+d2)){
		cout << -1;
	}
	else if((y1*10000+m1*100+d1)>(y2*10000+m2*100+d2)){
		cout << 1;
	}
	else{
		cout << 0;
	}
	
	
	return 0;
}
