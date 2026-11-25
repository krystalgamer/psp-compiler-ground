#ifndef MENU_H
#define MENU_H
/* types recovered from DWARF */
typedef struct {
	int thumbpts;
	int fullptss;
	int fullpts;
	int fullptse;
	void *texture;
	int posx;
	int posy;
} MOVIE_LIST;

typedef struct {
	int current;
	int page;
	int pos;
	int selected;
	int saved;
} MENU_LIST;
#endif
