#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

#include "ReadKey.h"
#include "../mta/MyTerminal.h"

struct termios __term_state;
struct termios termState;

struct termios origin;

void termInit()
{
    rk_myTermSave(&termState);
}

void defaultTermSettings(struct termios *termState)
{
    *termState = __term_state;
}

int rk_readKey(enum Keys *key) {
	int term = open(TERM, O_RDWR);
	char buf[8];
	tcgetattr(0, &origin);
	struct termios termState = __term_state;
	rk_myTermRegime(&termState, 0, 0, 1, 0, 1);
	int num = read(term, &buf, 4);
	buf[7] = 0;
	
	if (num < 0) {
		FILE *f = fopen("ghs.txt", "wt");
		putc('N', f);
		fclose(f);
	} else {
		FILE *f = fopen("ght.txt", "wt");
		putc('Y', f);
		fprintf(f, "%s", buf);
		fclose(f);
	}
    if (strncmp(buf, "l", 1) == 0)
    	*key = KLOAD;
    else if (strncmp(buf, "s", 1) == 0)
    	*key = SAVE;
    else if (strncmp(buf, "r", 1) == 0)
    	*key = RUN;
    else if (strncmp(buf, "t", 1) == 0)
    	*key = STEP;
    else if (strncmp(buf, "i", 1) == 0)
    	*key = RESET;
    else if (strncmp(buf, "q", 1) == 0)
    	*key = EXIT;
    else if (strncmp(buf, "a", 1) == 0)
    	*key = F5;
    else if (strncmp(buf, "c", 1) == 0)
    	*key = F6;
    else if (strcmp(buf, "\n") == 0)
    	*key = ENTER;
    else if (strcmp(buf, "\E[15~") == 0)
    	*key = F5;
    else if (strcmp(buf, "\E[17~") == 0)
    	*key = F6;
    else if (strcmp(buf, "\E[A") == 0)
    	*key = UP;
    else if (strcmp(buf, "\E[B") == 0)
    	*key = DOWN;
    else if (strcmp(buf, "\E[C") == 0)
    	*key = RIGHT;
    else if (strcmp(buf, "\E[D") == 0)
    	*key = LEFT;
    else
    	*key = NONE;
    rk_myTermRegime(&termState, 1, 0, 0, 1, 1);
    tcsetattr(0, TCSANOW, &origin);

	return 0;
}

int rk_myTermRegime(struct termios const *currState, int regime, int vtime, int vmin, int echo, int sigint) {
	if (regime < 0 || regime > 1 || echo < 0 || echo > 1 || sigint < 0 || sigint > 1) return -1;

	struct termios newTermState = *currState;

    if (regime == 1)
        newTermState.c_lflag |= ICANON;
    else
        newTermState.c_lflag &= ~ICANON;

    if (echo == 1)
        newTermState.c_lflag |= ECHO;
    else
        newTermState.c_lflag &= ~ECHO;

    if (sigint == 1)
        newTermState.c_lflag |= ISIG;
    else
        newTermState.c_lflag &= ~ISIG;

    newTermState.c_cc [VMIN]  = vmin;
    newTermState.c_cc [VTIME] = vtime;
	tcsetattr(0, TCSADRAIN, &newTermState);

	return 0;
}

int rk_myTermSave(struct termios *termState)
{
    return tcgetattr(0, termState);
}

int rk_myTermRestore(struct termios *currState)
{
    return tcsetattr(0, TCSADRAIN, &termState);
}

/*Thank you, Mioko!*/
