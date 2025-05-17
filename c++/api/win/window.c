#include <windows.h>
 
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    // 1. Đăng ký lớp cửa sổ
    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MyWindowClass";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // Đặt màu nền trắng
    wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Con trỏ chuột mặc định
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); // Biểu tượng mặc định

    if (!RegisterClass(&wc)) return 0;

    // 2. Tạo cửa sổ
    HWND hwnd = CreateWindow(
        "MyWindowClass",         // Lớp cửa sổ
        "Cửa sổ đơn giản",      // Tiêu đề
        WS_OVERLAPPEDWINDOW,    // Kiểu cửa sổ
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, // Vị trí và kích thước
        NULL, NULL, hInstance, NULL
    );

    if (!hwnd) return 0;

    // 3. Hiển thị cửa sổ
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // 4. Vòng lặp thông điệp
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) { // Thêm kiểm tra điều kiện an toàn
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

// 5. Xử lý thông điệp
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}
