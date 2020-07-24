#include <iostream>
#include <cstring>
using namespace std;

void Push(int);
int Pop();
int Size();
int Empty();
int Front();
int Back();

int* Queue = new int[5];
int back = -1, capacity = 5;

int main()
{
	int count;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		char* order = new char[7];
		char* chnum=new char[500];
		cin >> order;
		if (strcmp("push", order) == 0)
		{
			cin >> chnum;
			Push(atoi(chnum));
		}
		else if (strcmp("pop", order) == 0)
		{
			cout << Pop() << endl;
		}
		else if (strcmp("size", order) == 0)
		{
			cout << Size() << endl;
		}
		else if (strcmp("empty", order) == 0)
		{
			cout << Empty() << endl;
		}
		else if (strcmp("front", order) == 0)
		{
			cout << Front() << endl;
		}
		else if (strcmp("back", order) == 0)
		{
			cout << Back() << endl;
		}
	}
	return 0;
}
void Push(int number)
{
	if (back == capacity-1)
	{
		capacity *= 2;
		int* newQueue = new int[capacity];
		for (int i = 0; i < capacity; i++)
		{
			newQueue[i] = Queue[i];
		}
		delete[] Queue;
		Queue = newQueue;
	}
	Queue[++back] = number;
}

int Pop()
{
	if (Empty() == 1)
		return -1;
	int retnum = Queue[0];
	int* newQueue = new int[capacity];
	for (int i = 0; i < back; i++)
	{
		newQueue[i] = Queue[i+1];
	}
	delete[] Queue;
	Queue = newQueue;
	back--;
	return retnum;
}

int Size()
{
	return (back + 1);
}

int Empty()
{
	if (back == -1)
		return 1;
	else
		return 0;
}

int Front()
{
	if (Empty() == 1)
		return -1;
	return Queue[0];
}

int Back()
{
	if (Empty() == 1)
		return -1;
	return Queue[back];
}