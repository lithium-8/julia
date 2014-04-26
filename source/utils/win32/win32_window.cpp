#include"win32_vars.hpp"
#include"../platform.hpp"

JNAMESPACE_BEGIN

static HINSTANCE Instance = NULL;

static LRESULT _stdcall wndProc(HWND _hwnd, UINT _msg, WPARAM _wp, LPARAM _lp)
{
	switch (_msg)
	{
	case WM_MOVE:
		WindowPosition[0] = (uint16_t)LOWORD(_lp);
		WindowPosition[1] = (uint16_t)HIWORD(_lp);
		break;
	default:
		break;
	}
	return DefWindowProc(_hwnd, _msg, _wp, _lp);
}

bool platformWindowCreate()
{
	WNDCLASSEX wc = { 0 };
	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(wc);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = GetModuleHandle(0);
	wc.lpfnWndProc = wndProc;
	wc.style = CS_OWNDC;
	wc.lpszClassName = "julia-engine";
	wc.lpszMenuName = NULL;
	RegisterClassEx(&wc);

	DWORD exStyle = Windowed == true ? WS_EX_TOPMOST : NULL;
	DWORD style = Windowed == true ? WS_OVERLAPPED : WS_POPUP;

	RECT rect = { 0 };
	SetRect(&rect, WindowPosition[0], WindowPosition[1], WindowSize[0] + WindowPosition[0], WindowSize[1] + WindowPosition[1]);
	AdjustWindowRect(&rect, style, FALSE);

	WindowHandle = CreateWindowEx(exStyle, wc.lpszClassName, WindowTitle, style, rect.left, rect.top, rect.right, rect.bottom, NULL, NULL, wc.hInstance, NULL);
	if (WindowHandle == NULL)
	{
		Error_t err = { JERRCODE_PLATFORM_WINDOW_CREATE_FAILED, "CreateWindowEx() failed", true };
		ErrorsStack::pushError(err);
		return false;
	}
	
	if (Windowed == false)
		ShowWindow(WindowHandle, SHOW_FULLSCREEN);
	else
		ShowWindow(WindowHandle, SHOW_OPENWINDOW);
	UpdateWindow(WindowHandle);

	DeviceContextHandle = GetDC(WindowHandle);
	if (DeviceContextHandle == NULL)
	{
		Error_t err = { JERRCODE_PLATFORM_WINDOW_CREATE_FAILED, "GetDC() failed", true };
		ErrorsStack::pushError(err);
		return false;
	}

	Instance = wc.hInstance;

	return true;
}


void platformWindowDestroy()
{
	if (WindowHandle != NULL)
	{
		if (DeviceContextHandle != NULL)
			ReleaseDC(WindowHandle, DeviceContextHandle);
		DestroyWindow(WindowHandle);
		UnregisterClass("julia", Instance);
	}
}

void platformUpdate()
{
	static MSG msg = { 0 };
	if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

JNAMESPACE_END