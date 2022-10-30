#include "ShapeEditor.h"
#include "line_editor.h"
#include "line_shape.h"

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

void LineEditor::OnMouseMove(HWND hWnd)
{
	if (isEditing)
	{
		hdc = GetDC(hWnd);
		SetROP2(hdc, R2_NOTXORPEN);
		hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		hPenOld = (HPEN)SelectObject(hdc, hPen);

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

		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
		ReleaseDC(hWnd, hdc);
	}
}