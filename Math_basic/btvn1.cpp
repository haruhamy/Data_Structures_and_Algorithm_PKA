#include <stdio.h>

int max(int a, int b){
	return a<b? b :a;
}

int main(){
	int n; scanf("%d", &n);
	
	int a[n];
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	int sum1 = 0, sum2 = -1000; 
	
	//sum 2 ghi nhan ki luc
	
	for(int i=0; i<n; i++){
		sum1 += a[i];
		sum2 = max(sum1, sum2);
		if(sum1<0) sum1=0;
	}
	printf("%d", sum2);
}
