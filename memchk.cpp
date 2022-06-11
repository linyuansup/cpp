#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
#include <psapi.h>
#include <process.h>
using namespace std;
float GetMemoryUsage(int pid)
{
	uint64_t mem = 0;
	PROCESS_MEMORY_COUNTERS pmc;
	HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (GetProcessMemoryInfo(process, &pmc, sizeof(pmc)))
		mem = pmc.WorkingSetSize;
	CloseHandle(process);
	return mem / 1024.0 / 1024.0;
}
void log(const string& message)
{
	freopen("log.txt", "w", stdout);
	time_t now = time(nullptr);
	cout << ctime(&now) << message << endl;
}
int main()
{
	int current_pid;
	cin >> current_pid;
	while (true)
	{
		log(to_string(GetMemoryUsage(current_pid)) + "MB");
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	return 0;
}