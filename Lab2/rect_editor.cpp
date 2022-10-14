#include "ShapeEditor.h"
#include "rect_editor.h"
#include "rect_shape.h"
#include "Resource.h"

void RectEditor::OnLBup(HWND hWnd)
{
	pcshape[index] = new RectShape;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[index]->Set(xstart, ystart, pt.x, pt.y);
	isEditing = false;
	InvalidateRect(hWnd, NULL, TRUE);
	index++;
}

void RectEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_32771, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32772, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32773, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_32774, MF_UNCHECKED);
	}
}

void RectEditor::OnMouseMove(HWND hWnd)
{
	if (isEditing)
	{
		hdc = GetDC(hWnd);
		SetROP2(hdc, R2_NOTXORPEN);
		//removing last image
		MoveToEx(hdc, xstart, ystart, NULL);
		LineTo(hdc, xend, ystart);
		LineTo(hdc, xend, yend);
		MoveToEx(hdc, xstart, ystart, NULL);
		LineTo(hdc, xstart, yend);
		LineTo(hdc, xend, yend);
		//making new image
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		xend = pt.x;
		yend = pt.y;
		MoveToEx(hdc, xstart, ystart, NULL);
		LineTo(hdc, xend, ystart);
		LineTo(hdc, xend, yend);
		MoveToEx(hdc, xstart, ystart, NULL);
		LineTo(hdc, xstart, yend);
		LineTo(hdc, xend, yend);
		ReleaseDC(hWnd, hdc);
	}
}