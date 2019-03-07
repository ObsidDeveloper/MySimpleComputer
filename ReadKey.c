#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

#include "mta/MyTerminal.h"
#include "ReadKey.h"

struct termios const _term_st;
struct termios term;

int rk_myTermSave(void) {
	return tcgetattr(1, term);
}

int rk_myTermRestore(void) {
	return tcsetattr(1, TCSADRAIN, &term);
}

int rk_myTermRegine(struct termios const *current, int regime, int vtime, int vmin, int echo, int sigint) {
	if (CHECK_REG_ECH_SIG) return -1;
	
	struct termios newstate = *current;

	if (regime) newstate.c_lflag |= ICANOW;
		else newstate.c_lflag &= ~ICANOW;

	if (echo) newstate.c_lflag |= ECHO;
		else newstate.c_lflag &= ~ECHO;

	if (sigint) newstate.c_lflag |= ISIG;
		else newstate.c_lflag &= ~ISIG;

	newstate.c_cc[VMIN] = vmin;
	newstate.c_cc[VTIME] = vtime;
	tcsetattr(0, TSCANOW, &newstate);

	return 0;
}

int rk_readKey(enum Keys *key) {
	int term = open(TERM, O_RDWR);
	char buf;

	struct termios termState = __term_state;
	rk_myTermRegime(&termState, 0, 1, 1, 0, 0);
	read(term, &buf, 1);

    switch (buf) {
		case 'q': {*key = EXIT; break;}
		case 'l': {*key = KLOAD; break;}
		case 's': {*key = SAVE; break;}
		case 'r': {*key = RUN; break;}
		case 't': {*key = STEP; break;}
		case 'i': {*key = RESET; break;}
		case 'e': {*key = EDIT; break;}
		case '\E': {
			read(term, &buf, 1);
			read(term, &buf, 1);
			switch (buf) {
				case 'A':
					*key = UP;
					break;
				case 'B':
					*key = DOWN;
					break;
				case 'C':
					*key = RIGHT;
					break;
				case 'D':
					*key = LEFT;
					break;
				case '1':
					read(term, &buf, 1);
					if (buf == '5') {
						read (term, &buf, 1);
						if (buf == '~') *key = F5;
					}
					if (buf == '7') {
						read (term, &buf, 1);
						if (buf == '~') *key = F6;
					}
					break;
				default:
					*key = NONE;
			}
			break;
			break;
		}
		default:
			*key = NONE;
			break;
    }
    rk_myTermRegime(&termState, 1, 0, 0, 1, 1);
    close(term);

	return 0;
}

void termInit() {
    rk_myTermSave(&__term_state);
}

void defaultTermSettings(struct termios *termState) {
    *termState = __term_state;
}

/*Thank you, Mioko!*/
