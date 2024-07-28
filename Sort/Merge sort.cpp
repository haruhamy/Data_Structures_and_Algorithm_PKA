#include <bits/stdc++.h>

using namespace std;

int tmp[1000005];
void merge_sort(int a[], int l, int r){
	if(l >= r){ //nếu dãy cần sắp xếp chỉ có 1 phàn tử
		return;
	}
	int mid = (l+r) / 2; //tính giá trị mid  
	merge_sort(a, l, mid); //gọi đệ quy mảng bên trái
	merge_sort(a, mid + 1, r); //gọi đệ quy mảng bên phải 
	cout << "l = "<< l << " r = " << r << "\n"; 
	int i = l;
	int j = mid + 1;
	int idx = 0;
	while(i <= mid && j <= r){
		if (a[i] < a[j]){
			tmp[idx++] = a[i++];
		}else{
			tmp[idx++] = a[j++];
		}
	}	
	while (i <= mid){
		tmp[idx++] = a[i++];
	}
	while(j <= r){
		tmp[idx++] = a[j++];
	}
	// cout << idx << endl;
	for (int k = 0; k < idx; k++){
		a[l + k] = tmp[k];
	}
}
int main(){
	int n; cin >> n; int a[n];
	for ( int i= 0; i < n ; i++){
		cin >> a[i];
	}
	merge_sort(a, 0, n - 1);
	for(int i = 0; i < n; i++){
		cout << a[i] << " "; 
	}
}