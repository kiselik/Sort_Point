#pragma once
#include "Core.h"
class queue
{
private:
	Core* last;
	Core* first;
	int count;
public:
	queue()
	{
		last = 0;
		first = 0;
		count = 0;
	}

	queue(queue& tmp)
	{
		Core* cur = tmp.first;
		while (cur != 0)
		{
			Push(cur->GetInfo());
			cur = cur->GetNext();
		}
	}
	queue& operator=(queue& tmp)
	{
		delete first;
		first = 0;
		count = 0;
		last = 0;
		Core* Cur = tmp.first;
		while (Cur != 0)
		{
			Push(Cur->GetInfo());
			Cur = Cur->GetNext();
		}
		return *this;
	}

	~queue(void)
	{
		delete first;
		last = 0;
		count = 0;
	}

	bool Is_Empty(void)
	{
		return(count == 0);
	}

	void Push(int info)
	{
		Core* tmp = new Core(info);
		if (count == 0)
		{
			first = tmp;
			last = tmp;
			count = 1;
		}
		else
		{
			last->SetNext(tmp);
			last = tmp;
			count++;
		}
	}
	int Pop(void)
	{
		if (count == 0) { return 0; }
		else
		{
			Core* tmp = first;
			first = first->GetNext();
			int a = tmp->GetInfo();
			tmp->SetNext(0);
			delete tmp;
			count--;
			if (count == 0) { last = 0; }
			return a;
		}
	}


};


