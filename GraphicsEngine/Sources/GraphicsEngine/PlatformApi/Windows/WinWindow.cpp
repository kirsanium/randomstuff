#include "WinWindow.h"

#ifdef CAN_USE_DIRECT_X

#include "Screen.h"
#include "PlatformApi/Windows/WinInput.h"


WinWindow * pWinWindow = nullptr;

LRESULT WINAPI WndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
		// TODO: Добавить обработку изменения размера окна
		case WM_SIZE:
			{
				pWinWindow->SetResolution();
				break;
			}

		case WM_EXITSIZEMOVE:
			{
				pWinWindow->SetResolution();
				break;
			}

        case WM_DESTROY:
            PostQuitMessage( 0 );
            return 0;
    }

    return DefWindowProc( hWnd, msg, wParam, lParam );
}


WinWindow::WinWindow(const TCHAR * pTitle)
	:	m_pTitle( pTitle )
{
	pWinWindow = this;
}

WinWindow::~WinWindow()
{
	pWinWindow = nullptr;
}

void WinWindow::Init(GraphicsEngineImpl * pEngineImpl)
{
	// Register the window class
    m_wc.cbSize			= sizeof( WNDCLASSEX );
	m_wc.style			= CS_HREDRAW | CS_VREDRAW;
	m_wc.lpfnWndProc	= WndProc;
	m_wc.cbClsExtra		= 0;
	m_wc.cbWndExtra		= 0;
	m_wc.hInstance		= GetModuleHandle( nullptr );
	m_wc.hIcon			= nullptr;
	m_wc.hCursor		= LoadCursor( nullptr, IDC_ARROW );
	m_wc.hbrBackground	= ( HBRUSH )( COLOR_WINDOW + 1 );
	m_wc.lpszMenuName	= nullptr;
	m_wc.lpszClassName	= m_pTitle;
	m_wc.hIconSm		= nullptr;
    
	if( !RegisterClassEx( &m_wc ) )
			return;

    // Create the application's window
	RECT rc = { 0, 0, 512, 512 };
	AdjustWindowRect( &rc, WS_OVERLAPPEDWINDOW, FALSE );
    m_hWnd = CreateWindow( m_pTitle, m_pTitle, WS_OVERLAPPEDWINDOW, 
			CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top,
			nullptr, nullptr, m_wc.hInstance, nullptr );

	m_pWindowsEngineImpl = pEngineImpl;

	WinInput::Init();
}

void WinWindow::Deinit()
{
	m_pWindowsEngineImpl = nullptr;

	UnregisterClass( m_pTitle, m_wc.hInstance );
}

void WinWindow::Show()
{
	// Show the window
	ShowWindow( m_hWnd, SW_SHOWDEFAULT );
	UpdateWindow( m_hWnd );

	// Enter the message loop
	ZeroMemory( &m_msg, sizeof( m_msg ) );  
}

HWND WinWindow::GetHWND()
{
	return m_hWnd;
}

void WinWindow::SetResolution()
{
	int width, height;
	GetResolution(width, height);

	m_pWindowsEngineImpl->SetResolution(width, height);
}

void WinWindow::GetResolution(int & width, int & height)
{
	RECT rc;
	GetClientRect( m_hWnd, &rc );
	width	= static_cast<int>( rc.right - rc.left );
	height	= static_cast<int>( rc.bottom - rc.top );

	Screen::SetResolution(width, height);
}

void WinWindow::DispatchMessages()
{
	WinInput::Clear();

	while (IsRunning() && PeekMessage( &m_msg, nullptr, 0U, 0U, PM_REMOVE ) )
    {
		WinInput::Dispatch(m_msg);

		TranslateMessage( &m_msg );
        DispatchMessage( &m_msg );
    }
}

bool WinWindow::IsRunning()
{
	return (m_msg.message != WM_QUIT);
}

#endif
