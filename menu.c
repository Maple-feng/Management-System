#include "fun.h"

void menu(){
//int main(){
    char n;
loop:printf("*******************************************************************************\n");
	printf("*************Student	Information	Management	System*****************\n");
	printf("*******************************************************************************\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("		1.search	student		information\n");
	printf("		2.add		student		information\n");
	printf("		3.update	student		information\n");
	printf("		4.delete	student		information\n");
	printf("		5.add		user		account\n");
	printf("		6.update	user		account\n");
	printf("		7.delete	user		account\n");
	printf("		8.search	user		account\n");
	printf("		9.exit\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("select a number:");
	fflush(stdin);
	scanf("%c", &n);
	system("cls");
	if (n == '1'){
		search_menu();
		goto loop;
	}
	else if (n == '2'){
		student_add();
		goto loop;
	}
	else if (n == '3'){
		update();
		goto loop;
	}
	else if (n == '4'){
		student_delete();
		goto loop;
	}
	else if (n == '5'){
		account_add();
		goto loop;
	}
	else if (n == '6'){
		accout_update();
		goto loop;
	}
	else if (n == '7'){
		account_delete();
		goto loop;
	}
	else if (n == '8'){
		account_search();
		goto loop;
	}
	else if (n == '9'){
		printf("谢谢使用，再见\n");
		system("pause");
		return 0;
	}
	else{
		printf("输入错误！请正确输入！\n");
		system("pause");
		system("cls");
		goto loop;
	}
	system("pause");
	return;
}