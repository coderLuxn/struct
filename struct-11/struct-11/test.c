#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//自定义类型：结构体,枚举，联合
//一.结构体
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//结构体
//typedef 相当于重命名struct Stu成s
//struct-结构体关键字 Stu-结构体标签 struct Stu -结构体类型
//typedef struct Stu
//{
//	//定义一个结构体类型
//	//成员变量
//	char name[20];
//	short age;
//	char tale[12];
//	char sex[5];
//}s;
//int main()
//{
//	struct Stu s1;//创建结构体类型
//	s s2;
//	return 0;
//}

//嵌套结构体
//struct S
//{
//	char name[10];
//	short age;
//	char tale[12];
//	char sex[10];
//};
//struct T
//{
//	char ch[20];
//	struct S s;
//	char* pc;
//};
//int main()
//{
//	char arr[] = "hello lxn";
//	struct T t = { "123",{"张三",20,"18225334103","女"},arr };
//	printf("%s\n", t.ch);
//	printf("%s\n", t.s.name);
//	printf("%d\n", t.s.age);
//	printf("%s\n", t.s.tale);
//	printf("%s\n", t.s.sex);
//	printf("%s\n", t.pc);
//	return 0;
//}

//打印
//typedef struct Stu
//{
//	char name[10];
//	short age;
//	char tale[12];
//	char sex[10];
//}stu;
//void print1(stu a)
//{
//	printf("name: %s\n", a.name);
//	printf("age: %d\n", a.age);
//	printf("tale: %s\n", a.tale);
//	printf("sex: %s\n", a.sex);
//}
//void print2(struct Stu* pa)
//{
//	printf("name: %s\n", pa->name);//结构体指针
//
//}
//
//int main()
//{
//	stu s1 = { "张三",20,"18225334103","男" };
//	//print1(s1);
//	print2(&s1);
//	return 0;
//}

//（1）匿名结构体
//struct
//{
//	char name[20];
//	int age;
//}x;

//(2) 结构体自引用（链表）
//struct Node
//{
//	int date;
//	struct Node* nest;
//};

//(3)结构体变量的定义和初始化
//struct s
//{
//	char c;
//	int a;
//};
//
//int main()
//{
//	struct s s1 = { 'L',30};
//	return 0;
//}

//(4)结构体内存对齐
//结构体的内存对齐是拿空间换时间的做法
// struct s1
//{
//	char c1;
//	char c2;
//	int a;
//};
//
//struct s2
//{
//	char c1;
//	int a;
//	char c2;
//};
//
//int main()
//{
//	struct s1 s1 = { 0 };
//	struct s2 s2 = { 0 };
//	printf("%d\n", sizeof(s1));
//	printf("%d\n", sizeof(s2));
//	return 0;
//}

//(5)修改默认对齐数 #pragme
//#pragma pack(4)
//struct s2
//{
//	char c1;
//	double d;
//	char c2;
//	int a;
//};
//#pragma pack()
//int main()
//{
//	struct s2 s2 = { 0 };//没有pragma就是24
//	printf("%d\n", sizeof(s2));//20
//	return 0;
//}

//(6)offsetof 计算偏移量
#include <stddef.h>
//int main()
//{
//	struct s2 s2 = { 0 };
//	printf("%d\n", offsetof(struct s2,d));
//	printf("%d\n", offsetof(struct s2, c1));
//	printf("%d\n", offsetof(struct s2, a));
//	return 0;
//}

//(7)结构体传参
//struct S
//{
//	char c;
//	int a;
//	double d;
//};

//传值（错误）
//void Init(struct S tem)//传的是实参的一份临时拷贝
//{
//	tem.c = 'w';
//	tem.a = 100;
//	tem.d = 3.13;
//}

//传址
//void Init( struct S* tem)
//{
//	tem->c ='w';
//	tem->a = 100;
//	tem->d = 3.14;
//	/*(*tem).c = 'w';
//	(*tem).a = 100;
//	(*tem).d = 3.14;*/
//}
//
//void print1(struct S tem)//传值
//{
//	printf("%c %d %lf\n", tem.c, tem.a, tem.d);
//}
//
//void print2(const struct S* tem)//传址
//{
//	printf("%c %d %lf", tem->c, tem->a, tem->d);
//}
//int main()
//{
//	struct S s={0};
//	//如果要初始化传参Init
//	//Init(s);//传值
//	Init(&s);//传址
//	print1(s);
//	print2(&s);
//	/*s.c = 'w';
//	s.a = 100;
//	s.d = 3.14;
//	return 0;*/
//}

//1.位段
//struct S1
//{
//	int a : 2;
//	int b : 5;
//	int c : 10;
//	int d : 30;
//};
//
//struct S2
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//
//int main()
//{
//	//struct S1 s1 = { 0 };
//	struct S2 s2 = { 0 };
//	s2.a = 10;
//	s2.b = 20;
//	s2.c = 3;
//	s2.d = 4;
//	//printf("%d\n", sizeof(s1));//8
//	//printf("%d\n", sizeof(s2));//3
//	return 0;
//}

//2.枚举enum
//enum Sex
//{
//	MALE=6,
//	FAMALE,
//    CECRET,
//};
//
//int main()
//{
//	enum Sex s={ MALE};
//	printf("%d", s);
//	enum Sex s1 = { FAMALE };
//	printf("%d", s1);
//	enum Sex s2 = { CECRET };
//	printf("%d\n", s2);
//	enum Sex s3 = 0;
//	printf("%d", sizeof(s3));//4
//	return 0;
//}

//联合-共用体-联合体union
// 判断大小端字节序存储模式
//int check_sys(int* a)
//{
//	if (1 == *(char*)a)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int a = 1;
//	int ret=check_sys(&a);
//	if (ret == 1)
//	{
//		printf("小端模式");
//	}
//	else
//	{
//		printf("大端模式");
//	}
//	return 0;
//}

//int check_sys()
//{
//	union Un
//	{
//		char c;
//		int i;
//	};
//	union Un u;
//	u.i = 1;
//	return u.c;
//}
//int main()
//{
//	int ret=check_sys();
//	if (ret == 1)
//	{
//		printf("小端模式");
//	}
//	else
//	{
//		printf("大端模式");
//	}
//	return 0;
//	return 0;
//}

//union Un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	union Un u;
//	printf("%d\n", sizeof(u));//4
//	printf("%p\n", &u);
//	printf("%p\n", &(u.i));
//	printf("%p\n", &(u.c));
//	return 0;
//}

