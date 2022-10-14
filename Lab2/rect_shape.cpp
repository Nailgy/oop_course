#include "framework.h"

#include "rect_shape.h"

HBRUSH hBrush, hBrushOld;

void RectShape::Show(HDC hdc)
{
	hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 128, 0));
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	Rectangle(hdc, xs1, ys1, xs2, ys2);

	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);

}