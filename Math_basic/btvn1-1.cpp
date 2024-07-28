#include <stdio.h>

int value[100] = {}, next[100] = {}, prev[100] ={};

int start[100], end[100];

int dem = 0;

void add(int u, int v){
	
	dem++; value[dem] = v, next[dem] = 0;
	
	if(start[u] == 0){
		
		start[u] = dem;
		
		end[u] = dem;
	}else{
		prev[dem] = end[u];
		
		next[end[u]] = dem;
		
		end[u] = dem;
	}
	dem++; value[dem] = u, next[dem] = 0;
	
	if(start[v] == 0){
		
		start[v] = dem;
		
		end[v] = dem;
	}else{
		prev[dem] = end[v];
		
		next[end[v]] = dem;
		
		end[v] = dem;
	}
}
void list(int i){
	int j; j = start[i];
	
	while(next[j] != 0){
		printf("%d ", value[j]);
		
		j=next[j];
	}
	printf("%d ", value[j]);
}
void pop(int u, int v){
	int j = start[u];
	
	while(next[j] != 0){
		if(value[j] == v) break;
		j=next[j];
	}
	next[prev[j]]= next[j];
	prev[next[j]] = prev[j];
	if(prev[j] == 0){
		 start[u] = next[j];
		 
		 prev[next[j]]==0;
	}
	int k = start[v];
	
	while(next[k] != 0){
		if(value[k] == u) break;
		k=next[k];
	}
	next[prev[k]] =next[k];
	prev[next[k]] = prev[k];
	if(prev[j] == 0){
		 start[v] = next[k];
		 
		 prev[next[k]]==0;
	}	
}
int main(){	
	while(1){
		printf("Nhap lua chon: \n");
		printf("1. them vao danh sach u v \n");
		printf("2. in ra danh sach ban be u \n");
		printf("3. xoa ban be hai nguoi u va v \n");
		printf("4. thoat \n");
		int lc; scanf("%d", &lc);
		
		if(lc == 1){
			
			int u, v; scanf("%d", &u); scanf("%d", &v);
			
			add(u, v);
		}
		if(lc == 2){
			int i; scanf("%d", &i);
			
			list(i);
		}
		if(lc == 3){
			int u, v; scanf("%d", &u); scanf("%d", &v);
			
			pop(u, v); 
		}
		if(lc== 4){
//			for(int i=0; i<20; i++){
//				printf("%d ", i);
//			}
//			printf("\n");
//			for(int i=0; i<20; i++){
//				printf("%d ", value[i]);
//			}
//			printf("\n");
//			for(int i=0; i<20; i++){
//				printf("%d ", next[i]);
//			}
//			printf("\n");
//			for(int i=0; i<20; i++){
//				printf("%d ", prev[i]);
//			}
//			printf("\n");
//			for(int i=1; i<=5; i++){
//				printf("%d ", i);
//			}
//			printf("\n");
//			for(int i=1; i<=5; i++){
//				printf("%d ", start[i]);
//			}
//			printf("\n");
//			for(int i=1; i<=5; i++){
//				printf("%d ", end[i]);
//			}
//			printf("\n");
			
			break;
		}
	}
}
