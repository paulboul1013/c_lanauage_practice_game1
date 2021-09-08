#include "GameLib.h"

void setTitle(char * title) {
	SetConsoleTitle(title);
}
void setColor(int forecolor, int backcolor) {
	HANDLE windhandle;
	windhandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(windhandle, forecolor + backcolor * 0x10);
}
 void SetPosition(int x, int y) {
	HANDLE winHandle;
	COORD pos = { x,y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(winHandle, pos);

}

 //從x,y座標開始，清rowCount行
 void Clear(int x, int y, int rowCount) {
	
	 int i,j;
	 for (i = 0; i < rowCount; i++) {
		 SetPosition(x, y+i);
		 for (int j = 0; j < 88; j++) {
			 printf(" ");
		 }
	 }
 }