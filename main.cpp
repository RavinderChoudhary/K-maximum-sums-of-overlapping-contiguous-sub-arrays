#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = arr.size();
	int k = 3;
	vector<int> pre_sum(n+1,0);
	for(int i=1;i<=n;i++)
	  pre_sum[i] = pre_sum[i-1] + arr[i-1];
	
	priority_queue<int,vector<int>,greater<int> > mnheap;
	for(int i=1;i<=n;i++){
	    for(int j=i;j<=n;j++){
	        int x = pre_sum[j] - pre_sum[i-1];
	        if(mnheap.size() < k)
	           mnheap.push(x);
	        else{
	           if(mnheap.top() < x){
	               mnheap.pop();
	               mnheap.push(x);
	           }
	        }
	    }
	}
	
	while(!mnheap.empty()){
	    cout<<mnheap.top()<<" ";
	    mnheap.pop();
	}
	return 0;
}
