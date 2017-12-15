// ���ﳵ.cpp : Defines the entry point for the console application.
//ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include "stdafx.h"
//�궨��
#define COUNT sizeof(Goods)
#define LEN sizeof(struct Goods)
int num;

struct Goods
{
	long GoodsNum;
	char GoodsName[10];
	int GoodsPrice;
	struct Goods *next;
};
struct Goods *head,*tail;
struct Goods *ReadfromFile(void);
void GoodsAdd();
struct Goods *GoodsAlter();
void InitFace();
struct Goods *GoodsDel();
void InitFace();
void GoodsDemand();
void GoodsDerive(struct Goods *tou);
void EnterPassword();
void EnterFace();

void main(int argc, char* argv[])
{
	head=tail=NULL;
	system("color 1f");
	EnterPassword();
	InitFace();
	EnterFace();
}
//��Ʒ��Ϣ¼��
void GoodsAdd()
{
	char ichoose;
	struct Goods *p;
	struct Goods *pp;
	p=(struct Goods *)malloc(sizeof(struct Goods));//����������ڴ�ռ�����
	if(p==NULL)
	{
		printf("\t\t�ռ����ʧ��!");
		exit(0);
	}
	printf("\t\t��������Ʒ����:");
	scanf("%ld",&p->GoodsNum);
	printf("\t\t��������Ʒ��:");
	scanf("%s",&p->GoodsName);
	printf("\t\t��������Ʒ�۸�:");
	scanf("%d",&p->GoodsPrice);
	if(head==NULL)//�������Ϊ�գ���headΪͷ���
	{
		head=tail=p;
		tail->next=NULL;
	}
	else
	{
		tail->next=p;
		tail=p;
		tail->next=NULL;
	}
	printf("\t\t�����Ʒ��Ϣ�ɹ�!\n");
	printf("\t\t�Ƿ����(Y\\N)!");
	getchar();
	scanf("%c",&ichoose);
	if(ichoose=='Y'||ichoose=='y')
	{
		GoodsAdd();
	}
	else if(ichoose=='N'||ichoose=='n')
	{
		for(pp=head;pp!=NULL;pp=pp->next)
	{
		printf("\t\t%s\t\t%ld\t\t%d\n",pp->GoodsName,pp->GoodsNum,pp->GoodsPrice);
	}
		GoodsDerive(head);
	}
	
}

//��Ʒ��Ϣ�޸�
struct Goods *GoodsAlter()
{
	char AlterName[10];
	struct Goods *pp;
	struct Goods *p;
	p=head;
	for(pp=head;pp!=NULL;pp=pp->next)
	{
		printf("\t\t%s\t\t%ld\t\t%d\n",pp->GoodsName,pp->GoodsNum,pp->GoodsPrice);
	}
	if(head==NULL)
	{
		printf("\t\t���ﳵΪ��!\n");
		return(head);
	}
	printf("\t\t������Ҫ�޸ĵ���Ʒ������:");
	scanf("%s",&AlterName);
	while(strcmp(AlterName,p->GoodsName)!=0&&p->next!=NULL)
	{
		p=p->next;
	}
	if(strcmp(AlterName,p->GoodsName)==0)
	{
		printf("\t\t�����޸ĵ���Ʒ����:");
		scanf("%s",p->GoodsName);
		printf("\t\t�����޸ĺ�ļ۸�:");
		scanf("%d",&p->GoodsPrice);
		printf("\t\t��������:");
		scanf("%ld",&p->GoodsNum);
		printf("�޸ĳɹ�!");
	}
	else
	{
		printf("\t\t��������!\n");
	}
}
//��ʼ������
void InitFace()
{
	printf("\t\t*********************************************************\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t\t���ﳵϵͳ\t\t\t*\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t\t�汾�ţ�1.0\t\t\t*\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t����ʯ�ʹ�ѧ�ƿ�Ժ����������\t\t*\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t��д��;\t�޼���\t\t\t\t*\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t��дʱ��;   2017/12/12\t\t\t*\n");
	printf("\t\t*********************************************************\n");
	printf("\t\t");
	system("pause");//�������������
	system("cls");//����
}
//�������
void EnterPassword()
{
	int count=0,ch,i;
	char mima[100]={"000000\0'"};
	char input[100]={0};
	printf("\t\t*********************************************************\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t\t���ﳵϵͳ\t\t\t*\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t��������λ�������ϵͳ��\t\t*\n");
	printf("\t\t���������룺");
	ch=getch();
	for(i=0;i<100;i++)
	{
		input[i]=ch;
		if(input[i]=='\r')
		{
			input[i]='\0';
			break;
		}
		else
			printf("*");
		ch=getch();//�ӻ�������ȡ�س���
	}
	if(strcmp(mima,input)==0)
		{
			printf("\n");
			printf("\t\t������ȷ!\n");
			printf("\t\t3����Զ����빺�ﳵ!\n");
			Sleep(3000);//�ӳ�ʱ��
		}
	else
	{
		printf("\n");
		printf("\t\t�������!\n");
		printf("\t\t3����Զ��˳�!\n");
		Sleep(3000);//�ӳ�ʱ��
		exit(0);
	}
	system("cls");//����

}
//��Ʒɾ��
struct Goods *GoodsDel()
{
	char DelName;
	struct Goods *p=head,*pr=head,*pp;
	for(pp=head;pp!=NULL;pp=pp->next)
	{
		printf("\t\t%s\t\t%ld\t\t%d\n",pp->GoodsName,pp->GoodsNum,pp->GoodsPrice);
	}
	if(head==NULL)
	{
		printf("\t\t�޿�ɾ����Ʒ\n");
		return(head);
	}
	printf("\t\t������Ҫɾ������Ʒ����:");
	scanf("%s",DelName);
	while(strcmp(&DelName,p->GoodsName)!=0&&p->next!=NULL)
	{
		pr=p;
		p=p->next;
	}
	if(strcmp(&DelName,p->GoodsName)==0)
	{
		if(p==head)
		{
			head=p->next;
			printf("\t\tɾ���ɹ�\n");
		}
		else
		{
			pr->next=p->next;
			printf("ɾ���ɹ�!\n");
		}
		free(p);
	}
	else
	{
		printf("�������Ʒ�����д���!\n");
	}
}
//���ﳵ��Ϣ��ѯ
void GoodsDemand()
{
	struct Goods *node;
	node=ReadfromFile();
	//system("cls");
	printf("\t\t*********************************************************\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t\t���ﳵ��Ϣ��ѯ\t\t\t*\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*********************************************************\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t��Ʒ����\t��Ʒ����\tҩƷ�۸�\n");
	//for(node=head;node!=NULL;node=node->next)
	do
	{
		printf("\t\t%s\t\t%ld\t\t%d\n",node->GoodsName,node->GoodsNum,node->GoodsPrice);
		node=node->next;
	}while(node!=NULL);
}

//��Ʒ��Ϣ�������ļ�
void GoodsDerive(struct Goods *tou)
{
	struct Goods *p=tou;
	//char a[10]={"��Ʒ����"},b[10]={"��Ʒ����"},c[10]={"��Ʒ�۸�"},e[10]={"     "};
	FILE *fp;
	fp=fopen("��Ʒ��Ϣ.txt","ab");
	if(fp==NULL)
	{
		printf("���鵱ǰĿ¼�Ƿ����д��%s�Ĺ���","��Ʒ��Ϣ.txt");
	}
	//fprintf(fp,"%s\t\t\t%s\t\t\t%s\n",a,b,c);
	while(p!=NULL)
	{
		if(fwrite(p,LEN,1,fp)!=1)
		{
			printf("д�����ݴ���\n");
			fclose(fp);
			return;
		}
		p=p->next;
	}
	fclose(fp);
	printf("\t\t*********************************************************\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t\t��Ʒ��Ϣ����\t\t\t*\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*********************************************************\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t*\t\t\t\t\t\t\t*\n");
	printf("\t\t�ɹ������ݱ��浽%s�ļ���\n","��Ʒ��Ϣ.txt");
}

//�������
void EnterFace()
{
	char a;
	while(1)
	{
	printf("\t\t*********************************************************\n");
		printf("\t\t*\t\t\t\t\t\t\t*\n");
		printf("\t\t*\t\t\t\t\t\t\t*\n");
		printf("\t\t*\t\t\tҩƷ����ϵͳ\t\t\t*\n");
		printf("\t\t*\t\t\t\t\t\t\t*\n");
		printf("\t\t*\t\t\t\t\t\t\t*\n");
		printf("\t\t*\t\t1.��Ʒ��Ϣ���\t\t\t\t*\n");
		printf("\t\t*\t\t2.��Ʒ��Ϣɾ��\t\t\t\t*\n");
		printf("\t\t*\t\t3.��Ʒ��Ϣ�޸�\t\t\t\t*\n");
		printf("\t\t*\t\t4.��Ʒ��Ϣ��ѯ\t\t\t\t*\n");
		printf("\t\t*\t\t5.��Ʒ��Ϣ����\t\t\t\t*\n");
		printf("\t\t*\t\t6.�˳�ϵͳ\t\t\t\t*\n");
		printf("\t\t*\t\t\t\t\t\t\t*\n");
		printf("\t\t*\t\t\t\t\t\t\t*\n");
		printf("\t\t*\t\t����ʯ�ʹ�ѧ�ƿ�Ժ����������\t\t*\n");
		printf("\t\t*\t\t\t\t\t\t\t*\n");
		printf("\t\t*\t\t\t\t\t\t\t*\n");
		printf("\t\t*********************************************************\n");
		printf("\t\t*\t\t\t\t\t\t\t*\n");
		printf("\t\t*\t\t\t\t\t\t\t*\n");
		printf("\t\t*��ѡ��˵�1-4��");
		scanf("%d",&a);
				if(a==1)
		{
			system("cls");
			printf("\t\t*********************************************************\n");
			printf("\t\t*\t\t\t\t\t\t\t*\n");
			printf("\t\t*\t\t\t��Ʒ��Ϣ���\t\t\t*\n");
			printf("\t\t*\t\t\t\t\t\t\t*\n");
			printf("\t\t*********************************************************\n");
			printf("\t\t*\t\t\t\t\t\t\t*\n");
			printf("\t\t*\t\t\t\t\t\t\t*\n");
			GoodsAdd();
			printf("\t\t");
			system("pause");
			system("cls");
		}
		else if (a == 2)
		{
			system("cls");
			printf("\t\t*********************************************************\n");
			printf("\t\t*\t\t\t\t\t\t\t*\n");
			printf("\t\t*\t\t\t��Ʒ��Ϣɾ��\t\t\t*\n");
			printf("\t\t*\t\t\t\t\t\t\t*\n");
			printf("\t\t*********************************************************\n");
			printf("\t\t*\t\t\t\t\t\t\t*\n");
			printf("\t\t*\t\t\t\t\t\t\t*\n");
			printf("\t\t*\t\t\t\t\t\t\t*\n");
			printf("\t\t��Ʒ����\t��Ʒ���\t��Ʒ�۸�\n");
			GoodsDel();
			printf("\t\t");
			system("pause");
			system("cls");
		}
		else if (a == 3)
		{
			system("cls");
			printf("\t\t*********************************************************\n");
			printf("\t\t*\t\t\t\t\t\t\t*\n");
			printf("\t\t*\t\t\t��Ʒ��Ϣ�޸�\t\t\t*\n");
			printf("\t\t*\t\t\t\t\t\t\t*\n");
			printf("\t\t*********************************************************\n");
			printf("\t\t*\t\t\t\t\t\t\t*\n");
			printf("\t\t*\t\t\t\t\t\t\t*\n");
			printf("\t\t*\t\t\t\t\t\t\t*\n");
			printf("\t\t��Ʒ����\t��Ʒ���\t��Ʒ�۸�\n");
			GoodsAlter();
			printf("\t\t");
			system("pause");
			system("cls");
		}
		else if (a == 4)
		{
			system("cls");
			GoodsDemand();
			printf("\t\t");
			system("pause");
			system("cls");
		}
		else if(a==5)
		{
			system("cls");
			GoodsDerive(head);
			printf("\t\t");
			system("pause");
			system("cls");
		}
		else if(a==6)
		{
			printf("\t\t");
			exit(0);
		}
	}
}
//���ļ��н���Ϣ��ȡ
struct Goods *ReadfromFile(void)
{
	FILE *fp;
	struct Goods *tou=NULL;
	struct Goods *p1;
	struct Goods *p2;
	if((fp=fopen("��Ʒ��Ϣ.txt","rb+"))==NULL)
	{
		printf("��ȡʧ��\n");
		exit(0);
	}
	while(!feof(fp))
	{
		if((p1=(struct Goods*)malloc(LEN))==NULL){
			printf("�ڴ��������\n");
			fclose(fp);
			exit(0);
		}
		if(fread(p1,LEN,1,fp)!=1){
			free(p1);
			break;
		}
		if(tou==NULL)
			tou=p2=p1;
		else{
			p2->next=p1;
			p2=p1;
		}
	}
	/*while(!feof(fp))
	{
		p1=head;
		fread(p1,LEN,1,fp);
		p2=p1->next;
	}*/
	fclose(fp);
	return (tou);
}
