#include <iostream>
#include <vector>
using namespace std;


int robRange(vector<int>& values, int start, int end){
	
	// 1��dp˼·�����start,end��������Ľ� 
    
    return ;   // ����values 
}

int rob(vector<int>& values) { 

	
	// 2�������ʼ״̬ 
	
	
	// 3�����ؽϴ�Ľ�� 
    return max(robRange(���1), robRange(���2));
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


