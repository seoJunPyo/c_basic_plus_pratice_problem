#include "Q17.h"

#define MAXQUEUE 10
#define MIN_PER_HR 60

typedef struct item
{
	long arrive;
	int proccess_time;
} Item;

typedef struct node
{
	Item item;
	struct node* next;
} Node;

typedef struct queue
{
	Node* front;
	Node* rear;
	int items;
} Queue;


void Init_Queue(Queue* pq);
bool Queue_is_Full(Queue* pq);
bool Queue_is_Empty(Queue* pq);
int Queue_Item_Count(Queue* pq);
bool EnQueue(Item item, Queue* pq);
bool Dequeue(Item* pitem, Queue* pq);
void Empty_Queue(Queue* pq);
bool newcustomer(double x);
Item customertime(long when);
static void Copy_To_Node(Item item, Node* pn);
static void Copy_To_Item(Node* pn, Item* pi);
void simulate(int hours, int perhour);

int Q17_4(void)
{
	int hours, perhour;
	srand(time(0));

	puts("��� ���� : ����");
	puts("�ùķ��̼� �ð� �Է� : ");
	scanf_s("%d", &hours);
	puts("1�ð��� �����ϴ� ��� �� �� �Է� :");
	scanf_s("%d", &perhour);

	for (int i = 0; i < 2; i++)
		simulate(hours, perhour);

	puts("����!");

	return 0;
}

void Init_Queue(Queue* pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

bool Queue_is_Full(Queue* pq)
{
	return pq->items == MAXQUEUE;
}

bool Queue_is_Empty(Queue* pq)
{
	return pq->items == 0;
}

int Queue_Item_Count(Queue* pq)
{
	return pq->items;
}

bool EnQueue(Item item, Queue* pq)
{
	Node* pnew;

	if (Queue_is_Full(pq))
		return false;

	pnew = (Node*)malloc(sizeof(Node));
	if (pnew != NULL)
	{
		Copy_To_Node(item, pnew);
		pnew->next = NULL;
	}

	if (Queue_is_Empty(pq))
		pq->front = pnew;
	else
		pq->rear->next = pnew;

	pq->rear = pnew;
	pq->items++;

	return true;
}

bool Dequeue(Item* pitem, Queue* pq)
{
	Node* pt;

	if (Queue_is_Empty(pq))
		return false;

	Copy_To_Item(pq->front, pitem);
	pt = pq->front;
	pq->front = pq->front->next;
	free(pt);
	pq->items--;
	if (pq->items == 0)
		pq->rear = NULL;

	return true;
}

void Empty_Queue(Queue* pq)
{
	Item dummy;
	while (!Queue_is_Empty(pq))
		Dequeue(&dummy, pq);
}

static void Copy_To_Node(Item item, Node* pn)
{
	pn->item = item;
}

static void Copy_To_Item(Node* pn, Item* pi)
{
	*pi = pn->item;
}

bool newcustomer(double x)
{
	if (rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}

Item customertime(long when)
{
	Item cust;

	cust.proccess_time = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}

void simulate(int hours, int perhour)
{
	Queue line;
	Item temp;
	long cycle, cyclelimt;
	int wait_time = 0;
	long turnaways = 0, customers = 0, served = 0, sum_line = 0, line_wait = 0;
	double min_per_cust;

	Init_Queue(&line);

	cyclelimt = MIN_PER_HR * hours;
	min_per_cust = MIN_PER_HR / perhour;

	for (cycle = 0; cycle < cyclelimt; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (Queue_is_Full(&line))
				turnaways++;
			else
			{
				customers++;
				temp = customertime(cycle);
				EnQueue(temp, &line);
			}
		}

		if (wait_time <= 0 && !Queue_is_Empty(&line))
		{
			Dequeue(&temp, &line);
			wait_time = temp.proccess_time;
			line_wait += cycle - temp.arrive;
			served++;
		}

		if (wait_time > 0)
			wait_time--;

		sum_line += Queue_Item_Count(&line);
	}

	if (customers > 0)
	{
		printf("ť�� �߰��� �� �� : %ld\n", customers);
		printf("   ������ �� �� : %ld\n", served);
		printf("   �������� �� �� : %ld\n", turnaways);
		printf("     ť�� ��� ���� : %.2f\n", (double)sum_line / cyclelimt);
		printf("     ��� ��� �ð� : %.2f min.\n", (double)line_wait / served);
	}
	else
		puts("���� ������.");

	Empty_Queue(&line);
}