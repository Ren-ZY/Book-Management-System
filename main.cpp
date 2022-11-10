#include"superadmin.h"
#include"usr.h"



int main(){

	char choice_2;
	while (1)
	{
		system("cls");
		printf("\n\n");
		printf("**********************************欢迎使用图书销售管理系统****************************\n\n");
		printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n\n"); 
		printf("※※※※※※※※    1 = 进入超级管理员用户系统                      ※※※※※※※※※\n");
		printf("※※※※※※※※    2 = 进入普通管理员用户系统                      ※※※※※※※※※\n");
		printf("※※※※※※※※    3 = 退出                                        ※※※※※※※※※\n\n");
		printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n\n"); 
		printf("**************************************************************************************\n\n");
		gets(&choice_2);

		switch (choice_2)
		{

		case '1': system("cls"); Administer(); break; //管理员 
		case '2': system("cls"); usr(); break;

		case '3':
			printf("感谢使用!!");
			Sleep(1500);
			exit(0); break;

		default:
			printf("请按提示重新输入！！");
			Sleep(1500);
			system("cls");
			break;
		}
	}

	return 0;
}