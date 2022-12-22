#include "shape.h"

void Shape::Set(long x1, long y1, long x2, long y2)
{
	xs1 = x1;
	ys1 = y1;

	xs2 = x2;
	ys2 = y2;
}

void Shape::SetEnd(long x1, long y1)
{
	xs2 = x1;
	ys2 = y1;
}

void Shape::ShowGlobal(HDC hdc, bool isSelected)
{
	COLORREF color;
	if (isSelected)
		color = RGB(0, 255, 0);
	else color = 0;

	HPEN hPen = CreatePen(PS_SOLID, 1, color);
	HPEN hPenOld = (HPEN)SelectObject(hdc, hPen);

	Show(hdc);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}

std::wstring Shape::getProperties()
{
	WCHAR properties[50];
	const wchar_t* format;

	std::wstring name = getName();
	if (name.length() > 8)
		format = L"%s\t%d\t%d\t%d\t%d";
	else
		format = L"%s\t\t%d\t%d\t%d\t%d";

	swprintf_s(properties, 50, format, name.c_str(), xs1, ys1, xs2, ys2);
	return properties;
}
