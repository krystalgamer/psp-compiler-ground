#ifndef UNITQUE_H
#define UNITQUE_H
typedef struct {
	int nTop;
	int nBottom;
	int nCount;
	int nFlag;
	int nDataSize;
	void *pBuffer;
	int nSema;
	int pad2[9];
	char Data[0];
} UnitQue;

UnitQue *UnitQueCreate(int size);
void UnitQueDestroy(UnitQue *pQue);
void UnitQueReset(UnitQue *pQue);
int UnitQueGetLeftLinear(UnitQue *pQue);
int UnitQueGetLeft(UnitQue *pQue);
int UnitQueGetFree(UnitQue *pQue);
void UnitQuePutData(UnitQue *pQue, void *pData, int nLen);
void UnitQueGetData(UnitQue *pQue, void *pData, int nLen);
void UnitQueFillData(UnitQue *pQue, int nData, int nLen);
void *UnitQueGetPtr(UnitQue *pQue);
void UnitQueIncPtr(UnitQue *pQue, int nLen);
#endif
