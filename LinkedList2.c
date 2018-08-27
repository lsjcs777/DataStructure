#include <stdio.h>
#include <stdlib.h>



//*************************************************************************

//  구조체 정의

//*************************************************************************

typedef struct Dnode
{
	int data;
	struct Dnode * prev; //앞의 링크!!
	struct Dnode * next; //뒤의 링크!!
}node;

node *head, *tail;



//*************************************************************************

//   head와 tail 초기화

//*************************************************************************

void init()
{
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));

	head->data = 0;
	tail->data = 0;


	head->next = tail;
	head->prev = head;
	tail->prev = head;
	tail->next = tail;

}



//*************************************************************************

//   노트 생성

//*************************************************************************
node* makenode(int data)
{
	node * p = (node*)malloc(sizeof(node));
	p->data = data;
	p->next = NULL;
	p->prev = NULL;
	return p;
}



//*************************************************************************

//   노드 삽입

//*************************************************************************
void push_back(int data)
{
	node* newnode = makenode(data);
	node* p;
	p = tail;

	p->prev->next = newnode;
	newnode->prev = p->prev;
	p->prev = newnode;
	newnode->next = p;

}



//*************************************************************************

//    출력

//*************************************************************************
void print()
{
	node * p;
	p = tail;
	while (p->prev != head)
	{
		printf("%d--", p->data);
		p = p->prev;
	}
	printf("%d", p->data);
}



//*************************************************************************

//   삭제

//*************************************************************************

void removeat(int val)
{
	node* p;
	p = head->next;

	while (p->next != tail)
	{
		if (p->data == val)
		{
			p->next->prev = p->prev;
			p->prev->next = p->next;
			free(p);
			return;
		}
		p = p->next;
	}

}

//*************************************************************************

//   메인

//*************************************************************************

void LinkedList2()
{
	init();

	push_back(1);
	push_back(2);
	push_back(3);
	push_back(4);

	removeat(2);

	print();


}