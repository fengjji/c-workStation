#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <easyx.h>
#include <cstdlib>
#include <conio.h>
#include <ctime>
//��Ҫ��ͷ�ļ�

typedef struct Linklist {//���Ķ���
	int data;
	struct Linklist *next;
}Linklist, *LNode;

void join_line() {
	static int x1 = 90;
	static int x2 = 135;
	setlinecolor(RED);//��������
	line(x1, 38, x2, 38);
	x1 = x1 + 120;
	x2 = x2 + 120;
}

void delet_line(int x1, int y1, int x2, int y2) {//��ɾ��ʱ������
	setlinecolor(RED);
	line(x1, y1, x2, y2);
}

void draw_Node(int flag, char s[]) {//����� ����� �ѹ̶� д����X,Y���� flag=0��ʾ���һ�������߲��û��� 
	static int node_x1 = 15;//���þ�̬����  ������֤�˵�����ִ����Ϻ󣬲����ڱ���������
	static int node_x2 = 90;
	static int line_x = 70;
	static int text_x = 20;
	static int text_c_x = 35;
	int length = strlen(s);
	settextstyle(20, 0, _T("����"));//������ʽ
	setlinecolor(RGB(255, 215, 0));//�߿���ɫ
	rectangle(node_x1, 15, node_x2, 65);//��������
	line(line_x, 15, line_x, 65);//�������εġ��ָ��ߡ�
	if (flag != 0) {
		Sleep(100);
		join_line();//��������
	}
	if (length == 4) {//�����ַ���������������λ��
		outtextxy(text_x, 30, s);//�ַ���������
	}
	else {
		outtextxy(text_c_x, 30, s);
	}
	node_x1 = node_x1 + 120;
	node_x2 = node_x2 + 120;
	line_x = line_x + 120;
	text_x = text_x + 120;
	text_c_x = text_c_x + 120;
	//���Ƶ�ƫ����
}

void travel_Node(char s[], int fnode) {//��Ԫ����  flag=0��ʾ���һ�������߲��û��� fnode=1��ʾ�ҵ�����ˣ�fnode=0��û�У�
	static int node_x1 = 135;//���þ�̬����  ������֤�˵�����ִ����Ϻ󣬲����ڱ���������
	static int node_x2 = 210;
	static int line_x = 190;
	static int text_x = 125;
	static int text_c_x = 155;
	int length = lstrlen(s);
	settextstyle(20, 0, _T("����"));
	setlinecolor(RGB(255, 215, 0));//
	rectangle(node_x1, 15, node_x2, 65);
	line(line_x, 15, line_x, 65);
	if (length == 4) {
		outtextxy(text_x, 30, s);
	}
	else {
		if (fnode == 1) {
			setlinecolor(RGB(0, 128, 0));//�ҵ���ɫ ʾ��һ�� �ǶԵ�ǰ���ڵĿ�������������ɫ ��������
			rectangle(node_x1, 15, node_x2, 65);
			line(line_x, 15, line_x, 65);
			outtextxy(text_c_x, 30, s);
			//fnode = 0  �ڲ�����Ҳû�� �ĸ�����������
		}
		else {
			outtextxy(text_c_x, 30, s);
		}
	}
	node_x1 = node_x1 + 120;
	node_x2 = node_x2 + 120;
	line_x = line_x + 120;
	text_x = text_x + 120;
	text_c_x = text_c_x + 120;
}

void delet_draw(char s[], int dnode) {
	static int node_x1 = 135;//���þ�̬����  ������֤�˵�����ִ����Ϻ󣬲����ڱ���������
	static int node_x2 = 210;
	static int line_x = 190;
	static int text_x = 125;
	static int text_c_x = 155;
	int length = lstrlen(s);
	settextstyle(20, 0, _T("����"));
	setlinecolor(RGB(255, 215, 0));//
	rectangle(node_x1, 15, node_x2, 65);
	line(line_x, 15, line_x, 65);
	if (length == 4) {
		outtextxy(text_x, 30, s);
	}
	else {
		if (dnode == 1) {//����ҵ� ��ɾ���Ľ�� ����������ֵ����ʾ���������Ӽ���
			setfillcolor(BLACK);//�ҵ���ɫ ʾ��һ��
			solidrectangle(node_x1, 15, node_x2, 65);
			delet_line(node_x1, 38, node_x2, 38);
		}
		else {
			outtextxy(text_c_x, 30, s);
		}
	}
	node_x1 = node_x1 + 120;
	node_x2 = node_x2 + 120;
	line_x = line_x + 120;
	text_x = text_x + 120;
	text_c_x = text_c_x + 120;
}

Linklist *create_linklist(char s[], int fnode, int dnode, int flag) {//��������
	Linklist * head, *p, *pwork;
	head = (Linklist *)malloc(sizeof(Linklist));
	head->next = NULL; //����ͷ���
	pwork = head;
	draw_Node(flag,s);
	while (1) {//Ĭ��ȫ����ֵ����0
		p = (Linklist *)malloc(sizeof(Linklist));
		InputBox(s, 10, "���������ֵ");
		int node_value;
		sscanf(s, "%d", &node_value);
		if (node_value != 0) {
			p->data = node_value;
			draw_Node(flag, s);
			pwork->next = p;
			pwork = pwork->next;
		}
		else {
			p->data = node_value;
			p->next = NULL;
			s[0] = '/';
			s[1] = '\0';
			flag = 0;
			draw_Node(flag, s);
			break;
		}
	}
	system("pause");//ϵͳ��ͣ
	return head;
}//�ɹ�

Linklist *modify_elem(char s[], Linklist *Head,int fnode) {//�޸������ĳ��ֵ  �ҵ������ֺ� ����޸�
	Linklist *ptr = Head->next;
	int find_node;
	InputBox(s, 10, "����������ҵ�ֵ");
	sscanf(s,"%d",&find_node); 
	while (ptr != NULL) {
		if (ptr->data == find_node) {//�ҵ��� ���޸�
			fnode = 1;//�ҵ���֮���ɫ
			InputBox(s, 10, "�������µ�ֵ");
			int new_value;
			sscanf(s, "%d", &new_value);
			travel_Node(s, fnode);
			fnode = 0;//�޸�fnode��ֵ
		}
		else {
			sprintf(s, "%d", ptr->data);
			travel_Node(s, fnode);
		}
		ptr = ptr->next;
	}
	return Head;
	system("pause");//ϵͳ��ͣ
}

Linklist *delet_elem(char s[], Linklist *Head, int dnode) {//ɾ�����  ���ǵ��ǿ��ӻ� �䱾�ʻ�������Ӧ�Ľ�� ֻ������ͼ�����һ��ɾ���ĸо� ��ʵ ϵͳ��δ�ͷŵ���ɾ���Ľ��
	Linklist *ptr = Head->next;
	int delet_node;
	InputBox(s, 10, "�������ɾ���Ľ���ֵ");
	sscanf(s, "%d", &delet_node);
	while (ptr != NULL) {
		if (ptr->data == delet_node) {
			dnode = 1;
			delet_draw(s, dnode);
			dnode = 0;
		}
		else {
			sprintf(s, "%d", ptr->data);
			delet_draw(s, dnode);
		}
		ptr = ptr->next;
	}
	return Head;
	system("pause");
}


