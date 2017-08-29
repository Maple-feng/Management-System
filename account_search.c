#include "fun.h"

void account_search(){
//int main(){
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

	fp = fopen("account.txt", "r+");
	if (NULL == fp){
		perror("open file fail");
		return -1;
	}
	while (fscanf(fp,"%s\t%s\t%d", s->name, s->pwd, &s->role)>0){
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
		printf("%s\t%s\t%d\n", q->name, q->pwd, q->role);
		q = q->next;
	}
	free(q);
	free(s);
	free(head);
	free(tail);
	q = NULL;
	s = NULL;
	head = NULL;
	tail = NULL;
	fclose(fp);
	system("pause");
	system("cls");
	return;
}