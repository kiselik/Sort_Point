#pragma once
class Core
{
private:
	int info;
	Core* next;
public:
	Core(int _info = 0)
	{
		info = _info;
		next = 0;
	}
	~Core(void)
	{
		delete next;// убъет весь список !!!!!!!!!!!
	}

	Core(Core& tmp)
	{
		info = tmp.info;
		next = 0;
	}

	Core & operator=(Core & tmp)
	{
		info = tmp.info;
		next = 0;
		return *this;
	}

	int GetInfo(void)
	{
		return info;
	}

	void SetInfo(int value)
	{
		info = value;
	}

	Core* GetNext(void)
	{
		return next;
	}

	void SetNext(Core* tmp)
	{
		next = tmp;
	}
};

