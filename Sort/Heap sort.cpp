#include <stdio.h>

void swap(int *x, int *y){
    int c = *x;
    *x = *y;
    *y = c;
}
int heap[1000]; int sz = 0;

void heapify_up(int j){
    if(j == 1) return; //neu chi co 1 phan tu
    int i = j / 2; //tim cha cua node
    if(heap[i] < heap[j]){
        swap(&heap[i], &heap[j]);
        heapify_up(i);
    }
}

void push(int x){
    sz++;
    heap[sz] = x;
    heapify_up(sz);
}

void heapify_down(int i){
    int j = i * 2; //tim con
    if(j > sz) return; //khong co con
    if(heap[j] < heap[j + 1] && j + 1 <= sz){
        j++;
    }
    if(heap[j] > heap[i]){
        swap(&heap[j], &heap[i]);
        heapify_down(j);
    }
}

void pop(){
    heap[1] = heap[sz];
    sz--;
    heapify_down(1);
}

int max_heap(){
    return heap[1];
}

void heap_sort(int a[], int n){
    for(int i = 0; i < n; i++){
        push(a[i]);
    }
    for(int i = n - 1; i >= 0; i--){
            a[i] = max_heap();
            pop();
    }
}
int main(){
    int n; scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    heap_sort(a, n);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}
