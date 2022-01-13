#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include<time.h>
#include<stdlib.h>

#define USERNAME "zhangsan"
#define PASSWD   "1234abcd"
#define NUM 32
#define TOP 100


int Fact(int n)//阶乘
{
	int sum = 1;
	while (n > 0) {
		sum = sum * n;
		n--;
	}
	return sum;
}

int SumFact(int top)//阶乘和
{
	int sum = 0;
	for (int i = 1; i <= top; i++) {
		sum += Fact(i);

	}
	return sum;
}

void dayingzifu()
{
	char a[] = "hello bit!";
	char b[] = "##########";
	int left = 0;
	int right = strlen(b) - 1;
	printf("%s\r", b);
	while (left <= right) {
		b[left] = a[left];
		b[right] = a[right];
		left++, right--;
		printf("%s\r", b);

		Sleep(1000);
	}
	printf("\n");
}

void CountDown(int times)//锁住的时间
{
	while (times) {
		printf("你的系统已经被锁住，剩余....%2dS\r", times);
		times--;
		Sleep(1000);
	}
	printf("\n");
}

int Lock(int level)//锁  函数
{
	switch (level) {
	case 1:
		CountDown(10);
		break;
	case 2:
		CountDown(20);
		break;
	case 3:
		break;
		CountDown(30);
	default:
		break;
	}
}

//sucess 1，failed 0
int Login()//登录系统
{
	int count = 3;
	int lock_count = 0;
	char name[NUM];
	char pswd[NUM];

	do {
		name[0] = '\0';
		pswd[0] = '\0';

		printf("请输入用户名# ");
		scanf("%s", name);//name是数组不用带& 
		printf("请输入你的密码#");
		scanf("%s", pswd);

		if (0 == strcmp(name, USERNAME) && 0 == strcmp(pswd, PASSWD)) {
			return 1;
		}
		count--;
		if (count <= 0) {
			lock_count++;
			Lock(lock_count);
			count = 3;
		}
		else {
			printf("认证失败，你还有%d次机会！\n", count);
		}
	} while (1);
	return 0;
}

void Menu()
{
	printf("***********************\n");
	printf("****     1.Play    ****\n");
	printf("****     0.Exit    ****\n");
	printf("***********************\n");
	printf("Please Select>");
}

void Game()
{
	int data = rand() % TOP + 1;
	int x = 0;
	while (1) {
		printf("guess> ");
		scanf("%d", &x);
		if (x > data) {
			printf("猜大了\n");
		}
		else if (x < data) {
			printf("猜小了\n");
		}
		else {
			printf("猜对了\n");
			break;
		}
	}printf("拜拜\n");

}

int MyMax(int a, int b)
{
	return a > b ? a : b;
}

void Swap(int *a, int *b)
{

	int temp = *a;
	*a = *b;
	*b = temp;;

}

int main()
{
	int  x = 10;
	int  y = 20;

	int z = MyMax(x, y);
	printf("max = %d\n", z);

	printf("before: %d  %d\n", x, y);
	Swap(&x, &y);
	printf("after: %d  %d\n", x, y);
	

	//int a[10];
	//for (int i = 0; i < 10; i++) {
	//	printf("a[%d] :%d\n", i, a[i]);
	//}
	//memset(a, 0, sizeof(a));
	//for (int i = 0; i < 10; i++) {
	//	printf("a[%d] :%d\n", i, a[i]);
	//}

	//Login();
	//srand((unsigned long)time(NULL));

	//int quit = 0;
	//while (!quit) {
	//	Menu();
	//	int select = 0;
	//	scanf("%d", &select);
	//	switch (select) {
	//	case 1:
	//		Game();
	//		break;
	//	case 0:
	//		quit = 1;
	//		break;
	//	default:
	//		printf("输入有误！重新选择！\n");
	//		break;
	//	}
	//}


	//int ret = Login();
	//if (ret) {
	//	printf("welcome %s login my system \n", USERNAME);
	//}


	//dayingzifu();

	//int x = 5;
	//int ret = SumFact(x);
	//printf("%d", ret);

	//int x = 5;
	//int ret = Fact(x);

	//printf("ret : %d\n", ret);
	// 
	 
	 
	 
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int num;
	//printf("输入你要查找的数据");
	//scanf("%d", &num);
	//int left = 0, right = 9;
	//while (left <= right) {
	//	int mid_idx = (left + right) / 2;
	//	if (num > arr[mid_idx]) {
	//		left = mid_idx + 1;
	//	}
	//	else if (num < arr[mid_idx]) {
	//		right = mid_idx - 1;
	//	}
	//	else {
	//		printf("idx:%d\n", mid_idx);
	//		break;
	//	}
	//}

	// 
	//printf("");
	return 0;
}