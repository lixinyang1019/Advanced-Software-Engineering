
/*************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                 */
/*                                                                                               */
/* FILE NAME               :  menu.h                                                             */
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
 * Created by JiDan, 2014/09/12
 *
 */

#include "linktable.h"

typedef struct DataNode
{
	tLinkTableNode * pNext;
	char   cmd[100];
	char   desc[100];
	int    (*handler)();
} tDataNode;

/* FindCmd */
tDataNode* FindCmd(tLinkTable * head, char * cmd);

/* show all Cmd */
int ShowAllCmd(tLinkTable * head);

/* start Cmd */
tLinkTable * StartMenu();

/* add Cmd */
int AddMenuNode(tLinkTable * head, tDataNode * pNode);

/* del Cmd */
int DelMenuNode(tLinkTable * head, char * cmd);


