#include<Windows.h>  //底层实现窗口的头文件

//程序入口函数 
int WINAPI WinMain(          //WINAPI代表__stdcall 参数的传递顺序:从右向左,以此入栈,并且在函数返回前,清空堆栈
	HINSTANCE hInstance,     //应用程序实例句柄
	HINSTANCE hPrevInstance, //上一个应用程序句柄,win32环境下,参数一般为null,不起作用了
	LPSTR lpComdline,		 //char * argv[]
	int nShowCmd)			 //显示命令:最大化,最小化,正常
{
	//1.设计窗口
	WNDCLASS wc; //窗口类
	wc.cbClsExtra = 0;  //类的额外的内存
	wc.cbWndExtra = 0;  //窗口额外的内存
	wc.hbrBackground =(HBRUSH) GetStockObject(WHITE_BRUSH); //设置背景
	wc.hCursor = LoadCursor(NULL, IDC_HAND);  //设置光标:第一个参数为NULL,代表使用系统提供的光标
	wc.hIcon = LoadIcon(NULL, IDI_ERROR);   //设置图标:如果第一个参数为NULL,代表使用系统提供的图标
	wc.hInstance = hInstance; //应用程序实例句柄,传入WinMain中的形参即可
	//wc.lpfnWndProc            //回调函数 窗口过程
	wc.lpszClassName = TEXT("WIN"); //指定窗口类名称
	wc.style = 0;                 //显示风格 : 0代表默认风格
	//2.注册窗口
	RegisterClass(&wc);
		//3.创建窗口
		/*
		lpClassName,  类名 
		lpWindowName,  标题 名
		dwStyle,		风格
		x,			显示坐标  CW_USEDEFAULT 默认值
		y,
	   nWidth,		宽高
	   nHeight,
	   hWndParent,   父窗口	NULL
	   hMenu,         菜单   NULL
	   hInstance,	实例句柄 hInstance
	   lpParam)		附加值		NULL
		*/
		HWND hwind=CreateWindow(wc.lpszClassName,TEXT("WINDOWS"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance,NULL);
	//4.显示和更新
		ShowWindow(hwind, SW_SHOWNORMAL);
		UpdateWindow(hwind);
	//5.通过循环取消息
		/*
		HWND        hwnd;         主窗口
		UINT        message;	具体的消息名称
		WPARAM      wParam;		附加消息 键盘消息
		LPARAM      lParam;		附加消息 鼠标消息
		DWORD       time;		消息产生时间
		POINT       pt;			附加消息 鼠标消息	x,y
		*/
		MSG msg;

	//6.处理消息(窗口过程)
	return 0;
}