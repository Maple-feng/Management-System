#include "fun.h"

int main(){
	FILE *fp;
	char a[30] = { 0 };
	char b[20] = { 0 };
	char ch;
	int i=0;
	int m, n=0;
	pacc head = (pacc)malloc(sizeof(acc));
	head->next = NULL;
	pacc q = head;
	pacc tail = head;
	pacc cur = head;
	pacc s = (pacc)malloc(sizeof(acc));
	pacc pre;
	memset(s, 0, sizeof(acc));

	fp = fopen("account.txt", "r+");
	if (NULL == fp){
		perror("open file fail");
		return -1;
	}
	while (fscanf(fp, "%s\t%s\t%d", s->name, s->pwd, &s->role) > 0){
		s->next = tail->next;
		tail->next = s;
		tail = s;
		s = (pacc)malloc(sizeof(acc));
		memset(s, 0, sizeof(acc));
	}
	fseek(fp, 0, SEEK_SET);
	printf("enter user name:\n");
	scanf("%s", a);
	pre = head;
	while (cur != NULL){
		m = strcmp(cur->name, a);
		if (m == 0){
			system("cls");
			printf("enter user password:\n");
			while ((ch = getch()) != '\r'&&i>=0){
				if ('\b'== ch){
					b[i--] = 0;
					printf("\b \b");
				}
				else{
					b[i] = ch;
					i++;
					printf("*");
				}
			}
			m = strcmp(cur->pwd, b);
			if (m == 0){
				printf("\n登陆成功\n");
				n = cur->role;
				getchar();
				break;
			}
			else{
				printf("密码不正确\n");
			}
		}
		pre = cur;
		cur = cur->next;
	}
	system("pause");
	system("cls");
	if (1 == n){
		menu();
	}
	else if(2 == n){
		menu_stu();
	}
	else{
		printf("权限有问题无法查询\n");
		printf("谢谢使用\n");
		system("pause");
	}
	free(q);
	free(s);
	free(cur);
	q = NULL;
	s = NULL;
	cur = NULL;
	return 0;
}