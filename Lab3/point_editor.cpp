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

void PointEditor::OnMouseMove(HWND hWnd) {}
