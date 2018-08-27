#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

struct NODE {             // ���� ����Ʈ�� ��� ����ü
	struct NODE *next;    // ���� ����� �ּҸ� ������ ������
	int data;             // �����͸� ������ ���
};

int LinkedList1()
{

	struct NODE *head = malloc(sizeof(struct NODE));    // �Ӹ� ��� ����
														// �Ӹ� ���� �����͸� �������� ����

	struct NODE *node1 = malloc(sizeof(struct NODE));   // ù ��° ��� ����
	head->next = node1;                                 // �Ӹ� ��� ������ ù ��° ���
	node1->data = 10;                                   // ù ��° ��忡 10 ����

	struct NODE *node2 = malloc(sizeof(struct NODE));   // �� ��° ��� ����
	node1->next = node2;                                // ù ��° ��� ������ �� ��° ���
	node2->data = 20;                                   // �� ��° ��忡 20 ����

	node2->next = NULL;                                 // �� ��° ��� ������ ��尡 ����(NULL)

	struct NODE *curr = head->next;    // ���� ����Ʈ ��ȸ�� �����Ϳ� ù ��° ����� �ּ� ����
	while (curr != NULL)               // �����Ͱ� NULL�� �ƴ� �� ��� �ݺ�
	{
		printf("%d\n", curr->data);    // ���� ����� ������ ���
		curr = curr->next;             // �����Ϳ� ���� ����� �ּ� ����
	}

	free(node2);    // ��� �޸� ����
	free(node1);    // ��� �޸� ����
	free(head);     // �Ӹ� ��� �޸� ����

	return 0;


}