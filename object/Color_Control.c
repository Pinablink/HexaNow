#include <windows.h>
#define WHITE FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#define YELLOW FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN
#define RED  FOREGROUND_INTENSITY | FOREGROUND_RED   
#define GREEN FOREGROUND_INTENSITY | FOREGROUND_GREEN

static HANDLE hStdout;

void initSysColor ();
void setColorWhiteText ();
void setColorYellowText ();
void setColorRedText ();
void setColorGreenText ();

void initSysColor () {
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
}

void setColorWhiteText () {
	SetConsoleTextAttribute(hStdout, WHITE);
}

void setColorYellowText () {
	SetConsoleTextAttribute(hStdout, YELLOW);
}

void setColorRedText () {
	SetConsoleTextAttribute(hStdout, RED);	
}

void setColorGreenText () {
	SetConsoleTextAttribute(hStdout, GREEN);
}