#include <cstdio>
#include <cstdlib>
#include <cstring>

#define PROC_COUNT 5

typedef struct  
{
	int ID;
	float BurstTime;
	char Name[10];
} Process;

Process Procs[PROC_COUNT];

Process* ReadyQueue[PROC_COUNT];
int QueueLast = -1;

void InitProcesses(Process*);
void EnqueueReady(int);

int main()
{
	InitProcesses(Procs);
	EnqueueReady(2);
	EnqueueReady(0);
	EnqueueReady(4);
	EnqueueReady(3);
	EnqueueReady(1);
	
	printf("Hello World");
	return 0;
}

void InitProcesses(Process* procs)
{
	procs[0].BurstTime = 1.0f;
	procs[1].BurstTime = 1.0f;
	procs[2].BurstTime = 1.0f;
	procs[3].BurstTime = 1.0f;
	procs[4].BurstTime = 1.0f;

	int Index = 0;
	for(; Index < PROC_COUNT; ++Index)
	{
		procs[Index].ID = Index;
		strcpy_s(procs[Index].Name, "Process ");
		char Num[2];
		_itoa_s(Index, Num, 10);
		strcat_s(procs[Index].Name, Num);
	}
}

void EnqueueReady(int ProcIndex)
{
	++QueueLast;
	if(QueueLast >= PROC_COUNT)
	{
		printf("Queue overload");
		exit(-1);
	}
	
	ReadyQueue[QueueLast] = &Procs[ProcIndex];
}