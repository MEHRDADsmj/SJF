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

void InitProcesses(Process*);

int main()
{
	Process Procs[PROC_COUNT];
	//Process** ProcPtr = &Procs;
	InitProcesses(Procs);
	printf("Hello World");
	return 0;
}

void InitProcesses(Process* procs)
{
	int Index = 0;
	for(; Index < PROC_COUNT; ++Index)
	{
		procs[Index].ID = Index;
		strcpy_s(procs[Index].Name, "Process ");
		char Num[2];
		_itoa_s(Index, Num, 10);
		strcat_s(procs[Index].Name, Num);
	}

	procs[0].BurstTime = 1.0f;
	procs[1].BurstTime = 1.0f;
	procs[2].BurstTime = 1.0f;
	procs[3].BurstTime = 1.0f;
	procs[4].BurstTime = 1.0f;
}