#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> horizon;
vector<vector<int>> vertical;
vector<vector<int>> inter;
bool intersect(vector<int>i, vector<int>j);
int main(){
	int N;
	cin >>N;
	
	for (int i=0; i<N; i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if (b==d){ //수평선분인경우
			vector<int> k = {a,b,c,d};
			horizon.push_back(k); 
		}
		else if(a==c){ //수직 선분 
			vector<int> p = {a,b,c,d};
			vertical.push_back(p); 
		} 
	}
	for (auto hor: horizon){
		for (auto ver: vertical){
			if(intersect(hor,ver)){
				vector<int> q; 
				q.push_back(ver[0]); //교차점저장 
				q.push_back(hor[1]);
				inter.push_back(q); 
			}
		}
	}
	sort(inter.begin(), inter.end());
	cout <<endl;
	for (auto n: inter){
		cout<<"["<<n[0]<<", "<<n[1]<<"]"<<endl;
	}
	return 0;
}
bool intersect(vector<int>hor, vector<int>ver){
	int hor_x1 =hor[0],hor_y=hor[1],hor_x2=hor[2]
	,ver_x=ver[0],ver_y1=ver[1],ver_y2=ver[3];
	
	//수직의 x좌표가 수평의 x좌표 사이에 있는지
	//수직의 y좌표가 수평의 y좌표와 만나는지
	if(ver_x>=hor_x1 && ver_x<=hor_x2 && ver_y1<=hor_y&& ver_y2>=hor_y)    
	{	
		return true;
	}
	else{
		return false;
	}	
}
