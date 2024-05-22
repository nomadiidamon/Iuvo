#include "Iuvo.h"

void Iuvo::Write(const std::string message)
{
	std::cout << message;
}
void Iuvo::WriteLine(const std::string message)
{
	std::cout << message << std::endl;
}
void Iuvo::ClearConsole()
{
	std::cout << "\x1B[2J\x1B[H";
}
void Iuvo::PressAnyKeyToContinue()
{
	std::cout << "\nPress any key to continue...\n";
	std::cin.get();
	ClearConsole();
}
bool Iuvo::WipeAndFlush()
{
	std::cout << "Input failed, try again.";
	std::cin.ignore(INT_MAX, '\n');
	std::cin.clear();
	return 1;
}
bool Iuvo::Flush()
{
	std::cin.ignore(INT_MAX, '\n');
	std::cin.clear();
	return 1;
}

int Iuvo::GetValidatedInt(const char* message, int MinRange, int MaxRange)
{
	std::cout << message;
	int number;
	std::cin >> number;
	if (std::cin.fail()) {
		WipeAndFlush();
		GetValidatedInt(message, MinRange, MaxRange);
	}
	Flush();
	if (MinRange == 0 && MaxRange == 0) {
		return number;
	}
	else {
		if (MinRange < number && number < MaxRange) {
			return number;
		}
		else {
			WipeAndFlush();
			GetValidatedInt(message, MinRange, MaxRange);
		}
	}
}

char* Iuvo::GetValidatedString_255(const char* message)
{
	std::cout << message;

	char* ref = new char[255];
	std::cin.getline(ref, 255);
	if ((unsigned)strlen(ref) < 255) {
		return ref;
	}
	else {
		delete[] ref;
		Flush();
		std::cout << "Input was not within the valid range, try again." << std::endl;
		GetValidatedString_255(message);
	}
}

char* Iuvo::String_255()
{
	char* ref = new char[255];
	std::cin.getline(ref, 255);
	return ref;
}

int Iuvo::RandomInt(int MinRange, int MaxRange)
{
	int random;
	if (MinRange == 0 && MaxRange == 0) {
		random = rand();
		return random;
	}
	else {
		for (int i = 0; ; i++) {
			int x = rand();
			if (MinRange < x && x < MaxRange) {
				random = x;
				return random;
			}
		}
	}
}

void Iuvo::MemoryNet()
{
#define MEMORY_LEAK_LINE -1

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(MEMORY_LEAK_LINE); // DO NOT COMMENT OUT THIS LINE
	_CrtDumpMemoryLeaks();
}

const std::string Console::ESC = "\x1B";
int Console::windowWidth = 100, Console::windowHeight = 50;

void Console::ResizeWindow(int width, int height)
{
	windowWidth = width;
	windowHeight = height;
	std::cout << ESC << "[8;" << height << ";" << width << "t";
}
void Console::Reset()
{
	std::cout << ESC << "[0m";
}

void Console::Clear()
{
	std::cout << ESC << "[2J" << ESC << "[H"; //clears the screen and moves the cursor to the top-left
}

void Console::SetCursorPosition(int x, int y)
{
	std::cout << ESC << "[" << y << ";" << x << "H";
}

void Console::SetCursorLeft(int x)
{
	std::cout << ESC << "[" << x << "G";
}

void Console::Write(std::string message)
{
	std::cout << message;
}

void Console::Write(std::string message, ConsoleColor foreColor, ConsoleColor backColor)
{
	SetForegroundColor(foreColor);
	SetBackgroundColor(backColor);
	std::cout << message;
	Reset();
}

void Console::WriteLine(std::string message)
{
	std::cout << message << std::endl;
}

void Console::WriteLine(std::string message, ConsoleColor foreColor, ConsoleColor backColor)
{
	SetForegroundColor(foreColor);
	SetBackgroundColor(backColor);
	std::cout << message;
	Reset();
	std::cout << std::endl;
}

void Console::SetForegroundColor(ConsoleColor foreColor)
{
	std::cout << ESC << "[" << foreColor + 30 << "m";
}

void Console::SetForegroundColor(int r, int g, int b)
{
	std::cout << ESC << "[38;2;" << r << ";" << g << ";" << b << "m";
}

void Console::SetBackgroundColor(ConsoleColor backColor)
{
	std::cout << ESC << "[" << backColor + 40 << "m";
}

void Console::SetBackgroundColor(int r, int g, int b)
{
	std::cout << ESC << "[48;2;" << r << ";" << g << ";" << b << "m";
}