#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // node dang truoc
    struct node *prev; // node dang sau
} node;

node *makeNode(int x)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void duyet(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int size(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        ++cnt;
        head = head->next;
    }
    return cnt;
}

void pushFront(node **head, int x)
{
    node *newNode = makeNode(x);
    newNode->next = (*head);
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    (*head) = newNode;
}

void pushBack(node **head, int x)
{
    node *newNode = makeNode(x);
    if (*head == NULL)
    {
        (*head) = newNode;
        return;
    }
    node *tmp = *head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
}

void insert(node **head, int k, int x)
{
    int n = size(*head); // so node trong dslk
    if (k < 1 || k > n)
    {
        printf("Vi tri chen khong hop le ! \n");
        return;
    }
    if (k == 1)
    {
        pushFront(head, x);
        return;
    }
    if (k == n + 1)
    {
        pushBack(head, x);
        return;
    }
    node *tmp = *head;
    for (int i = 1; i < k - 1; i++)
    {
        tmp = tmp->next; // node thu k
    }
    node *newNode = makeNode(x);
    newNode->next = tmp->next; // cho phan next cua newNode la next cua k-1
    tmp->next->prev = newNode; // cho phan prev cua k la newNode
    tmp->next = newNode;       // cho phan next cua k - 1 la newNode
    newNode->prev = tmp;       // cho phan prev cua newNode la k-1
}

void popFront(node **head)
{
    if (*head == NULL)
        return; // neu dslk rong
    node *temp = *head;
    *head = temp->next; // node head nhay den node thu 2
    if (*head != NULL)
    { // neu dslk co > 1 node
        (*head)->prev = NULL;
    }
    free(temp);
}

void popBack(node **head)
{
    if (*head == NULL)
        return; // neu dslk rong
    node *temp = *head;
    if (temp->next == NULL)
    { // danh sach lien ket chi co 1 node
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    } // duyet den node thu hai tu cuoi
    node *last = temp->next; // node cuoi
    temp->next = NULL;
    free(last);
}

void erase(node **head, int k)
{
    int n = size(*head);
    if (k < 1 || k > n)
        return;
    if (k == 1)
        popFront(head);
    else
    {
        node *temp = *head;
        for (int i = 1; i <= k - 1; i++)
        {
            temp = temp->next;
        } // duyet den node thu k (temp)
        temp->prev->next = temp->next;
        // next cua node k - 1 = k + 1
        if (temp->next != NULL)            // neu node k+1 khong phai node cuoi
            temp->next->prev = temp->prev; // cho prev cua k+1 la prev cua k
        free(temp);
    }
}

void reverse(node **head)
{
    if (*head == NULL)
        return;          // dslk rong
    int n = size(*head); // so luong node trong dslk
    node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    } // duyet den last la node cuoi
    node *first = *head; // node dau
    for (int i = 1; i <= n / 2; i++)
    {
        int tmp = first->data;    // tmp luu data cua first
        first->data = last->data; // data cua first chuyen thanh data cua last
        last->data = tmp;         // data cua last la tmp, tuc la data cua first
        first = first->next;      // duyet tien
        last = last->prev;        // duyet lui
    }
}
int main()
{
    node *head = NULL;
    // Thêm phần tử vào đầu danh sách
    pushFront(&head, 1);
    pushFront(&head, 2);
    pushFront(&head, 3);
    duyet(head); // Dự kiến: 3 2 1
    printf("\n");

    // Thêm phần tử vào cuối danh sách
    pushBack(&head, 4);
    pushBack(&head, 5);
    duyet(head); // Dự kiến: 3 2 1 4 5
    printf("\n");

    // Chèn phần tử vào vị trí thứ 3
    insert(&head, 3, 6);
    duyet(head); // Dự kiến: 3 2 6 1 4 5
    printf("\n");

    // Xóa phần tử đầu tiên
    popFront(&head);
    duyet(head); // Dự kiến: 2 6 1 4 5
    printf("\n");

    // Xóa phần tử cuối cùng
    popBack(&head);
    duyet(head); // Dự kiến: 2 6 1 4
    printf("\n");

    // Xóa phần tử ở vị trí thứ 2
    erase(&head, 2);
    duyet(head); // Dự kiến: 2 1 4
    printf("\n");

    // Đảo ngược danh sách liên kết
    reverse(&head);
    duyet(head); // Dự kiến: 4 1 2
    printf("\n");

    return 0;
}
