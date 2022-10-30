#include "ShapeEditor.h"

ShapeEditor::ShapeEditor(void) {}
Shape* ShapeEditor::pcshape[MY_SHAPE_ARRAY_SIZE];
int ShapeEditor::index = 0;

void ShapeEditor::OnLBdown(HWND hWnd)
{
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	constXstart = pt.x;
	constYstart = pt.y;
	xstart = pt.x;
	xend = pt.x;
	ystart = pt.y;
	yend = pt.y;
	isEditing = true;
}

void ShapeEditor::OnPaint(HWND hWnd)
{
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < MY_SHAPE_ARRAY_SIZE; i++) {
		if (pcshape[i]) {
			pcshape[i]->Show(hdc);
		}
	}
	EndPaint(hWnd, &ps);
}

void ShapeEditor::ShiftStartPoint() // to enable drowing from the center to one of the edges
{
	xstart = (2 * constXstart) - xend;
	ystart = (2 * constYstart) - yend;
}
