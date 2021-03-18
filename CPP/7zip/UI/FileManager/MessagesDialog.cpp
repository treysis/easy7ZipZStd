// MessagesDialog.cpp
 
#include "StdAfx.h"

#include "../../../Common/IntToString.h"

#include "../../../Windows/ResourceString.h"

#include "MessagesDialog.h"

#include "LangUtils.h"

#include "ProgressDialog2Res.h"

using namespace NWindows;

void CMessagesDialog::AddMessageDirect(LPCWSTR message)
{
  int i = _messageList.GetItemCount();
  wchar_t sz[16];
  ConvertUInt32ToString((UInt32)i, sz);
  _messageList.InsertItem(i, sz);
  _messageList.SetSubItem(i, 1, message);
}

void CMessagesDialog::AddMessage(LPCWSTR message)
{
  UString s = message;
  while (!s.IsEmpty())
  {
    int pos = s.Find(L'\n');
    if (pos < 0)
      break;
    AddMessageDirect(s.Left(pos));
    s.DeleteFrontal(pos + 1);
  }
  AddMessageDirect(s);
}

bool CMessagesDialog::OnInit()
{
  #ifdef LANG
  LangSetWindowText(*this, IDD_MESSAGES);
  LangSetDlgItems(*this, NULL, 0);
  SetItemText(IDOK, LangString(IDS_CLOSE));
  #endif
  _messageList.Attach(GetItem(IDL_MESSAGE));
  _messageList.SetUnicodeFormat();

  _messageList.InsertColumn(0, L"", 30);
  _messageList.InsertColumn(1, LangString(IDS_MESSAGE), 600);

  FOR_VECTOR (i, *Messages)
    AddMessage((*Messages)[i]);

  _messageList.SetColumnWidthAuto(0);
  _messageList.SetColumnWidthAuto(1);

  RECT rc;
  GetWindowRect(&rc);
  m_sizeMinWindow.cx = (RECT_SIZE_X(rc))*3/4;
  m_sizeMinWindow.cy = (RECT_SIZE_Y(rc))*3/4;

  NormalizeSize();
  return CModalDialog::OnInit();
}

bool CMessagesDialog::OnSize(WPARAM /* wParam */, int xSize, int ySize)
{
  int mx, my;
  GetMargins(8, mx, my);
  int bx, by;
  GetItemSizes(IDOK, bx, by);
  int y = ySize - my - by;
  int x = xSize - mx - bx;

  MoveItem(IDOK, x, y, bx, by, false);
  _messageList.Move(mx, my, xSize - mx * 2, y - my * 2, false);
  InvalidateRect(NULL);
  return false;
}

bool CMessagesDialog::OnMessage(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_GETMINMAXINFO:
		{
			return OnGetMinMaxInfo((PMINMAXINFO)lParam);
		}
	}
	return CModalDialog::OnMessage(message, wParam, lParam);
}

bool CMessagesDialog::OnGetMinMaxInfo(PMINMAXINFO pMMI)
{
	pMMI->ptMinTrackSize.x = m_sizeMinWindow.cx;
	pMMI->ptMinTrackSize.y = m_sizeMinWindow.cy;
  return false;
}
