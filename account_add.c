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
	printf("�밴��һ�¸�ʽ�����û���Ϣ\tctrl+z�˳�\n");
	printf("�û���\t����\tȨ��\n");
	printf("���磺admin\tadmin\t1\n");
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