#pragma once
#include <math.h>
#include "queue.h"
#include <string>
using namespace std;
void To_String(string st, int &k, string *w)
{
	k = 0;
	string sth = " ,";
	st += " ";
	int len = st.length();

	w[0] = "";
	for (int i = 0; i < len; i++)
	{
		int l = sth.find(st[i]);
		if (l < 0)
		{
			w[k] += st[i];
		}
		else
		{
			if (st[i] == ' ')
			{
				if (w[k] != "")
					w[++k] = "";
			}
			if (st[i] == ',')
			{
				if (w[k] != "")
					w[++k] = "";
			}
		}
	}
};
void SortPoint(int *mem, int sizemem)
{
	queue Q[10];
	int max = 0;
	for (int i = 0;i < sizemem;i++)
	{
		if (mem[i] > max)
		{
			max = mem[i];
		}
	}

	int k = 0;
	while (max != 0)
	{
		k++;
		max = max / 10;
	}
	for (int i = 0;i < k;i++)
	{
		for (int j = 0;j < sizemem;j++)
		{
			int index = (mem[j] / (int)pow(10, i)) % 10;
			Q[index].Push(mem[j]);
		}
		sizemem = 0;
		for (int j = 0;j < 10;j++)
		{
			while (!Q[j].Is_Empty())
				mem[sizemem++] = Q[j].Pop();
		}
	}
}