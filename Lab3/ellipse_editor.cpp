#include "ShapeEditor.h"
#include "ellipse_editor.h"
#include "ellipse_shape.h"

void EllipseEditor::OnLBup(HWND hWnd)
{
	pcshape[index] = new EllipseShape;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	ShiftStartPoint();
	pcshape[index]->Set(xstart, ystart, pt.x, pt.y);
	isEditing = false;
	InvalidateRect(hWnd, NULL, TRUE);
	index++;
}

void EllipseEditor::OnMouseMove(HWND hWnd)
{
	if (isEditing)
	{
		hdc = GetDC(hWnd);
		SetROP2(hdc, R2_NOTXORPEN);
		hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		hPenOld = (HPEN)SelectObject(hdc, hPen);

		//removing last image
		ShiftStartPoint();
		Arc(hdc, xstart, ystart, xend, yend, 0, 0, 0, 0);

		//making new image
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		xend = pt.x;
		yend = pt.y;
		ShiftStartPoint();
		Arc(hdc, xstart, ystart, xend, yend, 0, 0, 0, 0);

		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
		ReleaseDC(hWnd, hdc);
	}
}