#include "ShapeEditor.h"
#include "point_editor.h"
#include "point_shape.h"
#include "Resource.h"

void PointEditor::OnLBup(HWND hWnd)
{
	pcshape[index] = new PointShape;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[index]->Set(xstart, ystart, pt.x, pt.y);
	InvalidateRect(hWnd, NULL, TRUE);
	index++;
}

void PointEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_32771, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_32772, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32773, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_32774, MF_UNCHECKED);
	}
}

void PointEditor::OnMouseMove(HWND hWnd) {}
