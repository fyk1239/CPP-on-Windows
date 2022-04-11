#include <iostream>
#include <vector>
using namespace std;


int robRange(vector<int>& values, int start, int end){
	
	// 1、dp思路解决【start,end】子问题的解 
    
    return ;   // 最大的values 
}

int rob(vector<int>& values) { 

	
	// 2、处理初始状态 
	
	
	// 3、返回较大的结果 
    return max(robRange(情况1), robRange(情况2));
}




int main(){
	int len;
	while(cin>>len){
		int *a = new int[len];
		for(int i=0; i<len;i++){
			cin>>a[i];
		}
		vector<int> values(a, a+len);
		cout<<rob(values)<<endl;
	} 
	return 0;
	
} 


