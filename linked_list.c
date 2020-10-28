#include <stdio.h>
#include <stdlib.h>

/*
// 연결 리스트의 노드 구조체
struct NODE
{
	struct NODE *next; // 다음 노드의 주소를 저장할 포인터
	int data;		   // 데이터를 저장할 멤버
};
*/

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content)
{
	t_list *node;

	if (!(node = malloc(sizeof(t_list))))
		return (0);
	node->next = NULL;
	node->content = content;
	return (node);
}

/*
void addFirst(struct NODE *target, int data) //
{
	struct NODE *newNode = malloc(sizeof(struct NODE));
	newNode->next = target->next;
	newNode->data = data;

	target->next = newNode;
}
*/

void ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tail;

	if (!(lst) || !(new))
		return;
	if (!(*lst))
	{
		*lst = new;
		return;
	}
	tail = ft_lstlast(*lst);
	tail->next = new;
}

int ft_lstsize(t_list *lst)

{
	int size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_list *ft_lstlast(t_list *lst)
{
	if (!lst)
		return;
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int main(void)
{
	/*
	struct NODE *head = malloc(sizeof(struct NODE)); // 머리 노드 생성
													 // 머리 노드는 데이터를 저장하지 않음
	*/
	t_list *node;
	t_list *node2;
	t_list *node3;
	t_list *node4;
	t_list *begin;
	char **tab;

	/*
	// 노드 생성
	struct NODE *node1 = malloc(sizeof(struct NODE));
	head->next = node1; // 머리 노드 다음은 첫 번째 노드
	node1->data = 10;

	struct NODE *node2 = malloc(sizeof(struct NODE));
	node1->next = node2; // 첫 번째 노드 다음은 두 번째 노드
	node2->data = 20;

	node2->next = 0; // 두 번째 노드 다음은 노드가 없음(NULL)
	*/

	node = NULL;

	printf("content of last node : %s\n", ft_lstlast(begin));

	node = ft_lstnew("lorem ipsum dolor sit");
	node2 = ft_lstnew("ipsum dolor sit");
	node3 = ft_lstnew("dolor sit");
	node4 = ft_lstnew("sit");
	begin = NULL;

	/*
	head->next = NULL;

	addFirst(head, 10);
	addFirst(head, 20);
	addFirst(head, 30);
	*/

	/*
	ft_lstadd_front(&begin, node4);
	ft_lstadd_front(&begin, node3);
	ft_lstadd_front(&begin, node2);
	ft_lstadd_front(&begin, node);
	*/

	ft_lstadd_back(&begin, node4);
	ft_lstadd_back(&begin, node3);
	ft_lstadd_back(&begin, node2);
	ft_lstadd_back(&begin, node);

	printf("size : %d\n", ft_lstsize(begin));
	printf("content of last node : %s\n", ft_lstlast(begin));

	t_list *curr = node; // 연결 리스트 순회용 포인터에 첫 번째 노드의 주소 저장
	while (curr != NULL) // 포인터가 NULL이 아닐 때 계속 반복
	{
		printf("%s\n", curr->content);
		curr = curr->next;
	}

	/*
	free(node2);
	free(node1);
	free(head);
	*/

	curr = node;
	while (curr != NULL)
	{
		t_list *next = curr->next;
		free(curr);
		curr = next;
	}

	return 0;
}
