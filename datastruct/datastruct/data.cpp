#include "myfunction.h"
int main() {
	initgraph(1000,600);
	Linklist *HEAD;
	int flag = 1, fnode = 0, dnode = 0;
	char s[10] = "Head";
	HEAD = create_linklist(s, fnode, dnode, flag);
	//modify_elem(s, HEAD, fnode);//��
	delet_elem(s, HEAD, dnode);//ɾ��
	system("pause");
	_getch();
	closegraph();
	system("pause");
	return 0;
}

