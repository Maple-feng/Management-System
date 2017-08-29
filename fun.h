#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct account{
	char name[30];
	char pwd[20];
	int role;
	struct account *next;
}acc,*pacc;

typedef struct student{
	char id[10];
	char name[20];
	char sex[2];
	float score1;
	float score2;
	float score3;
	float score4;
	float score5;
	struct student *next;
}stu,*pstu;
void account_add();
void account_delete();
void account_search();
void accout_update();
void student_delete();
void menu();
void menu_stu();
void search();
void search_id();
void search_menu();
void search_name();
void search_stu_menu();
void student_add();
void update();