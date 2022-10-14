#include "ShapeEditor.h"
#include "line_editor.h"
#include "line_shape.h"
#include "Resource.h"

void LineEditor::OnLBup(HWND hWnd)
{
	pcshape[index] = new LineShape;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[index]->Set(xstart, ystart, pt.x, pt.y);
	isEditing = false;
	InvalidateRect(hWnd, NULL, TRUE);
	index++;
}

void LineEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_32771, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32772, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_32773, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32774, MF_UNCHECKED);
	}
}

void LineEditor::OnMouseMove(HWND hWnd)
{
	if (isEditing)
	{
		hdc = GetDC(hWnd);
		SetROP2(hdc, R2_NOTXORPEN);
		//removing last image
		MoveToEx(hdc, xstart, ystart, NULL);
		LineTo(hdc, xend, yend);
		//making new image
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		xend = pt.x;
		yend = pt.y;
		MoveToEx(hdc, xstart, ystart, NULL);
		LineTo(hdc, xend, yend);
		ReleaseDC(hWnd, hdc);
	}
}