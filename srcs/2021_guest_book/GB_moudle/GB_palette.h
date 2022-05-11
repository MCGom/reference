#pragma once

#include<Windows.h>
#include<vector>
#include<stdlib.h>
#include<ctime>

// �ķ�Ʈ
#define BTNS (sizeof(cols)/sizeof(COLORREF))    // ���� ��ư ����
//#define S_BTN_x 650                             // ���� ��ư ���� x��ġ
//#define S_BTN_y 30                              // ���� ��ư ���� y��ġ
#define BTN_gap 3                               // ��ư ����
#define BTN_size 35                             // ��ư ũ��

// ������ ���� 
#define Window_Size_Width 1370                  //������ ����
#define Window_Size_Height 700                  // ������ ����

#ifndef WINDOW_COLOR
#define WINDOW_COLOR RGB(230,230,230)
#endif

#define Screen_Save_Timer 
static COLORREF cols[] = {
                    RGB(0,0,0),         //����
                    RGB(255,255,255),   //���
                    RGB(192,192,192),   //ȸ��
                    RGB(238,45,54),     //������
                    RGB(255,127,39),    //��Ȳ��
                    RGB(255,242,0),     //�����
                    RGB(113,222,22),    //���λ�
                    RGB(14,190,98),     //�ʷϻ�
                    RGB(23,186,255),    //�ϴû�
                    RGB(64,125,217),    //�Ķ���
                    RGB(163,73,164),    //�����
                    RGB(255,174,201),   //����ȫ
                    RGB(251,117,190),   //��ȫ
                    RGB(185,122,87),    //����
};

typedef struct btn      //���� ��ư������ ������ ����ü
{
    RECT rect;
    COLORREF col;
    HBRUSH brsh;
    HPEN pen;
    //HWND Wnd;
}BTN;

class Palette
{
public:
    BTN btn_ran;
    COLORREF ran;
    HPEN pen;
    int x;
    int y;
    int boundary_x;
    int boundary_y;
    std::vector<BTN> btns;

    Palette(int x, int y);
    ~Palette();
    void paint(HWND hWnd, HDC hdc);
    COLORREF is_press(LPARAM lParam);

    COLORREF ChangeRand();
};

class GB_Pen
{
public:
    int x;
    int y;
    int width;
    int height;
    int size;
    int text_x;
    int text_y;
    int text_size;
    COLORREF col;
    RECT area;
    RECT text_area;

    GB_Pen(int x, int y, int width, int height);
    GB_Pen(int x, int y, int width, int height, int text_x, int text_y, int text_size);
    void set_color(COLORREF col);
    COLORREF get_color();
    void set_size(int size);
    void set_size_up();
    void set_size_down();
    int get_size();
    void paint(HWND hWnd, HDC hdc);
    void paint_text(HWND hWnd, HDC hdc);
};
