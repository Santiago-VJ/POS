#include "UI.h"
#include <windows.h>
//section of portability for Windows or linux/Mac
#ifdef _WIN32
void activateUI()
{
    //set console mode to enable ANSI escape codes
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;
    dwMode |= 0x0004;
    SetConsoleMode(hOut, dwMode);
    // Set UTF-8 encoding for output
    SetConsoleOutputCP(CP_UTF8);
}
#else
// For Linux and Mac, ANSI escape codes work by default
void activateUI() {
}
#endif

