#include "framework.h"
#include "myeditor.h"

MyEditor* MyEditor::p_instance = 0;
Shape* MyEditor::pcshape[MY_SHAPE_ARRAY_SIZE];
int MyEditor::index = 0;

MyEditor::~MyEditor()
{
	for (int i = 0; i < MY_SHAPE_ARRAY_SIZE; i++)
		if (pcshape[i]) pcshape[i] = NULL;
}

MyEditor* MyEditor::getInstance()
{
	if (!p_instance)
		p_instance = new MyEditor();
	return p_instance;
}

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

std::wstring MyEditor::OnLBup(HWND hWnd)
{
	std::wstring properties = L"";

	if (currentShape) 
	{
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		pcshape[index]->SetEnd(pt.x, pt.y);
		properties = pcshape[index]->getProperties();
		isEditing = false;
		InvalidateRect(hWnd, NULL, TRUE);
		index++;
	}
	return properties;
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

void MyEditor::OnPaint(HWND hWnd, int chosenItem)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < MY_SHAPE_ARRAY_SIZE; i++) 
	{ 
		bool isSelected = chosenItem == i;
		if (pcshape[i]) pcshape[i]->ShowGlobal(hdc, isSelected);
	}
	EndPaint(hWnd, &ps);
}

void MyEditor::RemoveItem(int chosenItem)
{
	if (chosenItem >= 0)
	{
		for (int index = 0; index < MY_SHAPE_ARRAY_SIZE; index++)
			if (index >= chosenItem)
			{
				Shape* next = pcshape[index + 1];
				if (next)
					pcshape[index] = next;
				else
				{
					pcshape[index] = NULL;
					break;
				}
			}
		index--;
	}
}

