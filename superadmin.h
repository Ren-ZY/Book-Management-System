#define _CRT_SECURE_NO_WARNINGS
#define MAXBUFLEN 255

#include <stdio.h>   
#include <string.h>   
#include <windows.h>    //��ͷ�ļ��ؼ�
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

void Administer()/* ��ʾ����Ա����ϵͳѡ����� */
{
	int flag = 0;
	char id[20];
	char password[20];


	printf("�����볬������Ա�˺�: ");
	gets(id);
	printf("�����볬������Ա����: ");
	gets(password);

	RETCODE resultCode;
	//Ԥ����SQL���

	
	
	

	//����������䣬ʹ��SQLDriverConnect��ʽ��������Դ��127.0.0.1ָ������UID��PWD�ֱ�Ϊ�û��������롣
	SQLCHAR ConnStrIn[MAXBUFLEN] =
		"DRIVER={SQL Server}; SERVER=DESKTOP-4J9BPKN\\SQL2008;UID=ren; PWD=ren791350;Trusted_Connection=yes;DATABASE=sellmanage; ";

	//���价����� ��������ʧ�����ӡ������Ϣ
	resultCode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
	//���û������
	resultCode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	//2.���Ӿ��  
	resultCode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
	resultCode = SQLDriverConnect(hdbc, NULL, ConnStrIn, SQL_NTS, NULL, NULL, NULL, SQL_DRIVER_NOPROMPT);
	//�ж������Ƿ�ɹ�  
	if ((resultCode != SQL_SUCCESS) && (resultCode != SQL_SUCCESS_WITH_INFO))
	{
		printf("failed to connect\n");  Sleep(1500); exit(0);
	}

		resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
		//��һ�ַ�ʽ:ֱ��ִ�� 
		UCHAR sql_0[MAXBUFLEN] = "select * from superadmin";
		SQLExecDirect(hstmt, sql_0, 128); //������������ֵ����С�ڱ�ִ��sql���ĳ���

		char list1[20];
		char list2[20];
		SQLINTEGER name_length, pwd_length;
		SQLBindCol(hstmt, 1, SQL_C_CHAR, list1, 20, 0);
		SQLBindCol(hstmt, 2, SQL_C_CHAR, list2, 20, 0);
		resultCode = SQLFetch(hstmt);
		if (strcmp(id, list1) != 0 || strcmp(password, list2) != 0){
			printf("�˺Ż��������\n"); Sleep(1500);  system("cls");   main();
		}
		
		resultCode = SQLFetch(hstmt);
		system("cls");

			while (1)
			{

				printf("\n\n\n");
				printf("************************************************************************************\n\n");
				printf("������������������������������������ѡ�������Ŀ������������������������������������\n");
				printf("����������  0 = ����û�                                                    ��������\n");
				printf("����������  1 = �鿴�����û�����                                            ��������\n");
				printf("����������  2 = �鼮��ѯ                                                    ��������\n");
				printf("����������  3 = ͼ����Ϣ�޸�                                                ��������\n");
				printf("����������  4 = ͼ�����                                                    ��������\n");
				printf("����������  5 = ��������                                                    ��������\n");				
				printf("����������  6 = ͼ���˻�                                                    ��������\n");
				printf("����������  7 = �������                                                    ��������\n");
				printf("����������  8 = �鼮����                                                    ��������\n");
				printf("����������  9 = �������                                                    ��������\n");
				printf("����������  a = �鿴�˵�                                                    ��������\n");
				printf("����������  q = �˳�ϵͳ                                                    ��������\n");
				printf("������������������������������������������������������������������������������������\n\n");
				printf("************************************************************************************\n\n");
				printf("��ѡ��?\n");
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

						
							 printf("������������û����˺ţ�");
							 gets(a);
							 printf("������������û������룺");
							 scanf("%s", b);
							 char temp;
							 gets(&temp);
							 printf("������������û�����ʵ������");
							 gets(c);
							 printf("������������û��Ĺ��ţ�");
							 gets(d);
							 printf("������������û����Ա�");
							 gets(e);
							 printf("������������û������䣺");
							 gets(f);
			                 
							 md5(b);

							 UCHAR sql_1[MAXBUFLEN] = "insert into usr values(?,?,?,?,?,?);";
							 SQLINTEGER p = SQL_NTS;
							 //1Ԥ����   
							 SQLPrepare(hstmt, sql_1, 128);
							 //2 �󶨲���ֵ   
							 SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &a, 0, &p);
							 SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &md, 0, &p);
							 SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &c, 0, &p);
							 SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &d, 0, &p);
							 SQLBindParameter(hstmt, 5, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &e, 0, &p);
							 SQLBindParameter(hstmt, 6, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &f, 0, &p);
							 //3 ִ��  
							 SQLExecute(hstmt);

							 printf("��ӳɹ���");
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
							 printf("��������ֵ����......\n");
							 gets(&temp);
							 system("cls");
							 break; }

				case '2':{    
							 system("cls");
							 printf("�������ѯ��ʽ\n1=book_id\n2=ISBN\n3=book_name\n4=author\n5=publisher\n");
							 char choice_3;
							 gets(&choice_3);

							 switch (choice_3){
							 case '1':{
										  system("cls");
										  printf("�������鼮���:");
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
										  printf("��������ֵ����......\n");
										  gets(&temp);
										  system("cls");
										  break; }
							 case '2':{
										  system("cls");
										  printf("������ISBN:");
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
										  printf("��������ֵ����......\n");
										  gets(&temp);
										  system("cls");
										  break; }
							 case '3':{
										  system("cls");
										  printf("����������:");
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
										  printf("��������ֵ����......\n");
										  gets(&temp);
										  system("cls");
										  break; }
							 case '4':{
										  system("cls");
										  printf("����������:");
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
										  printf("��������ֵ����......\n");
										  gets(&temp);
										  system("cls");
										  break; }

							 case '5':{
										  system("cls");
										  printf("�����������:");
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
										  printf("��������ֵ����......\n");
										  gets(&temp);
										  system("cls");
										  break; }
							       default:{
											   printf("�޴˲�ѯ��ʽ��");
											   Sleep(1500);																			   
								   }
							 }

							 break;
				}

				case '3':{
							 system("cls");
							 resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							 printf("������Ҫ�޸ĵ�ͼ��ı�ţ�");
							 char book_id[20];
							 gets(book_id);
							 char a[20];
							 printf("�������޸ĺ��ͼ���������");
							 gets(a);
							 char b[20];
							 printf("�������޸ĺ��ͼ������ߣ�");
							 gets(b);
							 char c[20];
							 printf("�������޸ĺ��ͼ��ĳ����磺");
							 gets(c);
							 char d[20];
							 printf("�������޸ĺ��ͼ��ļ۸�");
							 gets(d);
							
							
							 UCHAR sql_2[MAXBUFLEN] = "update books set book_name = ?,author = ?,publisher = ?,sell_price = ? where book_id = ?;";
							 SQLINTEGER p = SQL_NTS;
							 //1Ԥ����   
							 SQLPrepare(hstmt, sql_2, 128);
							 //2 �󶨲���ֵ   
							 SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &a, 0, &p);
							 SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &b, 0, &p);
							 SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &c, 0, &p);
							 SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &d, 0, &p);
							 SQLBindParameter(hstmt, 5, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &book_id, 0, &p);
							 //3 ִ��  
							 SQLExecute(hstmt);
							 printf("�޸ĳɹ���");
							 char temp;
							 printf("��������ֵ����......\n");
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

							
							
							printf("������Ҫ������ͼ��ı�ţ�");
							gets(a1);
							printf("������Ҫ������ͼ��Ľ����ۣ�");
							gets(f);
							printf("������Ҫ������ͼ��Ĺ���������");
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
									printf("������Ҫ������ͼ���ISBN��");
									gets(b);
									printf("������Ҫ������ͼ���������");
									gets(c);
									printf("������Ҫ������ͼ������ߣ�");
									gets(d);
									printf("������Ҫ������ͼ��ĳ����磺");
									gets(e);
									resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
									UCHAR sql_5[MAXBUFLEN] = "insert into buy_book_list values(?,?,?,?,?,?,?,'unpaid');";
									SQLINTEGER p = SQL_NTS;
									//1Ԥ����   
									SQLPrepare(hstmt, sql_5, 128);
									//2 �󶨲���ֵ   
									SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &a1, 0, &p);
									SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &b, 0, &p);
									SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &c, 0, &p);
									SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &d, 0, &p);
									SQLBindParameter(hstmt, 5, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &e, 0, &p);
									SQLBindParameter(hstmt, 6, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &f, 0, &p);
									SQLBindParameter(hstmt, 7, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 200, 0, &g, 0, &p);
									SQLExecute(hstmt);

									printf("�鼮�����ڿ��У������ɹ���\n");						
									char temp_2;
									printf("��������ֵ����......\n");
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
									//1Ԥ����   
									SQLPrepare(hstmt, sql_6, 128);
									//2 �󶨲���ֵ   
									SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &a1, 0, &q);
									SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &f, 0, &q);
									SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 200, 0, &g, 0, &q);
									SQLExecute(hstmt);
									printf("�鼮�ڿ������У������ɹ���\n");
									char temp_1;
									gets(&temp_1);
									char temp;
									printf("��������ֵ����......\n");
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
							printf("������Ҫ�����ͼ��ı�ţ�");
							gets(a);
							resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							UCHAR sql_7[MAXBUFLEN] = "update buy_book_list set buy_state = 'paid' where buy_state = 'unpaid' and book_id = ?;";
							SQLINTEGER p = SQL_NTS;
							//1Ԥ����   
							SQLPrepare(hstmt, sql_7, 128);
							//2 �󶨲���ֵ   
							SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &a, 0, &p);
							SQLExecute(hstmt);																								
							printf("����ɹ���\n");	
							char temp;
							printf("��������ֵ����......\n");
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
							 printf("������Ҫ�˻���ͼ��ı�ţ�");
							 gets(a);
							 resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							 UCHAR sql_7[MAXBUFLEN] = "update buy_book_list set buy_state = 'returned' where buy_state = 'unpaid' and book_id = ?;";
							 SQLINTEGER p = SQL_NTS;
							 //1Ԥ����   
							 SQLPrepare(hstmt, sql_7, 128);
							 //2 �󶨲���ֵ   
							 SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &a, 0, &p);
							 SQLExecute(hstmt);
							 
							 printf("�˻��ɹ���\n");
							 char temp;
							 printf("��������ֵ����......\n");
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
							 printf("������Ҫ��ӵ���ı�ţ�");
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
									 printf("Ҫ��ӵ����ڿ��в�����!\n");									 
									 char b2[20];
									 char c2[20];
									 char d2[20];
									 char e2[20];
									 char f2[20];
									 int g2;
									 printf("������Ҫ��ӵ����ISBN��");
									 gets(b2);
									 printf("������Ҫ��ӵ����������");
									 gets(c2);
									 printf("������Ҫ��ӵ�������ߣ�");
									 gets(d2);
									 printf("������Ҫ��ӵ���ĳ����磺");
									 gets(e2);
									 printf("������Ҫ��ӵ�������ۼۣ�");
									 gets(f2);
									 printf("������Ҫ��ӵ���Ŀ�棺");
									 scanf("%d", &g2);
									 char temp;
									 gets(&temp);

									 resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
									 UCHAR sql_17[MAXBUFLEN] = "insert into books values(?,?,?,?,?,?,?);";
									 SQLINTEGER p = SQL_NTS;
									 //1Ԥ����   
									 SQLPrepare(hstmt, sql_17, 128);
									 //2 �󶨲���ֵ   
									 SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &book_id, 0, &p);
									 SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &b2, 0, &p);
									 SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &c2, 0, &p);
									 SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &d2, 0, &p);
									 SQLBindParameter(hstmt, 5, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &e2, 0, &p);
									 SQLBindParameter(hstmt, 6, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &f2, 0, &p);
									 SQLBindParameter(hstmt, 7, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 200, 0, &g2, 0, &p);
									 SQLExecute(hstmt);

									 printf("��ӳɹ���\n");
									 break;
									 }

								 if (strcmp(book_id, a) == 0){
									 printf("Ҫ��ӵ����ڿ����Ѵ��ڣ������������ӵĿ������");
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
									 //1Ԥ����   
									 SQLPrepare(hstmt, sql_15, 128);
									 //2 �󶨲���ֵ   
									 SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 200, 0, &z, 0, &p);
									 SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &book_id, 0, &p);
									 SQLExecute(hstmt);
									 printf("��ӳɹ���\n");
									 break;
								 }

							 } while (true);
								 
							 char temp;
							 printf("��������ֵ����......\n");
							 gets(&temp);
							 system("cls");
							 break;

				
				}

				case '8': {
							  system("cls");
							  resultCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
							  UCHAR sql_15[MAXBUFLEN] = "update books set store_num = store_num - ? where book_id = ?;";
							  printf("�����뱻�������ı�ţ�");
							  char book_id[5];
							  gets(book_id);
							  printf("�����뱻��������������");
							  int g;
							  scanf("%d", &g);
							  char temp;
							  gets(&temp);

							  SQLINTEGER p = SQL_NTS;
							  //1Ԥ����   
							  SQLPrepare(hstmt, sql_15, 128);
							  //2 �󶨲���ֵ   
							  SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 200, 0, &g, 0, &p);
							  SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &book_id, 0, &p);
							  SQLExecute(hstmt);
							  printf("����ɹ���\n");
							  char temp_1;
							  printf("��������ֵ����......\n");
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
							 printf("�����뽻�׷�ʽ������Ϊin��֧��Ϊout):");
							 gets(in_or_out);
							 printf("�����뽻�׽��:");
							 gets(money_num);
							 printf("�����뽻������:");
							 gets(date);
							 
							 //1Ԥ����   
							 SQLINTEGER p = SQL_NTS;

							 SQLPrepare(hstmt, sql_8, 128);
							 //2 �󶨲���ֵ   
							 
							 SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 200, 0, &bill, 0, &p);
							 SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, in_or_out, 0, &p);
							 SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, money_num, 0, &p);
							 SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, date, 0, &p);
							 SQLExecute(hstmt);

							 bill++;
							 char temp_9;
							 printf("��������ֵ����......\n");
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

							printf("������Ҫ��ѯ����ʼ���ڣ�");
							gets(b);
							printf("������Ҫ��ѯ����ֹ���ڣ�");
							gets(c);

							SQLINTEGER p = SQL_NTS;
							//1Ԥ����   
							SQLPrepare(hstmt, sql_15, 128);
							//2 �󶨲���ֵ   
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
							printf("��������ֵ����......\n");
							gets(&temp);
							system("cls");
							break;

				}

				case 'q': {flag = 1; break; };

				default:{
					printf("�밴��ʾ�������룡��");
					Sleep(1500);
					system("cls"); }
				}
				
				if (flag == 1)  break;
			}

			//�ر��α꣬�ͷ������   
			SQLCloseCursor(hstmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
			/*�Ͽ����ݿ�����
			*1. �Ͽ����ݿ�����
			*2.�ͷ����Ӿ��.
			*3.�ͷŻ������(���������Ҫ���������������������)
			*/
			SQLDisconnect(hdbc);
			SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
			SQLFreeHandle(SQL_HANDLE_ENV, henv);
			return;
		


	}

	
