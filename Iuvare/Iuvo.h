#pragma once
#include "IuvoConsole.h"
#include "IuvoInput.h"
#include "IuvoNames.h"


namespace Iuvo
{
	int RandomInt(int MinRange, int MaxRange)
	{
		int random;
		if (MinRange == 0 && MaxRange == 0) {
			random = rand();
			return random;
		}
		else {
			for (int i = 0; ; i++) {
				int x = rand() % (MaxRange - MinRange + 1) + MinRange;
				if (MinRange < x) {
					random = x;
					return random;
				}
			}
		}
	}

	// Detects memory leaks
	void MemoryNet()
	{

	// Change this number to the line number the Output window shows you
	// to follow a memory leak. Put -1 to disable.
	#define MEMORY_LEAK_LINE -1


		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		_CrtSetBreakAlloc(MEMORY_LEAK_LINE); // DO NOT COMMENT OUT THIS LINE
		_CrtDumpMemoryLeaks();
	}

};


