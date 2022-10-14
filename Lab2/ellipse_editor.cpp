#include "ShapeEditor.h"
#include "ellipse_editor.h"
#include "ellipse_shape.h"
#include "Resource.h"

void EllipseEditor::OnLBup(HWND hWnd)
{
	pcshape[index] = new EllipseShape;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xend = pt.x;
	yend = pt.y;
	xstart = (2 * xstart) - xend;
	ystart = (2 * ystart) - yend;
	pcshape[index]->Set(xstart, ystart, xend, yend);
	isEditing = false;
	InvalidateRect(hWnd, NULL, TRUE);
	index++;
}

void EllipseEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_32771, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32772, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32773, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32774, MF_CHECKED);

	}
}

void EllipseEditor::OnMouseMove(HWND hWnd)
{
	if (isEditing)
	{
		hdc = GetDC(hWnd);
		SetROP2(hdc, R2_NOTXORPEN);
		//removing last image
		Arc(hdc, (2 * xstart) - xend, (2 * ystart) - yend, xend, yend, 0, 0, 0, 0);
		//making new image
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		xend = pt.x;
		yend = pt.y;
		Arc(hdc, (2 * xstart) - xend, (2 * ystart) - yend, xend, yend, 0, 0, 0, 0);
		ReleaseDC(hWnd, hdc);
	}
}