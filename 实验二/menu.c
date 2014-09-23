
/*************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                 */
/*                                                                                               */
/* FILE NAME               :  menu.c                                                             */
/* PRINCIPAL AUTHOR        :  JiDan                                                              */
/* SUBSYSTEM NAME          :  menu                                                               */
/* MODULE NAME             :  menu                                                               */
/* LANGUAGE                :  C                                                                  */
/* TARGET ENVIRONMENT      :  ANY                                                                */
/* DATE OF FIRST RELEASE   :  2014/09/22                                                         */
/* DESCRIPTION             :  menu for menu program                                              */
/*************************************************************************************************/

/*
 * Revision log;
 * Created by JiDan, 2014/09/22
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"
#include "menu.h"

#define CMD_MAX_LEN  128
#define DESC_LEN     1024
#define CMD_NUM      10

int ShowAllCmd(tLinkTable * head)
{
	tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
	while(pNode != NULL)
	{
		printf("%s - %s\n", pNode->cmd, pNode->desc);
		pNode = (tDataNode*)GetNextLinkTableNode(head, (tLinkTableNode *)pNode);
	}
	return 0;
}

tDataNode* FindCmd(tLinkTable * head, char * cmd)
{
	tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
	while(pNode != NULL)
	{
		if(!strcmp(pNode->cmd, cmd))
		{
			return pNode;
		}
		pNode = (tDataNode*)GetNextLinkTableNode(head, (tLinkTableNode *)pNode);
	}
	return NULL;
}

tLinkTable * StartMenu()
{
	return CreateLinkTable();
}

int AddMenuNode(tLinkTable * head, tDataNode * pNode)
{
	AddLinkTableNode(head, (tLinkTableNode *)pNode);
	return 1;
}

int DelMenuNode(tLinkTable * head, char * cmd)
{
	tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
	while(pNode != NULL)
	{
		if(!strcmp(pNode->cmd, cmd))
		{
			DelLinkTableNode(head, (tLinkTableNode *)pNode);
			return 1;
		}
		pNode = (tDataNode*)GetNextLinkTableNode(head, (tLinkTableNode *)pNode);
	}
	return 0;
}

