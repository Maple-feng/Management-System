#include "fun.h"

void account_add(){
	/*int main(){*/
	FILE *fp;
	int num = 0;
	int i;
	pacc head = (pacc)malloc(sizeof(acc));
	head->next = NULL;
	pacc cur = head;
	pacc tail = head;
	pacc s = (pacc)malloc(sizeof(acc));
	pacc q;
	memset(s, 0, sizeof(acc));

	fp = fopen("account.txt", "a+");
	if (NULL == fp){
		perror("open file fail");
		return -1;
	}
	printf("请按照一下格式输入用户信息\tctrl+z退出\n");
	printf("用户名\t密码\t权限\n");
	printf("例如：admin\tadmin\t1\n");
	while (scanf("%s\t%s\t%d", s->name, s->pwd, &s->role)>0){
		num++;
		s->next = tail->next;
		tail->next = s;
		tail = s;
		s = (pacc)malloc(sizeof(acc));
		memset(s, 0, sizeof(acc));
	}
	q = head->next;

	fseek(fp, 0, SEEK_SET);
	while (q != NULL){
		fprintf(fp,"%s\t%s\t%d\n", q->name, q->pwd, q->role);
		q = q->next;
	}
	free(q);
	free(s);
	free(head);
	q = NULL;
	s = NULL;
	head = NULL;
	tail = NULL;
	fclose(fp);
	system("pause");
	system("cls");
	return;
}