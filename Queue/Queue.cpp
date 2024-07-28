#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Định nghĩa cấu trúc của một nút trong danh sách liên kết
typedef struct _listnode
{
    int num;                // Giá trị của nút
    struct _listnode *next; // Con trỏ đến nút tiếp theo
} ListNode;

// Định nghĩa cấu trúc của một danh sách liên kết
typedef struct _linkedlist
{
    ListNode *head; // Con trỏ đến nút đầu tiên của danh sách
    ListNode *tail; // Con trỏ đến nút cuối cùng của danh sách
    int size;       // Kích thước của danh sách
} LinkedList;

// Định nghĩa cấu trúc của một hàng đợi sử dụng danh sách liên kết
typedef struct _queue
{
    LinkedList ll; // Một danh sách liên kết
} Queue;

// Hàm chèn một nút vào cuối danh sách liên kết
void insertNode(ListNode **ptrHead, ListNode **ptrTail, int value)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode)); // Ép kiểu void * thành ListNode *
    newNode->num = value;
    newNode->next = NULL;

    if (*ptrTail == NULL)
    {
        *ptrHead = newNode;
        *ptrTail = newNode;
    }
    else
    {
        (*ptrTail)->next = newNode;
        *ptrTail = newNode;
    }
}

// Hàm xóa nút đầu tiên trong danh sách liên kết
void removeNode(ListNode **ptrHead, ListNode **ptrTail)
{
    if (*ptrHead == NULL)
        return;

    ListNode *temp = *ptrHead;
    *ptrHead = (*ptrHead)->next;
    if (*ptrHead == NULL)
    {
        *ptrTail = NULL;
    }
    free(temp);
}

// Hàm kiểm tra hàng đợi có rỗng không
bool isEmptyQueue(Queue *q)
{
    return (q->ll.size == 0);
}

// Hàm enqueue để thêm giá trị vào hàng đợi
void enqueue(Queue *q, int item)
{
    insertNode(&(q->ll.head), &(q->ll.tail), item); // Chèn vào cuối danh sách
    q->ll.size++;                                   // Tăng kích thước của hàng đợi
}

// Hàm dequeue để lấy một phần tử từ hàng đợi
int dequeue(Queue *q)
{
    if (!isEmptyQueue(q))
    {                                             // Kiểm tra hàng đợi có rỗng không
        int item = (q->ll.head)->num;             // Lấy giá trị của nút đầu tiên
        removeNode(&(q->ll.head), &(q->ll.tail)); // Xóa nút đầu tiên
        q->ll.size--;                             // Giảm kích thước của hàng đợi
        return item;                              // Trả về giá trị
    }
    else
    {
        printf("\nHàng đợi rỗng"); // In thông báo hàng đợi rỗng
        return -1;                 // Trả về giá trị báo lỗi
    }
}

// Hàm in các phần tử trong hàng đợi
void printQueue(Queue *q)
{
    ListNode *temp = q->ll.head;
    printf("Các phần tử trong hàng đợi: ");
    while (temp != NULL)
    {
        printf("%d ", temp->num);
        temp = temp->next;
    }
    printf("\n");
}

// Hàm main để kiểm tra các tính năng của hàng đợi
int main()
{
    Queue q;
    q.ll.head = NULL;
    q.ll.tail = NULL;
    q.ll.size = 0;

    enqueue(&q, 10); // Thêm 10 vào hàng đợi
    enqueue(&q, 20); // Thêm 20 vào hàng đợi
    enqueue(&q, 30); // Thêm 30 vào hàng đợi

    printQueue(&q); // In các phần tử trong hàng đợi

    printf("Dequeue: %d\n", dequeue(&q)); // Lấy phần tử từ hàng đợi (10)
    printf("Dequeue: %d\n", dequeue(&q)); // Lấy phần tử từ hàng đợi (20)
    printf("Dequeue: %d\n", dequeue(&q)); // Lấy phần tử từ hàng đợi (30)
    printf("Dequeue: %d\n", dequeue(&q)); // Cố gắng lấy phần tử từ hàng đợi rỗng

    return 0;
}
