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
//必要的头文件

typedef struct Linklist {//结点的定义
	int data;
	struct Linklist *next;
}Linklist, *LNode;

void join_line() {
	static int x1 = 90;
	static int x2 = 135;
	setlinecolor(RED);//画连接线
	line(x1, 38, x2, 38);
	x1 = x1 + 120;
	x2 = x2 + 120;
}

void delet_line(int x1, int y1, int x2, int y2) {//待删除时的样子
	setlinecolor(RED);
	line(x1, y1, x2, y2);
}

void draw_Node(int flag, char s[]) {//画结点 长宽高 已固定 写给出X,Y坐标 flag=0表示最后一条连接线不用画了 
	static int node_x1 = 15;//利用静态变量  这样保证了当函数执行完毕后，不至于变量被回收
	static int node_x2 = 90;
	static int line_x = 70;
	static int text_x = 20;
	static int text_c_x = 35;
	int length = strlen(s);
	settextstyle(20, 0, _T("黑体"));//字体样式
	setlinecolor(RGB(255, 215, 0));//边框颜色
	rectangle(node_x1, 15, node_x2, 65);//画正方形
	line(line_x, 15, line_x, 65);//画正方形的“分割线”
	if (flag != 0) {
		Sleep(100);
		join_line();//画连接线
	}
	if (length == 4) {//根据字符串长度设置字体位置
		outtextxy(text_x, 30, s);//字符串的设置
	}
	else {
		outtextxy(text_c_x, 30, s);
	}
	node_x1 = node_x1 + 120;
	node_x2 = node_x2 + 120;
	line_x = line_x + 120;
	text_x = text_x + 120;
	text_c_x = text_c_x + 120;
	//下移的偏移量
}

void travel_Node(char s[], int fnode) {//找元素用  flag=0表示最后一条连接线不用画了 fnode=1表示找到结点了（fnode=0则没有）
	static int node_x1 = 135;//利用静态变量  这样保证了当函数执行完毕后，不至于变量被回收
	static int node_x2 = 210;
	static int line_x = 190;
	static int text_x = 125;
	static int text_c_x = 155;
	int length = lstrlen(s);
	settextstyle(20, 0, _T("黑体"));
	setlinecolor(RGB(255, 215, 0));//
	rectangle(node_x1, 15, node_x2, 65);
	line(line_x, 15, line_x, 65);
	if (length == 4) {
		outtextxy(text_x, 30, s);
	}
	else {
		if (fnode == 1) {
			setlinecolor(RGB(0, 128, 0));//找到变色 示意一下 是对当前所在的框框的所有线条变色 其他不变
			rectangle(node_x1, 15, node_x2, 65);
			line(line_x, 15, line_x, 65);
			outtextxy(text_c_x, 30, s);
			//fnode = 0  内部该了也没用 改副本不起作用
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
	static int node_x1 = 135;//利用静态变量  这样保证了当函数执行完毕后，不至于变量被回收
	static int node_x2 = 210;
	static int line_x = 190;
	static int text_x = 125;
	static int text_c_x = 155;
	int length = lstrlen(s);
	settextstyle(20, 0, _T("黑体"));
	setlinecolor(RGB(255, 215, 0));//
	rectangle(node_x1, 15, node_x2, 65);
	line(line_x, 15, line_x, 65);
	if (length == 4) {
		outtextxy(text_x, 30, s);
	}
	else {
		if (dnode == 1) {//如果找到 待删除的结点 则这个点的数值不显示，用先连接即可
			setfillcolor(BLACK);//找到变色 示意一下
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

Linklist *create_linklist(char s[], int fnode, int dnode, int flag) {//创建链表
	Linklist * head, *p, *pwork;
	head = (Linklist *)malloc(sizeof(Linklist));
	head->next = NULL; //建立头结点
	pwork = head;
	draw_Node(flag,s);
	while (1) {//默认全部数值大于0
		p = (Linklist *)malloc(sizeof(Linklist));
		InputBox(s, 10, "请输入结点的值");
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
	system("pause");//系统暂停
	return head;
}//成功

Linklist *modify_elem(char s[], Linklist *Head,int fnode) {//修改链表的某个值  找到该数字后 随机修改
	Linklist *ptr = Head->next;
	int find_node;
	InputBox(s, 10, "请输入带查找的值");
	sscanf(s,"%d",&find_node); 
	while (ptr != NULL) {
		if (ptr->data == find_node) {//找到了 就修改
			fnode = 1;//找到了之后变色
			InputBox(s, 10, "请输入新的值");
			int new_value;
			sscanf(s, "%d", &new_value);
			travel_Node(s, fnode);
			fnode = 0;//修改fnode的值
		}
		else {
			sprintf(s, "%d", ptr->data);
			travel_Node(s, fnode);
		}
		ptr = ptr->next;
	}
	return Head;
	system("pause");//系统暂停
}

Linklist *delet_elem(char s[], Linklist *Head, int dnode) {//删除结点  考虑到是可视化 其本质还是找相应的结点 只是利用图像给人一种删除的感觉 其实 系统并未释放掉待删除的结点
	Linklist *ptr = Head->next;
	int delet_node;
	InputBox(s, 10, "请输入待删除的结点的值");
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


