#define _CRT_SECURE_NO_WARNINGS
#define MAXBUFLEN 255

#include <stdio.h>   
#include <string.h>   
#include <windows.h>    //此头文件必加
#include <sql.h>    
#include <sqlext.h>    
#include <sqltypes.h>    
#include <odbcss.h>
#include"MD5.h"



SQLHENV henv = SQL_NULL_HENV;
SQLHDBC hdbc = SQL_NULL_HDBC;
SQLHSTMT hstmt = SQL_NULL_HSTMT;

int bill = 10;

char md[32];

int main();

void Administer()/* 显示管理员管理系统选择界面 */
{
	int flag = 0;
	char id[20];
	char password[20];


	printf("请输入超级管理员账号: ");
	gets(id);
	printf("请输入超级管理员密码: ");
	gets(password);

	RETCODE resultCode;
	//预定义SQL语句

	
	
	

	//定义连接语句，使用SQLDriverConnect方式连接数据源。127.0.0.1指本机，UID和PWD分别为用户名和密码。
	SQLCHAR ConnStrIn[MAXBUFLEN] =
		"DRIVER={SQL Server}; SERVER=DESKTOP-4J9BPKN\\SQL2008;UID=ren; PWD=ren791350;Trusted_Connection=yes;DATABASE=sellmanage; ";

	//分配环境句柄 ，若分配失败则打印错误消息
	resultCode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
	//设置环境句柄
	resultCode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	//2.连接句柄  
	resultCode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
	resultCode = SQLDriverConnect(hdbc, NULL, ConnStrIn, SQL_NTS, NULL, NULL, NULL, SQL_DRIVER_NOPROMPT);
	//判断连接是否成功  
	if ((resultCode != SQL_SUCCESS) && (resultCode != SQL_SUCCESS_WITH_INFO))
	{
		printf("failed to connect\n");  Sleep(1500); exit(0);
	}

		resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
		//第一种方式:直接执行 
		UCHAR sql_0[MAXBUFLEN] = "select * from superadmin";
		SQLExecDirect(hstmt, sql_0, 128); //第三个参数的值不可小于被执行sql语句的长度

		char list1[20];
		char list2[20];
		SQLINTEGER name_length, pwd_length;
		SQLBindCol(hstmt, 1, SQL_C_CHAR, list1, 20, 0);
		SQLBindCol(hstmt, 2, SQL_C_CHAR, list2, 20, 0);
		resultCode = SQLFetch(hstmt);
		if (strcmp(id, list1) != 0 || strcmp(password, list2) != 0){
			printf("账号或密码错误！\n"); Sleep(1500);  system("cls");   main();
		}
		
		resultCode = SQLFetch(hstmt);
		system("cls");

			while (1)
			{

				printf("\n\n\n");
				printf("************************************************************************************\n\n");
				printf("※※※※※※※※※※※※※※※※※请选择管理项目※※※※※※※※※※※※※※※※※※\n");
				printf("※※※※※  0 = 添加用户                                                    ※※※※\n");
				printf("※※※※※  1 = 查看所有用户资料                                            ※※※※\n");
				printf("※※※※※  2 = 书籍查询                                                    ※※※※\n");
				printf("※※※※※  3 = 图书信息修改                                                ※※※※\n");
				printf("※※※※※  4 = 图书进货                                                    ※※※※\n");
				printf("※※※※※  5 = 进货付款                                                    ※※※※\n");				
				printf("※※※※※  6 = 图书退货                                                    ※※※※\n");
				printf("※※※※※  7 = 添加新书                                                    ※※※※\n");
				printf("※※※※※  8 = 书籍购买                                                    ※※※※\n");
				printf("※※※※※  9 = 财务管理                                                    ※※※※\n");
				printf("※※※※※  a = 查看账单                                                    ※※※※\n");
				printf("※※※※※  q = 退出系统                                                    ※※※※\n");
				printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n\n");
				printf("************************************************************************************\n\n");
				printf("请选择?\n");
				char choice_1;
				gets(&choice_1);

				switch (choice_1)
				{

				case '0':{
							 system("cls");
							 resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							 char a[6];
							 unsigned char b[6];
							 char c[20];
							 char d[20];
							 char e[20];
							 char f[20];

						
							 printf("请输入新添加用户的账号：");
							 gets(a);
							 printf("请输入新添加用户的密码：");
							 scanf("%s", b);
							 char temp;
							 gets(&temp);
							 printf("请输入新添加用户的真实姓名：");
							 gets(c);
							 printf("请输入新添加用户的工号：");
							 gets(d);
							 printf("请输入新添加用户的性别：");
							 gets(e);
							 printf("请输入新添加用户的年龄：");
							 gets(f);
			                 
							 md5(b);

							 UCHAR sql_1[MAXBUFLEN] = "insert into usr values(?,?,?,?,?,?);";
							 SQLINTEGER p = SQL_NTS;
							 //1预编译   
							 SQLPrepare(hstmt, sql_1, 128);
							 //2 绑定参数值   
							 SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &a, 0, &p);
							 SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &md, 0, &p);
							 SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &c, 0, &p);
							 SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &d, 0, &p);
							 SQLBindParameter(hstmt, 5, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &e, 0, &p);
							 SQLBindParameter(hstmt, 6, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &f, 0, &p);
							 //3 执行  
							 SQLExecute(hstmt);

							 printf("添加成功！");
							 Sleep(1500);
							 system("cls");
							 break; }

				case '1':{
							 system("cls");
							 resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							 char a[20];
							 char b[20];
							 char c[20];
							 char d[20];
							 char e[20];
							 char f[20];
							 UCHAR sql_2[MAXBUFLEN] = "select * from usr";
							 SQLExecDirect(hstmt, sql_2, 128);
							 SQLBindCol(hstmt, 1, SQL_C_CHAR, a, 20, 0);
							 SQLBindCol(hstmt, 2, SQL_C_CHAR, b, 20, 0);
							 SQLBindCol(hstmt, 3, SQL_C_CHAR, c, 20, 0);
							 SQLBindCol(hstmt, 4, SQL_C_CHAR, d, 20, 0);
							 SQLBindCol(hstmt, 5, SQL_C_CHAR, e, 20, 0);
							 SQLBindCol(hstmt, 6, SQL_C_CHAR, f, 20, 0);
							
							 do{
								 resultCode = SQLFetch(hstmt);
								 if (resultCode == SQL_NO_DATA)
									 break;
								 printf("%s %s %s %s %s %s\n", a, b, c, d, e, f);
							 } while (true);

							 char temp;
							 printf("输入任意值返回......\n");
							 gets(&temp);
							 system("cls");
							 break; }

				case '2':{    
							 system("cls");
							 printf("请输入查询方式\n1=book_id\n2=ISBN\n3=book_name\n4=author\n5=publisher\n");
							 char choice_3;
							 gets(&choice_3);

							 switch (choice_3){
							 case '1':{
										  system("cls");
										  printf("请输入书籍编号:");
										  char book_id[5];
										  gets(book_id);
										  char a[5];
										  char b[20];
										  char c[20];
										  char d[20];
										  char e[20];
										  char f[20];
										  int g;
										  resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
										  UCHAR sql_3[MAXBUFLEN] = "select * from books";
										  SQLExecDirect(hstmt, sql_3, 128);
										  SQLBindCol(hstmt, 1, SQL_C_CHAR, a, 20, 0);
										  SQLBindCol(hstmt, 2, SQL_C_CHAR, b, 20, 0);
										  SQLBindCol(hstmt, 3, SQL_C_CHAR, c, 20, 0);
										  SQLBindCol(hstmt, 4, SQL_C_CHAR, d, 20, 0);
										  SQLBindCol(hstmt, 5, SQL_C_CHAR, e, 20, 0);
										  SQLBindCol(hstmt, 6, SQL_C_CHAR, f, 20, 0);
										  SQLBindCol(hstmt, 7, SQL_C_SLONG, &g, 20, 0);
										 
										  do{
											  resultCode = SQLFetch(hstmt);
											  if (resultCode == SQL_NO_DATA)
												  break;
											  if (strcmp(book_id, a) == 0)
												  printf("%s %s %s %s %s %s %d\n", a, b, c, d, e, f, g);
										  } while (true);

										  char temp;
										  printf("输入任意值返回......\n");
										  gets(&temp);
										  system("cls");
										  break; }
							 case '2':{
										  system("cls");
										  printf("请输入ISBN:");
										  char ISBN[20];
										  gets(ISBN);
										  char a[20];
										  char b[20];
										  char c[20];
										  char d[20];
										  char e[20];
										  char f[20];
										  int g;
										  resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
										  UCHAR sql_3[MAXBUFLEN] = "select * from books";
										  SQLExecDirect(hstmt, sql_3, 128);
										  SQLBindCol(hstmt, 1, SQL_C_CHAR, a, 20, 0);
										  SQLBindCol(hstmt, 2, SQL_C_CHAR, b, 20, 0);
										  SQLBindCol(hstmt, 3, SQL_C_CHAR, c, 20, 0);
										  SQLBindCol(hstmt, 4, SQL_C_CHAR, d, 20, 0);
										  SQLBindCol(hstmt, 5, SQL_C_CHAR, e, 20, 0);
										  SQLBindCol(hstmt, 6, SQL_C_CHAR, f, 20, 0);
										  SQLBindCol(hstmt, 7, SQL_C_SLONG, &g, 20, 0);
										  
										  do{
											  resultCode = SQLFetch(hstmt);
											  if (resultCode == SQL_NO_DATA)
												  break;
											  if (strcmp(ISBN, b) == 0)
												  printf("%s %s %s %s %s %s %d\n", a, b, c, d, e, f, g);
										  } while (true);

										  char temp;
										  printf("输入任意值返回......\n");
										  gets(&temp);
										  system("cls");
										  break; }
							 case '3':{
										  system("cls");
										  printf("请输入书名:");
										  char book_name[20];
										  gets(book_name);
										  char a[20];
										  char b[20];
										  char c[20];
										  char d[20];
										  char e[20];
										  char f[20];
										  int g;
										  resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
										  UCHAR sql_3[MAXBUFLEN] = "select * from books";
										  SQLExecDirect(hstmt, sql_3, 128);
										  SQLBindCol(hstmt, 1, SQL_C_CHAR, a, 20, 0);
										  SQLBindCol(hstmt, 2, SQL_C_CHAR, b, 20, 0);
										  SQLBindCol(hstmt, 3, SQL_C_CHAR, c, 20, 0);
										  SQLBindCol(hstmt, 4, SQL_C_CHAR, d, 20, 0);
										  SQLBindCol(hstmt, 5, SQL_C_CHAR, e, 20, 0);
										  SQLBindCol(hstmt, 6, SQL_C_CHAR, f, 20, 0);
										  SQLBindCol(hstmt, 7, SQL_C_SLONG, &g, 20, 0);
										  
										  do{
											  resultCode = SQLFetch(hstmt);
											  if (resultCode == SQL_NO_DATA)
												  break;
											  if (strcmp(book_name, c) == 0)
												  printf("%s %s %s %s %s %s %d\n", a, b, c, d, e, f, g);
										  } while (true);

										  char temp;
										  printf("输入任意值返回......\n");
										  gets(&temp);
										  system("cls");
										  break; }
							 case '4':{
										  system("cls");
										  printf("请输入作者:");
										  char author[20];
										  gets(author);
										  char a[20];
										  char b[20];
										  char c[20];
										  char d[20];
										  char e[20];
										  char f[20];
										  int g;
										  resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
										  UCHAR sql_3[MAXBUFLEN] = "select * from books";
										  SQLExecDirect(hstmt, sql_3, 128);
										  SQLBindCol(hstmt, 1, SQL_C_CHAR, a, 20, 0);
										  SQLBindCol(hstmt, 2, SQL_C_CHAR, b, 20, 0);
										  SQLBindCol(hstmt, 3, SQL_C_CHAR, c, 20, 0);
										  SQLBindCol(hstmt, 4, SQL_C_CHAR, d, 20, 0);
										  SQLBindCol(hstmt, 5, SQL_C_CHAR, e, 20, 0);
										  SQLBindCol(hstmt, 6, SQL_C_CHAR, f, 20, 0);
										  SQLBindCol(hstmt, 7, SQL_C_SLONG, &g, 20, 0);
										  
										  do{
											  resultCode = SQLFetch(hstmt);
											  if (resultCode == SQL_NO_DATA)
												  break;
											  if (strcmp(author, d) == 0)
												  printf("%s %s %s %s %s %s %d\n", a, b, c, d, e, f, g);
										  } while (true);

										  char temp;
										  printf("输入任意值返回......\n");
										  gets(&temp);
										  system("cls");
										  break; }

							 case '5':{
										  system("cls");
										  printf("请输入出版社:");
										  char publisher[20];
										  gets(publisher);
										  char a[20];
										  char b[20];
										  char c[20];
										  char d[20];
										  char e[20];
										  char f[20];
										  int g;
										  resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
										  UCHAR sql_3[MAXBUFLEN] = "select * from books";
										  SQLExecDirect(hstmt, sql_3, 128);
										  SQLBindCol(hstmt, 1, SQL_C_CHAR, a, 20, 0);
										  SQLBindCol(hstmt, 2, SQL_C_CHAR, b, 20, 0);
										  SQLBindCol(hstmt, 3, SQL_C_CHAR, c, 20, 0);
										  SQLBindCol(hstmt, 4, SQL_C_CHAR, d, 20, 0);
										  SQLBindCol(hstmt, 5, SQL_C_CHAR, e, 20, 0);
										  SQLBindCol(hstmt, 6, SQL_C_CHAR, f, 20, 0);
										  SQLBindCol(hstmt, 7, SQL_C_SLONG, &g, 20, 0);
										
										  do{
											  resultCode = SQLFetch(hstmt);
											  if (resultCode == SQL_NO_DATA)
												  break;
											  if (strcmp(publisher, e) == 0)
												  printf("%s %s %s %s %s %s %d\n", a, b, c, d, e, f, g);
										  } while (true);

										  char temp;
										  printf("输入任意值返回......\n");
										  gets(&temp);
										  system("cls");
										  break; }
							       default:{
											   printf("无此查询方式！");
											   Sleep(1500);																			   
								   }
							 }

							 break;
				}

				case '3':{
							 system("cls");
							 resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							 printf("请输入要修改的图书的编号：");
							 char book_id[20];
							 gets(book_id);
							 char a[20];
							 printf("请输入修改后的图书的书名：");
							 gets(a);
							 char b[20];
							 printf("请输入修改后的图书的作者：");
							 gets(b);
							 char c[20];
							 printf("请输入修改后的图书的出版社：");
							 gets(c);
							 char d[20];
							 printf("请输入修改后的图书的价格：");
							 gets(d);
							
							
							 UCHAR sql_2[MAXBUFLEN] = "update books set book_name = ?,author = ?,publisher = ?,sell_price = ? where book_id = ?;";
							 SQLINTEGER p = SQL_NTS;
							 //1预编译   
							 SQLPrepare(hstmt, sql_2, 128);
							 //2 绑定参数值   
							 SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &a, 0, &p);
							 SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &b, 0, &p);
							 SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &c, 0, &p);
							 SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &d, 0, &p);
							 SQLBindParameter(hstmt, 5, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &book_id, 0, &p);
							 //3 执行  
							 SQLExecute(hstmt);
							 printf("修改成功！");
							 char temp;
							 printf("输入任意值返回......\n");
							 gets(&temp);
							 system("cls");
							 break; }

				case'4':{
							system("cls");
							char a1[5];
							char a2[5];

							char b[20];
							char c[20];
							char d[20];
							char e[20];

							char f[20];
							int g;

							
							
							printf("请输入要进货的图书的编号：");
							gets(a1);
							printf("请输入要进货的图书的进货价：");
							gets(f);
							printf("请输入要进货的图书的购买数量：");
							scanf("%d", &g);


							resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							UCHAR sql_3[MAXBUFLEN] = "select * from books;";
							SQLExecDirect(hstmt, sql_3, 128);
							SQLBindCol(hstmt, 1, SQL_C_CHAR, a2, 20, 0);
							
							do{
								resultCode = SQLFetch(hstmt);

								if (resultCode == SQL_NO_DATA){
									char temp_5;
									gets(&temp_5);
									printf("请输入要进货的图书的ISBN：");
									gets(b);
									printf("请输入要进货的图书的书名：");
									gets(c);
									printf("请输入要进货的图书的作者：");
									gets(d);
									printf("请输入要进货的图书的出版社：");
									gets(e);
									resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
									UCHAR sql_5[MAXBUFLEN] = "insert into buy_book_list values(?,?,?,?,?,?,?,'unpaid');";
									SQLINTEGER p = SQL_NTS;
									//1预编译   
									SQLPrepare(hstmt, sql_5, 128);
									//2 绑定参数值   
									SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &a1, 0, &p);
									SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &b, 0, &p);
									SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &c, 0, &p);
									SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &d, 0, &p);
									SQLBindParameter(hstmt, 5, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &e, 0, &p);
									SQLBindParameter(hstmt, 6, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &f, 0, &p);
									SQLBindParameter(hstmt, 7, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 200, 0, &g, 0, &p);
									SQLExecute(hstmt);

									printf("书籍并不在库中，进货成功！\n");						
									char temp_2;
									printf("输入任意值返回......\n");
									gets(&temp_2);
									system("cls");
									break;
								}
									

								if (strcmp(a1, a2) == 0){
									do{
										resultCode = SQLFetch(hstmt);
										if (resultCode == SQL_NO_DATA) break;
									} while (true);

									resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
									UCHAR sql_6[MAXBUFLEN] = "insert into buy_book_list values(?,NULL,NULL,NULL,NULL,?,?,'unpaid');";
									SQLINTEGER q = SQL_NTS;
									//1预编译   
									SQLPrepare(hstmt, sql_6, 128);
									//2 绑定参数值   
									SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &a1, 0, &q);
									SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &f, 0, &q);
									SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 200, 0, &g, 0, &q);
									SQLExecute(hstmt);
									printf("书籍在库中已有，进货成功！\n");
									char temp_1;
									gets(&temp_1);
									char temp;
									printf("输入任意值返回......\n");
									gets(&temp);
									system("cls");
									break;
								}
									
							} while (true);

							break;
						
				}




				
				


                 
				case '5':{
							system("cls");
							resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							UCHAR sql_5[MAXBUFLEN] = "select book_id, buy_price, buy_num, buy_state from buy_book_list where book_id in (select book_id from books); ";
							char a2[5];
							char f[20];
							int g;
							char h[20];
							SQLExecDirect(hstmt, sql_5, 128);
							SQLBindCol(hstmt, 1, SQL_C_CHAR, a2, 20, 0);
							SQLBindCol(hstmt, 2, SQL_C_CHAR, f, 20, 0);
							SQLBindCol(hstmt, 3, SQL_C_SLONG, &g, 20, 0);
							SQLBindCol(hstmt, 4, SQL_C_CHAR, h, 20, 0);

							do{
								resultCode = SQLFetch(hstmt);
								if (resultCode == SQL_NO_DATA)
									break;
								printf("%s %s %d %s\n", a2, f, g, h);

							} while (true);


							resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							UCHAR sql_6[MAXBUFLEN] = "select book_id,ISBN, book_name,buy_price, buy_num, buy_state from buy_book_list where book_id not in (select book_id from books); ";
							char a1[5];
							char b1[20];
							char c1[20];
							char d1[20];
							int g1;
							char h1[20];
							SQLExecDirect(hstmt, sql_6, 128);
							SQLBindCol(hstmt, 1, SQL_C_CHAR, a1, 20, 0);
							SQLBindCol(hstmt, 2, SQL_C_CHAR, b1, 20, 0);
							SQLBindCol(hstmt, 3, SQL_C_CHAR, c1, 15, 0);
							SQLBindCol(hstmt, 4, SQL_C_CHAR, d1, 15, 0);
							SQLBindCol(hstmt, 5, SQL_C_SLONG, &g1, 20, 0);
							SQLBindCol(hstmt, 6, SQL_C_CHAR, h1, 20, 0);

							do{
								resultCode = SQLFetch(hstmt);
								if (resultCode == SQL_NO_DATA)
									break;
								printf("%s %s %s %s %d %s\n", a1, b1, c1, d1, g1, h1);

							} while (true);

							char a[5];
							printf("请输入要付款的图书的编号：");
							gets(a);
							resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							UCHAR sql_7[MAXBUFLEN] = "update buy_book_list set buy_state = 'paid' where buy_state = 'unpaid' and book_id = ?;";
							SQLINTEGER p = SQL_NTS;
							//1预编译   
							SQLPrepare(hstmt, sql_7, 128);
							//2 绑定参数值   
							SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &a, 0, &p);
							SQLExecute(hstmt);																								
							printf("付款成功！\n");	
							char temp;
							printf("输入任意值返回......\n");
							gets(&temp);
							system("cls");
							break;
							
				}

				case '6':{
							 system("cls");
							 resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							 UCHAR sql_5[MAXBUFLEN] = "select book_id, buy_price, buy_num, buy_state from buy_book_list where book_id in (select book_id from books); ";
							 char a2[5];
							 char f[20];
							 int g;
							 char h[20];
							 SQLExecDirect(hstmt, sql_5, 128);
							 SQLBindCol(hstmt, 1, SQL_C_CHAR, a2, 20, 0);
							 SQLBindCol(hstmt, 2, SQL_C_CHAR, f, 20, 0);
							 SQLBindCol(hstmt, 3, SQL_C_SLONG, &g, 20, 0);
							 SQLBindCol(hstmt, 4, SQL_C_CHAR, h, 20, 0);

							 do{
								 resultCode = SQLFetch(hstmt);
								 if (resultCode == SQL_NO_DATA)
									 break;
								 printf("%s %s %d %s\n", a2, f, g, h);

							 } while (true);


							 resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							 UCHAR sql_6[MAXBUFLEN] = "select book_id,ISBN, book_name,buy_price, buy_num, buy_state from buy_book_list where book_id not in (select book_id from books); ";
							 char a1[5];
							 char b1[20];
							 char c1[20];
							 char d1[20];
							 int g1;
							 char h1[20];
							 SQLExecDirect(hstmt, sql_6, 128);
							 SQLBindCol(hstmt, 1, SQL_C_CHAR, a1, 20, 0);
							 SQLBindCol(hstmt, 2, SQL_C_CHAR, b1, 20, 0);
							 SQLBindCol(hstmt, 3, SQL_C_CHAR, c1, 15, 0);
							 SQLBindCol(hstmt, 4, SQL_C_CHAR, d1, 15, 0);
							 SQLBindCol(hstmt, 5, SQL_C_SLONG, &g1, 20, 0);
							 SQLBindCol(hstmt, 6, SQL_C_CHAR, h1, 20, 0);

							 do{
								 resultCode = SQLFetch(hstmt);
								 if (resultCode == SQL_NO_DATA)
									 break;
								 printf("%s %s %s %s %d %s\n", a1, b1, c1, d1, g1, h1);

							 } while (true);


							 char a[5];
							 printf("请输入要退货的图书的编号：");
							 gets(a);
							 resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							 UCHAR sql_7[MAXBUFLEN] = "update buy_book_list set buy_state = 'returned' where buy_state = 'unpaid' and book_id = ?;";
							 SQLINTEGER p = SQL_NTS;
							 //1预编译   
							 SQLPrepare(hstmt, sql_7, 128);
							 //2 绑定参数值   
							 SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &a, 0, &p);
							 SQLExecute(hstmt);
							 
							 printf("退货成功！\n");
							 char temp;
							 printf("输入任意值返回......\n");
							 gets(&temp);
							 system("cls");
							 break;


				}

				case '7': {
							  system("cls");
							  resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							  UCHAR sql_5[MAXBUFLEN] = "select book_id, buy_price, buy_num, buy_state from buy_book_list where book_id in (select book_id from books); ";
							  char a2[5];
							  char f2[20];
							  int g2;
							  char h[20];
							  SQLExecDirect(hstmt, sql_5, 128);
							  SQLBindCol(hstmt, 1, SQL_C_CHAR, a2, 20, 0);
							  SQLBindCol(hstmt, 2, SQL_C_CHAR, f2, 20, 0);
							  SQLBindCol(hstmt, 3, SQL_C_SLONG, &g2, 20, 0);
							  SQLBindCol(hstmt, 4, SQL_C_CHAR, h, 20, 0);

							  do{
								  resultCode = SQLFetch(hstmt);
								  if (resultCode == SQL_NO_DATA)
									  break;
								  printf("%s %s %d %s\n", a2, f2, g2, h);

							  } while (true);


							  resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							  UCHAR sql_6[MAXBUFLEN] = "select book_id,ISBN, book_name,buy_price, buy_num, buy_state from buy_book_list where book_id not in (select book_id from books); ";
							  char a1[5];
							  char b1[20];
							  char c1[20];
							  char d1[20];
							  int g1;
							  char h1[20];
							  SQLExecDirect(hstmt, sql_6, 128);
							  SQLBindCol(hstmt, 1, SQL_C_CHAR, a1, 20, 0);
							  SQLBindCol(hstmt, 2, SQL_C_CHAR, b1, 20, 0);
							  SQLBindCol(hstmt, 3, SQL_C_CHAR, c1, 15, 0);
							  SQLBindCol(hstmt, 4, SQL_C_CHAR, d1, 15, 0);
							  SQLBindCol(hstmt, 5, SQL_C_SLONG, &g1, 20, 0);
							  SQLBindCol(hstmt, 6, SQL_C_CHAR, h1, 20, 0);

							  do{
								  resultCode = SQLFetch(hstmt);
								  if (resultCode == SQL_NO_DATA)
									  break;
								  printf("%s %s %s %s %d %s\n", a1, b1, c1, d1, g1, h1);

							  } while (true);




							 resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							 UCHAR sql_15[MAXBUFLEN] = "select * from books;";
							 printf("请输入要添加的书的编号：");
							 char book_id[5];
							 gets(book_id);

							 char a[5];
							 char b[20];
							 char c[20];
							 char d[20];
							 char e[20];
							 char f[20];
							 int g;													
							 SQLExecDirect(hstmt, sql_15, 128);
							 SQLBindCol(hstmt, 1, SQL_C_CHAR, a, 20, 0);
							 SQLBindCol(hstmt, 2, SQL_C_CHAR, b, 20, 0);
							 SQLBindCol(hstmt, 3, SQL_C_CHAR, c, 20, 0);
							 SQLBindCol(hstmt, 4, SQL_C_CHAR, d, 20, 0);
							 SQLBindCol(hstmt, 5, SQL_C_CHAR, e, 20, 0);
							 SQLBindCol(hstmt, 6, SQL_C_CHAR, f, 20, 0);
							 SQLBindCol(hstmt, 7, SQL_C_SLONG, &g, 20, 0);

							 do{
								 resultCode = SQLFetch(hstmt);
								 if (resultCode == SQL_NO_DATA){
									 printf("要添加的书在库中不存在!\n");									 
									 char b2[20];
									 char c2[20];
									 char d2[20];
									 char e2[20];
									 char f2[20];
									 int g2;
									 printf("请输入要添加的书的ISBN：");
									 gets(b2);
									 printf("请输入要添加的书的书名：");
									 gets(c2);
									 printf("请输入要添加的书的作者：");
									 gets(d2);
									 printf("请输入要添加的书的出版社：");
									 gets(e2);
									 printf("请输入要添加的书的零售价：");
									 gets(f2);
									 printf("请输入要添加的书的库存：");
									 scanf("%d", &g2);
									 char temp;
									 gets(&temp);

									 resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
									 UCHAR sql_17[MAXBUFLEN] = "insert into books values(?,?,?,?,?,?,?);";
									 SQLINTEGER p = SQL_NTS;
									 //1预编译   
									 SQLPrepare(hstmt, sql_17, 128);
									 //2 绑定参数值   
									 SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &book_id, 0, &p);
									 SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &b2, 0, &p);
									 SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &c2, 0, &p);
									 SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &d2, 0, &p);
									 SQLBindParameter(hstmt, 5, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &e2, 0, &p);
									 SQLBindParameter(hstmt, 6, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &f2, 0, &p);
									 SQLBindParameter(hstmt, 7, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 200, 0, &g2, 0, &p);
									 SQLExecute(hstmt);

									 printf("添加成功！\n");
									 break;
									 }

								 if (strcmp(book_id, a) == 0){
									 printf("要添加的书在库中已存在，请输入需增加的库存量：");
									 int z;
									 scanf("%d",&z);
									 char temp;
									 gets(&temp);
									 do{
										 resultCode = SQLFetch(hstmt);
										 if (resultCode == SQL_NO_DATA) break;
									 } while (true);

									 resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
									 UCHAR sql_15[MAXBUFLEN] = "update books set store_num = store_num + ? where book_id = ?;";
									 SQLINTEGER p = SQL_NTS;
									 //1预编译   
									 SQLPrepare(hstmt, sql_15, 128);
									 //2 绑定参数值   
									 SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 200, 0, &z, 0, &p);
									 SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &book_id, 0, &p);
									 SQLExecute(hstmt);
									 printf("添加成功！\n");
									 break;
								 }

							 } while (true);
								 
							 char temp;
							 printf("输入任意值返回......\n");
							 gets(&temp);
							 system("cls");
							 break;

				
				}

				case '8': {
							  system("cls");
							  resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							  UCHAR sql_15[MAXBUFLEN] = "update books set store_num = store_num - ? where book_id = ?;";
							  printf("请输入被购买的书的编号：");
							  char book_id[5];
							  gets(book_id);
							  printf("请输入被购买的书的数量：");
							  int g;
							  scanf("%d", &g);
							  char temp;
							  gets(&temp);

							  SQLINTEGER p = SQL_NTS;
							  //1预编译   
							  SQLPrepare(hstmt, sql_15, 128);
							  //2 绑定参数值   
							  SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 200, 0, &g, 0, &p);
							  SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &book_id, 0, &p);
							  SQLExecute(hstmt);
							  printf("购买成功！\n");
							  char temp_1;
							  printf("输入任意值返回......\n");
							  gets(&temp_1);
							  system("cls");
							  break;
				}


				case '9':{    
							 system("cls");
							 resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							 UCHAR sql_8[MAXBUFLEN] = "insert into money_table values(?,?,?,?);";
							 char in_or_out[5];
							 char money_num[5];
							 char date[10];
							 printf("请输入交易方式（收入为in，支出为out):");
							 gets(in_or_out);
							 printf("请输入交易金额:");
							 gets(money_num);
							 printf("请输入交易日期:");
							 gets(date);
							 
							 //1预编译   
							 SQLINTEGER p = SQL_NTS;

							 SQLPrepare(hstmt, sql_8, 128);
							 //2 绑定参数值   
							 
							 SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 200, 0, &bill, 0, &p);
							 SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, in_or_out, 0, &p);
							 SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, money_num, 0, &p);
							 SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, date, 0, &p);
							 SQLExecute(hstmt);

							 bill++;
							 char temp_9;
							 printf("输入任意值返回......\n");
							 gets(&temp_9);
							 system("cls"); break;
}


				case 'a':{
							system("cls");
							resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							UCHAR sql_15[MAXBUFLEN] = "select * from money_table where event_date between ? and ? ;";
						
							char b[20];
							char c[20];
							
							int bill_id;
							char in_or_out[5];
							char money_num[5];
							DATE_STRUCT event_time;

							printf("请输入要查询的起始日期：");
							gets(b);
							printf("请输入要查询的终止日期：");
							gets(c);

							SQLINTEGER p = SQL_NTS;
							//1预编译   
							SQLPrepare(hstmt, sql_15, 128);
							//2 绑定参数值   
							SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &b, 0, &p);
							SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &c, 0, &p);
							SQLExecute(hstmt);
							

							SQLBindCol(hstmt, 1, SQL_C_SLONG, &bill_id, 20, 0);
							SQLBindCol(hstmt, 2, SQL_C_CHAR, in_or_out, 20, 0);
							SQLBindCol(hstmt, 3, SQL_C_CHAR, money_num, 20, 0);
							SQLBindCol(hstmt, 4, SQL_C_TYPE_DATE, &event_time, 20, 0);
							
							do{
								resultCode = SQLFetch(hstmt);
								if (resultCode == SQL_NO_DATA)
									break;

								printf("%d %s %s %d-%d-%d\n", bill_id, in_or_out, money_num, event_time.year, event_time.month, event_time.day);

							} while (true);

							char temp;
							printf("输入任意值返回......\n");
							gets(&temp);
							system("cls");
							break;

				}

				case 'q': {flag = 1; break; };

				default:{
					printf("请按提示重新输入！！");
					Sleep(1500);
					system("cls"); }
				}
				
				if (flag == 1)  break;
			}

			//关闭游标，释放语句句柄   
			SQLCloseCursor(hstmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
			/*断开数据库连接
			*1. 断开数据库连接
			*2.释放连接句柄.
			*3.释放环境句柄(如果不再需要在这个环境中作更多连接)
			*/
			SQLDisconnect(hdbc);
			SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
			SQLFreeHandle(SQL_HANDLE_ENV, henv);
			return;
		


	}

	
