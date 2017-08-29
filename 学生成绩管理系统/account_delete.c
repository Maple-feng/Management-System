#include "fun.h"

void account_delete(){
	FILE *fp;
	FILE *fp1;
	char a[30];
	int m, n;
	pacc head = (pacc)malloc(sizeof(acc));
	head->next = NULL;
	pacc q = head;
	pacc tail = head;
	pacc cur = head;
	pacc s = (pacc)malloc(sizeof(acc));
	pacc pre;
	memset(s, 0, sizeof(acc));

	fp = fopen("account.txt", "r");
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
	fp1 = fopen("account.txt", "w+");
	if (NULL == fp1){
		perror("open file fail");
		return -1;
	}
	printf("ÇëÊäÈëÒªÉ¾³ýµÄÕËºÅ\t(ctrl+zÍË³ö)\n");
	printf("ÀýÈç£ºlili\n");
	scanf("%s", a);
	pre = head;
	while (cur != NULL){
		m = strcmp(cur->name, a);
		if (m == 0){
			pre->next = cur->next;
		}
		pre = cur;
		cur = cur->next;
	}
	fclose(fp);
	q = head->next;
	while (q != NULL){
		fprintf(fp1, "%s\t%s\t%d\n", q->name, q->pwd, q->role);
		q = q->next;
	}
	free(q);
	free(s);
	free(head);
	q = NULL;
	s = NULL;
	head = NULL;
	tail = NULL;
	cur = NULL;
	fclose(fp1);
	system("pause");
	system("cls");
	return;
}