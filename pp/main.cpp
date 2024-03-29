#include <windows.h>
#include <time.h>
#include "conio2.h"

#include "Window.h"

int main() {
	SetConsoleOutputCP(437);
	srand(time(NULL));

	const HWND hwndConsole = GetConsoleWindow();
	const HWND hwndDesktop = GetDesktopWindow();
	RECT desktop;
	GetWindowRect(hwndDesktop, &desktop);

	HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFO fontInfo;
	GetCurrentConsoleFont(stdHandle, FALSE, &fontInfo);
	const COORD fontSize = GetConsoleFontSize(stdHandle, fontInfo.nFont);

	const int marginRight = 100;
	const int marginLeft = 100;
	const int marginTop = 100;
	const int marginBot = 100;

	const int widthChar = (desktop.right - marginRight - marginLeft) / fontSize.X;
	const int heightChar = (desktop.bottom - marginTop - marginBot) / fontSize.Y;
	const int width = widthChar * fontSize.X;
	const int height = heightChar * fontSize.Y;

	const int x = marginRight;
	const int y = marginTop;

	MoveWindow(hwndConsole, x, y, width, height, TRUE);

	Window window(widthChar, heightChar);
	return 0;
}