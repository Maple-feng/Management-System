#include "fun.h"

void accout_update(){
//int main(){
	FILE *fp;
	int num = 0;
	int n, m;
	char a[20];
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
	printf("��������Ҫ�޸������Ȩ�޵��˺ţ�\t(ctrl+z�˳�)\n");
	scanf("%s", a);
	//printf("%s\n", a);
	/*printf("%d\n", n);*/
	while (q != NULL){
		m = strcmp(q->name,a);
		if (m==0){
			printf("���ҳɹ�\n");
			printf("�밴��һ�¸�ʽ�����˻���Ϣ\n");
			printf("����\tȨ��\n");
			scanf("%s\t%d", q->pwd, &q->role);
		}
		q = q->next;
	}
	fseek(fp, 0, SEEK_SET);
	q = head->next;
	while (q != NULL){
		fprintf(fp,"%s\t%s\t%d\n", q->name, q->pwd, q->role);
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