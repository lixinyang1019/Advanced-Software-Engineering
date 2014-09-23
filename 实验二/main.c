
/*************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                 */
/*                                                                                               */
/* FILE NAME               :  main.c                                                             */
/* PRINCIPAL AUTHOR        :  JiDan                                                              */
/* SUBSYSTEM NAME          :  menu                                                               */
/* MODULE NAME             :  menu                                                               */
/* LANGUAGE                :  C                                                                  */
/* TARGET ENVIRONMENT      :  ANY                                                                */
/* DATE OF FIRST RELEASE   :  2014/09/22                                                         */
/* DESCRIPTION             :  main for menu program                                              */
/*************************************************************************************************/

/*
 * Revision log;
 * Created by JiDan, 2014/09/22
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "linktable.h"

#define CMD_MAX_LEN  128
#define DESC_LEN     1024
#define CMD_NUM      10

int  Help();
int  Quit();
int  Add(tLinkTable * head);
int  Use(tLinkTable * head);
int  Del(tLinkTable * head);

static tDataNode data[] =
{
	{NULL, "help", "this is help cmd!", Help},
	{NULL, "quit", "exit this program", Quit}
};


tLinkTable * head = NULL;

main()
{
	int num = 0;
	head = (tLinkTable *) StartMenu(head);
	if(head != NULL)
	{
		printf("\nmenu create success\n");
	}
	AddMenuNode(head,&data[0]);
	AddMenuNode(head,&data[1]);
	printf("Menu successful initialization\n");
	printf("cmd list:\n");
	ShowAllCmd(head);
	while(1)
	{
		printf("\ninput 1 : add menu\n");
		printf("input 2 : del menu\n");
		printf("input 3 : use menu\n");
		printf("input 4 : show menu\n");
		printf("input :");
		scanf("%d", &num);
		switch(num)
		{
			
			case 1:
			Add(head);
			break;
			
			case 2:
			Del(head);
			break;

			case 3:
			Use(head);
			break;
			
			case 4:
			ShowAllCmd(head);
			break;
	
			default:
			printf("wrong input\n");
			break;
		}
	}
}

int Help()
{
	ShowAllCmd(head);
	return 0;
}

int Quit()
{
	exit(0);
	return 0;
}

int Add(tLinkTable * head)
{
	int i;
	char  t1[100];
	char  t2[100];
	tDataNode *p = (tDataNode *)malloc(sizeof(tDataNode));
	printf("input cmd\n");
	scanf("%s", t1);
	strcpy(p->cmd, t1);
	printf("input description\n");
	scanf("%s", t2);
	strcpy(p->desc, t2);
	i = AddMenuNode(head, p);
	if(i == 1)
	{
		printf("add success\n");
	}
}

int Use(tLinkTable * head)
{
	char cmd[CMD_MAX_LEN];
	printf("Input a cmd >");
	scanf("%s", cmd);
	tDataNode *p = FindCmd(head, cmd);
	if(p == NULL)
	{	
		printf("This is a wrong cmd!\n");
	}
	printf("%s - %s\n", p->cmd, p->desc);
	if(p->handler != NULL)
	{
		p->handler();
	}
}

int Del(tLinkTable * head)
{
	int i;
	char cmd[CMD_MAX_LEN];
	printf("Input a cmd >");
	scanf("%s", cmd);
	i = DelMenuNode(head, cmd);
	if(i == 1)
	{
		printf("delete success\n");
	}
	else
	{
		printf("delete fail\n");
	}
}







