#pragma once
#include <iostream>
#include <vector>

class Lists
{
	std::vector<std::string> nomines = {
	"Keon", "Tui", "Limak", "Adeline", "Isam",
	"Kamek","Namiko", "Vigi", "Durk", "Aguilar",
	"Khai", "Tyson", "Koda", "Vasu", "Jadon",
	"Rhea", "Yali", "Yalu", "Neveah", "Kaia",
	"Cara", "Daya", "Eileen", "Oba", "Semmi",
	"Anita", "Ainara", "Jerold", "Tobias", "Palafox",
	"Alcetas", "Karno","Grozdan", "Selasi", "Gerard"
	};
	std::vector<std::string> urbes = {
	"Callum", "Arrun", "Maidan", "Zakaria",
	"Sankai", "Ziza", "Alarcon", "Aulus", "Drymadoria",
	"Drimadoria", "Lykianti", "Nazar", "Elnashar",
	"Aminita", "Oha", "Aoleon", "Javad", "Thiago",
	"Palafax", "Ogallala", "Menin", "Engedi", "Rosta",
	"Cairno", "Azgoah", "Saurr", "Merav", "Eknashar"
	};
};


namespace Iuvo
{

	void Write(const std::string message);
	void WriteLine(const std::string message);
	void ClearConsole();
	static void PressAnyKeyToContinue();
	bool WipeAndFlush();
	bool Flush();
	int GetValidatedInt(const char* message, int MinRange = 0, int MaxRange = 0);
	// must delete reference returned after use.
	char* GetValidatedString_255(const char* message);
	// must delete reference returned after use.
	char* String_255();
	int RandomInt(int MinRange = 0, int MaxRange = 0);
	// Detects memory leaks
	void MemoryNet();

};

enum ConsoleColor
{
	Black,
	Red,
	Green,
	Yellow,
	Blue,
	Magenta,
	Cyan,
	White,
	Default = 9
};

class Console
{
public:
	static void ResizeWindow(int width, int height);
	static int GetWindowWidth() { return windowWidth; }
	static int GetWindowHeight() { return windowHeight; }
	static void SetCursorPosition(int x, int y);
	static void SetCursorLeft(int x);
	static void SetForegroundColor(ConsoleColor foreColor);
	static void SetForegroundColor(int r, int g, int b);
	static void SetBackgroundColor(ConsoleColor backColor);
	static void SetBackgroundColor(int r, int g, int b);
	static void Reset();
	static void Clear();

	static void Write(std::string message);
	static void Write(std::string message, ConsoleColor foreColor, ConsoleColor backColor = ConsoleColor::Black);
	static void WriteLine(std::string message);
	static void WriteLine(std::string message, ConsoleColor foreColor, ConsoleColor backColor = ConsoleColor::Black);


private:
	static const std::string ESC;

	static int windowWidth, windowHeight;
};

