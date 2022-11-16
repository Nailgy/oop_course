#include "framework.h"
#include "myeditor.h"

MyEditor::MyEditor(void) {}
MyEditor::~MyEditor() 
{
	for (int i = 0; i < MY_SHAPE_ARRAY_SIZE; i++)
		if (pcshape[i]) pcshape[i] = NULL;
}
Shape* MyEditor::pcshape[MY_SHAPE_ARRAY_SIZE];
int MyEditor::index = 0;

void MyEditor::Start(HWND hWnd, Shape* psh)
{
	currentShape = psh;
	SetWindowText(hWnd, currentShape->getDisplayText());
}

void MyEditor::OnLBdown(HWND hWnd)
{
	if (currentShape) 
	{
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		pcshape[index] = currentShape->duplicateShape();
		pcshape[index]->Set(pt.x, pt.y, pt.x, pt.y);
		isEditing = true;
	}
}

void MyEditor::OnLBup(HWND hWnd)
{
	if (currentShape) 
	{
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		pcshape[index]->SetEnd(pt.x, pt.y);
		isEditing = false;
		InvalidateRect(hWnd, NULL, TRUE);
		index++;
	}
}

void MyEditor::OnMouseMove(HWND hWnd)
{
	if (isEditing && currentShape)
	{
		pcshape[index]->DrawRubber(hWnd);
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		pcshape[index]->SetEnd(pt.x, pt.y);
		pcshape[index]->DrawRubber(hWnd);
	}
}

void MyEditor::OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < MY_SHAPE_ARRAY_SIZE; i++)
		if (pcshape[i]) pcshape[i]->Show(hdc);
	EndPaint(hWnd, &ps);
}

