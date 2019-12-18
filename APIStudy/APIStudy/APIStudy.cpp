// APIStudy.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "APIStudy.h"

#define MAX_LOADSTRING 100


// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.


// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);  //About <- ���������� �ʿ����

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_APISTUDY, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_APISTUDY));

    MSG msg;
	//DWORD <- unsigned long
    // �⺻ �޽��� �����Դϴ�.
	//GetMessage �ǰ�� ������ ���鶧 �������� �ʴ�..  <-Message�� ���ö����� Block�Ǿ�����(Message�����ö����� ���α׷� ����)
	//PeekMessage�� ���  <- Message�������� true��ȯ  ������ false ��ȯ
	while (WM_QUIT!=msg.message) //<-����޼���
	{

		//PM_REMOVE: Message Queue���� ���� ���� Message�� ������
		//PM_NOREMOVE: Message Queue���� Message�� �������� �ʰ� �״�ε�
		while (PeekMessage(&msg, nullptr, 0, 0,PM_NOREMOVE)) 
		{
			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

	}

    return (int) msg.wParam;
}



//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APISTUDY));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_APISTUDY);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//CallBack �Լ�: ����ڰ� �ƴ϶� �ý����� ȣ���ϴ� �Լ�.

	// �Լ� ȣ�� �Ծ�
	// ���� ���� ������ ��� �ϸ�, �Լ� ����� �� ���� ������ ���� �� ���ΰ�?
	// __cdecl:		���� ���� ���� ������ -> ���� ����. ȣ���ڰ� stack ����.
	// __stdcall:	���� ���� ���� ������ -> ���� ����. ��ȣ���ڰ� stack ����.
	// __fastcall:	���� ���� ���� ������ -> ���� ����. ��ȣ���ڰ� stack ����.
	// __thiscall:	���� ���� ���� ������ -> ���� ����. ��ȣ���ڰ� stack ����.

	switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // �޴� ������ ���� �м��մϴ�.
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT: //â�� �׸������� ȣ�� ��: �ּ�ȭ�޴ٰ� ��ﶧ, windowũ�⸦ �ٲܶ� ��... 
        {
            PAINTSTRUCT ps;
			// DC(Device Context): �׸��⿡ �ʿ��� �������� �����ϴ� �޸�(����).
			// HDC: DC�� �ڵ�.
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�.

			// MoveToEx: �׸��� ������(Ŀ�� ����Ʈ, CP)�� �ű�� �Լ�.
			// ������ ���ڿ��� �̵��ϱ� ���� Ŀ�� ����Ʈ ��ġ�� ��ϵ�.			
			//LineTo(hdc, 200, 100);
			//LineTo(hdc, 100, 200);
			//LineTo(hdc, 100, 100);
			//LineTo(hdc, 200, 200);
			//LineTo(hdc, 50, 100);
			Rectangle(hdc, 100, 100, 400, 400); // �簢�� �׸��� �Լ�
			Rectangle(hdc, 450, 100, 750, 400); // �簢�� �׸��� �Լ�
			Rectangle(hdc, 800, 100, 1100, 400); // �簢�� �׸��� �Լ�
			Rectangle(hdc, 100, 100, 400, 400); // �簢�� �׸��� �Լ�
			MoveToEx(hdc, 135, 125, nullptr);
			LineTo(hdc, 270, 125);
			LineTo(hdc, 135, 270);
			MoveToEx(hdc, 315, 110, nullptr);
			LineTo(hdc, 315, 285);
			Rectangle(hdc, 145, 300, 315, 375); // �簢�� �׸��� �Լ�

			MoveToEx(hdc, 485, 125, nullptr);
			LineTo(hdc, 715, 125);
			LineTo(hdc, 485, 275);
			MoveToEx(hdc, 600, 200, nullptr);
			LineTo(hdc, 715, 270);1`wq
			MoveToEx(hdc, 485, 300, nullptr);
			LineTo(hdc, 715, 300);
			MoveToEx(hdc, 600, 300, nullptr);
			LineTo(hdc, 600, 350);
			MoveToEx(hdc, 485, 325, nullptr);
			LineTo(hdc, 485, 385);
			LineTo(hdc, 715, 385);

			Ellipse(hdc, 835, 125, 950, 250);	  // �� �׸��� �Լ�
			MoveToEx(hdc, 950, 175, nullptr);
			LineTo(hdc, 1035, 175);
			MoveToEx(hdc, 950, 200, nullptr);
			LineTo(hdc, 1035, 200);
			MoveToEx(hdc, 1035, 125, nullptr);
			LineTo(hdc, 1035, 275);

			//LineTo(hdc,)

			Ellipse(hdc, 890, 265, 1005,390 );	  // �� �׸��� �Լ�


			
			EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}