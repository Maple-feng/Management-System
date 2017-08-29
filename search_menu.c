#include "fun.h"

void search_menu(){
	char i;
loop:printf("*******************************************************************************\n");
	printf("*************Student	Information	Management	System*****************\n");
	printf("*******************************************************************************\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("		0.search	all\n");
	printf("		1.search	by	name\n");
	printf("		2.search	by	id\n");
	printf("		3.return\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("select a number:");
	fflush(stdin);
	scanf("%c", &i);
	if (i == '0'){
		system("cls");
		search();
		goto loop;
	}
	else if (i == '1'){
		system("cls");
		search_name();
		goto loop;
	}
	else if (i == '2'){
		system("cls");
		search_id();
		goto loop;
	}
	else if (i == '3'){
		system("cls");
		return;
	}
	else{
		system("cls");
		printf(" ‰»Î”–ŒÛ\n");
		system("pause");
		system("cls");
		goto loop;
	}
	system("pause");
	system("cls");
	return;
}