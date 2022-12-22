#include "rect_shape.h"

void RectShape::Show(HDC hdc)
{
	hBrush = (HBRUSH)CreateSolidBrush(RGB(192, 192, 192));
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
	long shiftedX = 2 * xs1 - xs2;
	long shiftedY = 2 * ys1 - ys2;
	Rectangle(hdc, shiftedX, shiftedY, xs2, ys2);

	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}

void RectShape::DrawRubber(HWND hWnd)
{
	HDC hdc;
	HPEN hPenOld, hPen;
	hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	
	long shiftedX = 2 * xs1 - xs2;
	long shiftedY = 2 * ys1 - ys2;
	MoveToEx(hdc, shiftedX, shiftedY, NULL);
	LineTo(hdc, xs2, shiftedY);
	LineTo(hdc, xs2, ys2);
	MoveToEx(hdc, shiftedX, shiftedY, NULL);
	LineTo(hdc, shiftedX, ys2);
	LineTo(hdc, xs2, ys2);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
}

Shape* RectShape::duplicateShape()
{
	return new RectShape;
}

LPCTSTR RectShape::getDisplayText()
{
	return  L"Режим вводу прямокутників";
}

std::wstring RectShape::getName()
{
	return L"Прямокутник";
}