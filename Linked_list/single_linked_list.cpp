#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
	int value;
	struct Node *next;
};
typedef struct Node Node;

Node *start = NULL;

Node *create_node(int val)
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->value = val;
	p->next = NULL;
	return p;
}

Node *push_back(Node *start, int val)
{
	Node *p = create_node(val);
	if (start == NULL)
	{
		start = p;
	}
	else
	{
		Node *cur = start;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = p;
	}
	return start;
}

Node *insert(Node *start, int k, int val)
{
	Node *p = create_node(val);
	if (k == 0)
	{
		p->next = start;
		start = p;
	}
	else
	{
		Node *cur = start;
		int dem = 1;
		while (dem < k)
		{
			cur = cur->next;
			dem++;
		}
		p->next = cur->next;
		cur->next = p;
	}
	return start;
}

void print(Node *start)
{
	Node *cur = start;
	while (cur != NULL)
	{
		printf("%d ", cur->value);
		cur = cur->next;
	}
	printf("\n");
}

int get_value(Node *start, int k)
{
	Node *cur = start;
	int dem = 1;
	while (dem < k)
	{
		cur = cur->next;
		dem++;
	}
	return cur->value;
}

void get_pos(Node *start, int k)
{
	Node *cur = start;
	int dem = 0;
	while (cur != NULL)
	{
		dem++;
		if (cur->value == k)
		{
			printf("%d ", dem);
		}
		cur = cur->next;
	}
	printf("\n");
}

void Delete_first(Node **start)
{
	if (*start == NULL)
		return;
	Node *tmp = *start;
	*start = (*start)->next;
	free(tmp);
}

int size(Node *start)
{
	int cnt = 0;
	while (start != NULL)
	{
		++cnt;
		start = start->next;
	}
	return cnt;
}

void Delete(Node **start, int k)
{
	if (k < 1 || k > size(*start))
		return;
	if (k == 1)
		Delete_first(start);
	else
	{
		Node *tmp = (*start);
		for (int i = 1; i < k - 1; i++)
		{
			tmp = tmp->next;
		}
		Node *del = tmp->next;
		tmp->next = del->next;
		free(del);
	}
}

void remove_value(Node **start, int x)
{
	while ((*start) != NULL && (*start)->value == x)
	{
		Node *temp = *start;
		*start = (*start)->next;
		free(temp);
	}
	Node *temp = *start;
	Node *prev = temp;
	while (temp != NULL)
	{
		if (temp->value == x)
		{
			prev->next = temp->next;
			free(temp);
			temp = prev;
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}
	}
}

void deleteLinkedList(Node **head_ref)
{
	Node *current = *head_ref;
	Node *next;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head_ref = NULL;
}

void reverseLinkedList(Node **start)
{
	Node *prev = NULL;
	Node *current = *start;
	Node *next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*start = prev;
}

// Function to calculate the sum of all elements in the linked list
int sum(Node *start)
{
	int total = 0;
	Node *cur = start;
	while (cur != NULL)
	{
		total += cur->value;
		cur = cur->next;
	}
	return total;
}

// Hàm sắp xếp danh sách liên kết đơn theo thứ tự tăng dần bằng thuật toán sắp xếp chọn
Node *sort(Node *start)
{
	// Nếu danh sách liên kết trống hoặc chỉ có một phần tử, không cần sắp xếp
	if (start == NULL || start->next == NULL)
		return start;

	Node *current = start; // Sử dụng con trỏ 'current' để duyệt qua danh sách ban đầu

	while (current != NULL) // Lặp qua tất cả các phần tử trong danh sách ban đầu
	{
		Node *min = current;	 // Giả sử phần tử hiện tại là phần tử nhỏ nhất
		Node *r = current->next; // Con trỏ để duyệt các phần tử còn lại trong danh sách

		// Duyệt qua các phần tử còn lại để tìm phần tử nhỏ nhất
		while (r != NULL)
		{
			if (r->value < min->value)
				min = r; // Cập nhật phần tử nhỏ nhất
			r = r->next; // Di chuyển con trỏ 'r' tới phần tử tiếp theo
		}

		// Hoán đổi giá trị của phần tử nhỏ nhất và phần tử hiện tại
		if (min != current)
		{
			int temp = current->value;
			current->value = min->value;
			min->value = temp;
		}

		current = current->next; // Di chuyển con trỏ 'current' tới phần tử tiếp theo
	}
	return start; // Trả về danh sách đã sắp xếp
}

int main()
{
	while (1)
	{
		printf("1. Them vao cuoi danh sach \n");
		printf("2. Them vao vi tri k trong danh sach \n");
		printf("3. In ra danh sach \n");
		printf("4. Lay gia tri node thu k \n");
		printf("5. Lay vi tri cua node co gia tri k \n");
		printf("6. In ra so node cua day \n");
		printf("7. Xoa node thu k \n");
		printf("8. Xoa node co gia tri k \n");
		printf("9. Xoa toan bo danh sach lien ket \n");
		printf("10. Dao nguoc toan bo danh sach lien ket \n");
		printf("11. Tinh tong cac phan tu trong danh sach \n");
		printf("12. Sap xep cac phan tu trong danh sach \n");

		int lc;
		scanf("%d", &lc);

		if (lc == 1)
		{
			int n;
			scanf("%d", &n);
			start = push_back(start, n);
		}
		if (lc == 2)
		{
			int k;
			scanf("%d", &k);
			int n;
			scanf("%d", &n);
			start = insert(start, k, n);
		}
		if (lc == 3)
		{
			print(start);
		}
		if (lc == 4)
		{
			int k;
			scanf("%d", &k);
			printf("%d \n", get_value(start, k));
		}
		if (lc == 5)
		{
			int k;
			scanf("%d", &k);
			get_pos(start, k);
		}
		if (lc == 6)
		{
			printf("%d \n", size(start));
		}
		if (lc == 7)
		{
			int k;
			scanf("%d", &k);
			Delete(&start, k);
		}
		if (lc == 8)
		{
			int k;
			scanf("%d", &k);
			remove_value(&start, k);
		}
		if (lc == 9)
		{
			deleteLinkedList(&start);
		}
		if (lc == 10)
		{
			reverseLinkedList(&start);
		}
		if (lc == 11)
		{
			printf("Tong cac phan tu trong danh sach: %d\n", sum(start));
		}
		if (lc == 12)
		{
			start = sort(start);
			printf("Danh sach da duoc sap xep.\n");
		}
	}
}
