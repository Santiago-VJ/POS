
#ifndef UI_H
#define UI_H
void activateUI();
// definition of colors
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
// definition of fonts
#define NORMAL "\033[0m"
#define BOLD "\033[1m"
#define DIM "\033[2m"
// #define ITALIC "\033[3m" NOT SUPPORTED IN ALL TERMINALS
#define UNDERLINE "\033[4m"
//definition of background colors
#define BLACKBG     "\033[40m"       /* Black Background */
#define REDBG       "\033[41m"       /* Red Background */
#define GREENBG     "\033[42m"       /* Green Background */
#define YELLOWBG    "\033[43m"       /* Yellow Background */
#define BLUEBG      "\033[44m"       /* Blue Background */
//definition of clear screen
#define CLEAR  "\033[2J\033[1;1H"      /* Clear the screen and move cursor to top-left */
#endif