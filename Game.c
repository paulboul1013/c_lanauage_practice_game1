#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include "GameLib.h"
#include<time.h>
#define SEP "----------------------------------------------------------------------------------------"
#define COL 78
#define MARGIN_X 20//左邊距
#define MAP_START_Y 3
#define MAP_END_Y 11
#define INFO_START_Y 12
#define MAINMENU_START_Y 20
#define INFO_END_Y 19
int x = 3, y = 2;
Player players[] = {
	{1012,"張葦航","123",500,3,1,300,500,1000,1000000,.coord.X=3,.coord.Y=1},
	{1013,"張家航","123",100,3,1,200,500,1000,1000000,.coord.X = 2,.coord.Y = 0}
};

Martial martials[] = {
	/*
		int id;
	char name[50];
	char type[50];
	COORD hqCoord;
	int isOpen;
	char desc[1000];
	*/

	{1,"瘋狗派","邪派",.hqCoord.X=1,.hqCoord.Y=4,1,"由鼻地大師張葦航所創辦"}

};

Monster monsterArray[] = {
	{1,"spogbob",1,100,5,2,5,10,5,1,{0,0}},
	{2,"張家航",2,200,8,2,5,10,5,1,{0,0}},
	{3,"笑笑",3,100,5,2,5,10,5,1,{0,0}},
	{4,"關彥彤",4,100,5,2,5,10,5,1,{0,0}},
	{5,"人豪",5,100,5,2,5,10,5,1,{0,0}},
	{6,"萬攏",6,100,5,2,5,10,5,1,{0,0}},
	{7,"潤成",7,100,5,2,5,10,5,1,{0,0}},
	{8,"人豪666",8,100,5,2,5,10,5,1,{0,1}}
};


Prop propArray[] = {
	{1,"大巨捶",1,5,5000,Weapon,.minatttack=1,.maxatttack=4,"達瑞斯所使用的大捶"},
	{2,"多蘭盾",2,5,1000,Armor,.mindefence=2,.maxdefence=6,"能抵禦傷害"},
	{3,"探路者之燈",2,5,50,Con,.minpower=1,.maxpower=2,"能照亮東西"}


};

Map mapArray[8][8] = {
	{
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"地山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天空",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"虛空",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"}
	},
		{
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"}
	},
		{
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"}
	},
		{
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"}
	},
		{
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"}
	},
		{
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"}
	},
		{
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"}
	},
		{
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"},
	{1,"天山",1,{0,0},"充滿了西域文化"},{1,"天山",1,{0,0},"充滿了西域文化"}
	}

};
Player* currPlayer;
void Init() {//初始化遊戲數據
	currPlayer = &players[0];
	currPlayer->weapon = propArray[0];
	currPlayer->armor = propArray[1];
	currPlayer->martial = martials[0];
}



void Show() {//展示全局數據

	int propCount = sizeof(propArray) / sizeof(propArray[0]);

	for (int i = 0; i < propCount; i++) {
		printf("%d\t%s\t%.01f\t\n", propArray[i].id, propArray[i].name, propArray[i].price);
		switch (propArray[i].type) {
		case Weapon://武器
			printf("最小攻擊力: %d\t最大攻擊力: %d\n", propArray[i].minatttack, propArray[i].maxatttack);
			break;

		case Armor:
			printf("最小防護力: %d\t最大防護力: %d\n", propArray[i].mindefence, propArray[i].maxdefence);
			break;

		case Con:
			printf("最小能量值: %d\t最大能量值: %d\n", propArray[i].minpower, propArray[i].maxpower);
			break;
		}
	}
	printf("\n打印地圖 \n");

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%-8s", mapArray[i][j].name);
		}
		printf("\n");
	}

}
//顯示遊戲的歡迎信息
void ShowWelcome() {
	SetPosition(MARGIN_X, 0);
	printf("%s\n", SEP);
	SetPosition(MARGIN_X, 1);
	printf("|");
	SetPosition(MARGIN_X+30, 1);
	puts("歡迎來到瘋狗娛樂");
	SetPosition(MARGIN_X + 87, 1);
	printf("|");
	SetPosition(MARGIN_X, 2);
	printf("%s\n", SEP);
}
//顯示遊戲地圖
void ShowMap() {


	int i, j;
	printf("\n");
	for (i = 0; i < 8; i++) {
		SetPosition(MARGIN_X, MAP_START_Y+i);

		for (j = 0; j < 8; j++) {
			if (j == 0) {
				printf("|  ");
			}
			if (i == x && j == y) {
				//更改地圖文字顏色和背景色
				setColor(5, 15);
			}
			printf("%-9s", mapArray[i][j].name);
			setColor(10, 0);
		}
		SetPosition(MARGIN_X+87, 3 + i);
		printf("|");

	}
	SetPosition(MARGIN_X, MAP_END_Y);
	printf(SEP);
	ShowMapInfo();
}
//顯示遊戲地圖下方的遊戲信息
void ShowInformation() {
	SetPosition(MARGIN_X,INFO_START_Y );
	int i;
	for ( i = 0; i < 7; i++) {
		SetPosition(MARGIN_X, INFO_START_Y+i);
		printf("|");

		SetPosition(MARGIN_X+87, INFO_START_Y+i);
		printf("|");
	}
	SetPosition(MARGIN_X , INFO_START_Y +7);
	printf(SEP);


}
//顯示地圖的信息
void ShowMapInfo() {
	//1.清除信息框的消息
	Clear(MARGIN_X+1, INFO_START_Y, 7);
	//2.顯示當前玩家所在地圖的信息
	SetPosition(MARGIN_X + 25, INFO_START_Y);
	printf("當前玩家所在地圖: <<%s>> ",mapArray[x][y].name);
	SetPosition(MARGIN_X + 10, INFO_START_Y+1);
	//需要控制顯示的行

	char* desc = mapArray[x][y].desc;
	int descLen = strlen(desc);
	int i, j;
	for (i = 0; i < descLen; i++) {
		if (i != 0 && i % 60 == 0) {
			SetPosition(MARGIN_X + 10, INFO_START_Y + 1+i/60);
		}
		printf("%c", desc[i]);

	}
}
//顯示遊戲的主菜單
void ShowMainMenu() {
	SetPosition(MARGIN_X,MAINMENU_START_Y);
	printf("遊戲菜單");
	SetPosition(MARGIN_X, MAINMENU_START_Y+1);
	printf("1.個人訊息");
	SetPosition(MARGIN_X, MAINMENU_START_Y + 2);
	printf("2.查找怪物");
	SetPosition(MARGIN_X, MAINMENU_START_Y + 3);
	printf("3.回總部");
	SetPosition(MARGIN_X, MAINMENU_START_Y + 4);
	printf("4.購買裝備");
	SetPosition(MARGIN_X, MAINMENU_START_Y + 5);
	printf("5.");
	SetPosition(MARGIN_X, MAINMENU_START_Y + 6);
	printf("6.");
	SetPosition(MARGIN_X, MAINMENU_START_Y + 7);
	printf("7.");
	SetPosition(MARGIN_X, MAINMENU_START_Y + 8);



}

//處理遊戲主菜單的業務
void ProcessMainMenu(char key) {
	switch (key)
	{

	case '1':
		ShowPlayInfo();
		break;
	case '2':
		ShowMonsters();
		break;
	case '3':
		Move(currPlayer->martial.hqCoord.X,currPlayer->martial.hqCoord.Y);
		break;
	case '4':

		break;
	case '5':

		break;

	default:
		break;
	}

}
//在信息介面顯示玩家的個人資料
void ShowPlayInfo() {
	Clear(MARGIN_X, INFO_START_Y, 7);
	SetPosition(MARGIN_X + 20, INFO_START_Y);
	printf("玩家 <<%s>> 的個人資料如下: ",currPlayer->name);
	SetPosition(MARGIN_X + 10, INFO_START_Y+1);
	printf("等級: %d\t血量: %d\t魔力: %d\t經驗值: %d", currPlayer->level,currPlayer->hp,currPlayer->mp,currPlayer->exp);
	SetPosition(MARGIN_X + 10, INFO_START_Y + 2);
	printf("當前武器: %s(%d/%d) ", currPlayer->weapon.name, currPlayer->weapon.minatttack,currPlayer->weapon.maxatttack);
	printf("當前防具: %s(%d/%d)", currPlayer->armor.name, currPlayer->armor.mindefence, currPlayer->armor.maxdefence);



}
//在當前地圖顯示怪物
void ShowMonsters() {

	char levelNames[9][20] = { "菜雞","虎級","鬼級","龍級","神級","惡級","回式級","罪級","破壞神級"};
	Clear(MARGIN_X-1, INFO_START_Y, 7);
	SetPosition(MARGIN_X + 10, INFO_START_Y);
	//怪物總數
	int monsterCount = sizeof(monsterArray) / sizeof(Monster);
	int i;
	int monsterIndex[9];//當前地圖的怪物索引
	int curMapMonsterCount = 0;//當前地圖的怪物總數
	for (i = 0; i < monsterCount; i++) {
		if (monsterArray[i].coord.X == x && monsterArray[i].coord.Y == y&&monsterArray[i].state!=0) {
			monsterIndex[curMapMonsterCount++] = i;
			if (curMapMonsterCount == 9) {
				break;
			}
		}
	}
	SetPosition(MARGIN_X + 10, INFO_START_Y);
	if (curMapMonsterCount == 0) {
		printf("當前地圖沒有任何怪物");
		return;
	}
	printf("當前地圖出現如下怪物: ");
	SetPosition(MARGIN_X + 5, INFO_START_Y+2);
	for (i = 0; i < curMapMonsterCount; i++) {
		if (i != 0 && i % 3 == 0) {
			SetPosition(MARGIN_X + 5, INFO_START_Y +2+i/3);
		}
		printf("%d.%s(%s)\t", i+1,monsterArray[monsterIndex[i]].name, levelNames[monsterArray[monsterIndex[i]].level-1]);
	}
	SetPosition(MARGIN_X + 5, INFO_END_Y-1);
	int pkMonsterId = -1;
	printf("請輸要攻擊的對象: (按0返回)");
	scanf("%d", &pkMonsterId);
	//printf("要攻擊的怪物編號為: %d", pkMonsterId);


	Fight(pkMonsterId);

}

void Fight(int monsterId) {

	int monsterIndex = -1;
	int i;
	for (i = 0; i < sizeof(monsterArray) / sizeof(Monster); i++) {
		if (monsterArray[i].id == monsterId) {
			monsterIndex = i;
			break;
		}
	}
	SetPosition(MARGIN_X + 5, INFO_END_Y - 1);
	printf("                                     ");
	if (monsterIndex == -1) {
		SetPosition(MARGIN_X + 5, INFO_END_Y - 1);
		printf("要pk的怪物不存在，按任意鍵繼續");
		return;
	}
	int fightCount = 0;
	while (1) {
		srand((unsigned)time(NULL));
		int playerAtttack = rand() % (currPlayer->weapon.maxatttack - currPlayer->weapon.minatttack + 1) + currPlayer->weapon.minatttack;
		monsterArray[monsterIndex].hp -= playerAtttack;
		if (monsterArray[monsterIndex].hp <= 0) {
			break;
		}
		currPlayer->hp -= monsterArray[monsterIndex].att;
		if (currPlayer->hp <= 0) {
			break;
		}
		SetPosition(MARGIN_X + 5, INFO_END_Y - 1);
		printf("                                        ");
		SetPosition(MARGIN_X + 2, INFO_END_Y - 1);
		printf("                                        ");
		fightCount++;
		printf("戰鬥地%d輪 ,%sHP:%d\t%sHP:%d", fightCount, currPlayer->name, currPlayer->hp, monsterArray[monsterIndex].name, monsterArray[monsterIndex].hp);
		Sleep(500);
	}
	SetPosition(MARGIN_X + 5, INFO_END_Y - 1);
	printf("                                        ");
	if (currPlayer->hp <= 0) {

		SetPosition(MARGIN_X-2 , INFO_END_Y - 1);
		printf("江湖快訊: 大俠<<%s>> 在與 <<%s>> 的戰鬥中,戰敗身亡",currPlayer->name,monsterArray[monsterIndex].name);
		currPlayer->hp = 100;
		return;
	}
	SetPosition(MARGIN_X + 5, INFO_END_Y - 1);
	printf("經過戰鬥 <<%s>> 被你殺死 獲得%d經驗, %d金幣!", monsterArray[monsterIndex].name, monsterArray[monsterIndex].exp, monsterArray[monsterIndex].maxMoney);
	currPlayer->exp += monsterArray[monsterIndex].exp;
	currPlayer->gold += monsterArray[monsterIndex].maxMoney;



}
void Move(int xx, int yy) {
	y = xx;
	x = yy;
	ShowMap();
}


