#include<Windows.h>  //�ײ�ʵ�ִ��ڵ�ͷ�ļ�

//������ں��� 
int WINAPI WinMain(          //WINAPI����__stdcall �����Ĵ���˳��:��������,�Դ���ջ,�����ں�������ǰ,��ն�ջ
	HINSTANCE hInstance,     //Ӧ�ó���ʵ�����
	HINSTANCE hPrevInstance, //��һ��Ӧ�ó�����,win32������,����һ��Ϊnull,����������
	LPSTR lpComdline,		 //char * argv[]
	int nShowCmd)			 //��ʾ����:���,��С��,����
{
	//1.��ƴ���
	WNDCLASS wc; //������
	wc.cbClsExtra = 0;  //��Ķ�����ڴ�
	wc.cbWndExtra = 0;  //���ڶ�����ڴ�
	wc.hbrBackground =(HBRUSH) GetStockObject(WHITE_BRUSH); //���ñ���
	wc.hCursor = LoadCursor(NULL, IDC_HAND);  //���ù��:��һ������ΪNULL,����ʹ��ϵͳ�ṩ�Ĺ��
	wc.hIcon = LoadIcon(NULL, IDI_ERROR);   //����ͼ��:�����һ������ΪNULL,����ʹ��ϵͳ�ṩ��ͼ��
	wc.hInstance = hInstance; //Ӧ�ó���ʵ�����,����WinMain�е��βμ���
	//wc.lpfnWndProc            //�ص����� ���ڹ���
	wc.lpszClassName = TEXT("WIN"); //ָ������������
	wc.style = 0;                 //��ʾ��� : 0����Ĭ�Ϸ��
	//2.ע�ᴰ��
	RegisterClass(&wc);
		//3.��������
		/*
		lpClassName,  ���� 
		lpWindowName,  ���� ��
		dwStyle,		���
		x,			��ʾ����  CW_USEDEFAULT Ĭ��ֵ
		y,
	   nWidth,		���
	   nHeight,
	   hWndParent,   ������	NULL
	   hMenu,         �˵�   NULL
	   hInstance,	ʵ����� hInstance
	   lpParam)		����ֵ		NULL
		*/
		HWND hwind=CreateWindow(wc.lpszClassName,TEXT("WINDOWS"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance,NULL);
	//4.��ʾ�͸���
		ShowWindow(hwind, SW_SHOWNORMAL);
		UpdateWindow(hwind);
	//5.ͨ��ѭ��ȡ��Ϣ
		/*
		HWND        hwnd;         ������
		UINT        message;	�������Ϣ����
		WPARAM      wParam;		������Ϣ ������Ϣ
		LPARAM      lParam;		������Ϣ �����Ϣ
		DWORD       time;		��Ϣ����ʱ��
		POINT       pt;			������Ϣ �����Ϣ	x,y
		*/
		MSG msg;

	//6.������Ϣ(���ڹ���)
	return 0;
}