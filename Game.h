#pragma once

//定義一些遊戲核心結構和函式

#include<stdio.h>
#include<string.h>
#include<Windows.h>

//遊戲地圖實現結構
//編號 名稱 介紹 玩家的進入等級
typedef struct _map {
	int id;//地圖編號 
	char name[50];//地圖名稱
	int minLevel;//玩家的進入等級
	//座標結構
	COORD  coord;
	char desc[500];//地圖介紹


}Map;


/*  遊戲結構類型定義   */
//玩家,地圖,裝備,怪物

//遊戲道具類型enum  武器,防具 ,消耗品, 卡片,碎片
typedef enum _proptype {
	Weapon,Armor,Con,card,Frag
}PropType;

//遊戲道具- 武器,防具 ,消耗品, 卡片
typedef struct  _prop {

	int id;//道具編號
	char name[50];//道具名子
	int leve;//道具等級
	int stock;//道具庫存貨玩家背包的道具數量
	double price;//道具價格
	PropType type;//遊戲道具類型
	union {
		int minatttack;//武器對應攻擊力
		int mindefence;//防具對應防護力
		int minpower;//消耗品, 卡片對應能量值
	};
	union {
		int maxatttack;//武器對應攻擊力
		int maxdefence;//防具對應防護力
		int maxpower;//消耗品, 卡片對應能量值
	};
	char desc[200];//道具的功能描述

}Prop;
//門派
typedef struct _marital {
	int id;
	char name[50];
	char type[50];
	COORD hqCoord;
	int isOpen;
	char desc[1000];
}Martial;

typedef struct _Player {
	int id;
	char name[50];
	char pass[50];
	int life;
	int level;
	int exp;
	int hp;
	int mp;
	int mpMax;
	int gold;
	Martial martial;
	Prop weapon;
	Prop armor;
	COORD coord;

}Player;
typedef struct _monster {
	int id;
	char name[50];
	int level;
	int hp;
	int att;
	int diff;
	int minMoney;
	int maxMoney;
	int exp;
	int state;
	COORD coord;

}Monster;


void Init();//初始化遊戲數據
void Show();//展示全局數據
void ShowWelcome();//顯示遊戲的歡迎信息
void ShowMap();//顯示遊戲地圖
void ShowInformation();//顯示遊戲地圖下方的遊戲信息
void ShowMainMenu();//顯示遊戲的主菜單
void ShowMapInfo(); //顯示地圖的信息
//處理遊戲主菜單的業務
void ProcessMainMenu(char key);
//在信息介面顯示玩家的個人資料
void ShowPlayInfo();
//在當前地圖顯示怪物
void ShowMonsters();

void Fight(int monsterId);

void Move(int xx,int yy);




