#include "fun.h"

void menu_stu(){
//int main(){
    char n;
loop:printf("*******************************************************************************\n");
	printf("*************Student	Information	Management	System*****************\n");
	printf("*******************************************************************************\n");
	printf("\n");
	printf("\n");
	printf("\n"); 
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("		1.search	student		information\n");
	printf("		9.exit\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("select a number:");
	fflush(stdin);
	scanf("%c", &n);
	system("cls");
	if (n == '1'){
		search_stu_menu();
		goto loop;
	}
	else if (n == '9'){
		printf("ллʹ�ã��ټ�\n");
		system("pause");
		return 0;
	}
	else{
		printf("�����������ȷ���룡\n");
		system("pause");
		system("cls");
		goto loop;
	}
	system("pause");
	return;
}