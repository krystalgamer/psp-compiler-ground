#ifndef ICONV_H
#define ICONV_H
/* browser character set conversion (iconv.c) */

extern const u16 *unicodeToJisx0208_map[256];
extern const u16 *unicodeToJisx0212_map[256];
extern const u16 jisx0208ToUnicodeTable[];
extern const u16 jisx0212ToUnicodeTable[];

int checkASCII(const u8 *s, int len);
int checkJIS(const u8 *s, int len);
int checkShiftJIS(const u8 *s, int len);
int checkEUC(const u8 *s, int len);
int checkUTF8(const u8 *s, int len);
int glanceEncode(const u8 *s, int len);

#endif
