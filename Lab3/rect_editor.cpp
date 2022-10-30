#include "ShapeEditor.h"
#include "rect_editor.h"
#include "rect_shape.h"

void RectEditor::OnLBup(HWND hWnd)
{
	pcshape[index] = new RectShape;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xend = pt.x;
	yend = pt.y;
	
	pcshape[index]->Set(xstart, ystart, xend, yend);
	isEditing = false;
	InvalidateRect(hWnd, NULL, TRUE);
	index++;
}

void RectEditor::OnMouseMove(HWND hWnd)
{
	if (isEditing)
	{
		hdc = GetDC(hWnd);
		SetROP2(hdc, R2_NOTXORPEN);
		hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		hPenOld = (HPEN)SelectObject(hdc, hPen);

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

		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
		ReleaseDC(hWnd, hdc);
	}
}