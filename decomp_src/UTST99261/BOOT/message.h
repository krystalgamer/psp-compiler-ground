#ifndef MESSAGE_H
#define MESSAGE_H
/* types recovered from DWARF (tools/dwarfhdr.py) */
enum {
    MESS_MODE_NOP = 0,
    MESS_MODE_NULL = 1,
    MESS_MODE_START = 2,
    MESS_MODE_EXEC = 3,
    MESS_MODE_END = 4,
    MESS_MODE_OK = 5,
    MESS_MODE_CANCEL = 6,
    MESS_MODE_INPUT_ID = 7,
    MESS_MODE_INPUT_PASSWORD = 8,
    MESS_MODE_RELOAD = 9,
    MESS_MODE_HOME = 10,
    MESS_MODE_BACK = 11,
    MESS_MODE_URL = 12,
    MESS_MODE_NETWORK = 13,
    MESS_MODE_FONT = 14,
    MESS_MODE_TEX = 15,
    MESS_MODE_DEZ = 16,
    MESS_MODE_EXIT = 17,
};
typedef struct { /* size 0x1c */
    char type;
    int x;
    int y;
    int tData;
    char *messData;
    int messSize;
    char mode;
} MESS_OBJ;
extern char _iSslOn;

int messInit(void);
int messExit(void);
int messStart(void);
void messBlack(int cc);
int messExec(int ti);
int messEnd(void);
int messObjCreate(char type, int x, int y, char *str, int strLen, int tData);
int messObjDel(int obj_no);
int messObjStateSet(int obj_no, int a);
int messObjStrSet(int obj_no, char *st, int len);
void messObjDraw(void);

#endif
