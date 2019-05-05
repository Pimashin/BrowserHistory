//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PimashinE.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "windows.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma link "VirtualTrees"
#pragma link "VirtualTrees"
#pragma link "VirtualTrees"
#pragma link "VirtualTrees"
#pragma link "VirtualTrees"
#pragma link "VirtualTrees"
#pragma link "VirtualTrees"
#pragma link "VirtualTrees"
#pragma resource "*.dfm"
#include <iostream>
#include "sqlite3.h"
#include <stdlib.h>
#include <stdio.h>


TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
VirtualStringTree1 -> NodeDataSize = sizeof(BrowserHistory);

}


void __fastcall TForm1::Button1Click(TObject *Sender)
{

 using namespace std;
	const char *db_name="History";
	VirtualStringTree1 -> Clear();
	sqlite3_stmt *stmt;
	sqlite3* db;
	char* sql ="select * from urls";
	int r = sqlite3_open(db_name ,&db);
	if (r!=SQLITE_OK) {
	Edit1->Visible=1;
	Edit1->Text = String("Error!")+sqlite3_errmsg(db);
	}

	sqlite3_prepare_v2( db,sql, -1, &stmt, NULL);

    while (sqlite3_step(stmt) == SQLITE_ROW)
	{
		PVirtualNode entryNode = VirtualStringTree1 -> AddChild(VirtualStringTree1 -> RootNode);
		BrowserHistory *nodeData = (BrowserHistory*)VirtualStringTree1 -> GetNodeData(entryNode);
		nodeData -> id = sqlite3_column_int(stmt, 0) ;
		nodeData -> url   = (char*)sqlite3_column_text(stmt,1);

	}
	sqlite3_finalize(stmt);
	sqlite3_close(db);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
		 PVirtualNode selectedNode = VirtualStringTree1 -> FocusedNode;
	int selectedNodeIndex = selectedNode -> Index;
	BrowserHistory *Data = (BrowserHistory*)VirtualStringTree1->GetNodeData(selectedNode);
	UnicodeString id = Data->id;
	sqlite3_stmt *stmt;
	const char *db_name="History";
	sqlite3* db;
	int r = sqlite3_open(db_name ,&db);
   String sql = String("DELETE from urls where id="+id);
   wchar_t *sql1 = sql.c_str();
	sqlite3_prepare16_v2( db,sql1, -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	sqlite3_close(db);
	VirtualStringTree1 -> DeleteNode(selectedNode);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 	sqlite3_stmt *stmt;
	const char *db_name="History";
	sqlite3* db;
	int r = sqlite3_open(db_name ,&db);
   char *sql = "DELETE from urls";
	sqlite3_prepare_v2( db,sql, -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	sqlite3_close(db);
	VirtualStringTree1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  VirtualStringTree1 -> NodeDataSize = sizeof(BrowserHistory);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)

{

if (!Node) return;
	 BrowserHistory *nodeData = (BrowserHistory *)Sender -> GetNodeData(Node);
	switch (Column)
		{
		   case 0: CellText = nodeData -> id;break;
		   case 1: CellText =  nodeData -> url; break;
		}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::VirtualStringTree1NodeClick(TBaseVirtualTree *Sender, const THitInfo &HitInfo)

{

PVirtualNode selectedNode = VirtualStringTree1->FocusedNode;
}
//---------------------------------------------------------------------------
