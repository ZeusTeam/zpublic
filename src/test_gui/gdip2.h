#pragma once
#include "resource.h"

class CGdip2 : public CSimpleDialog<IDD_DIALOG6>
{
public:
    BEGIN_MSG_MAP(CGdip2)
        MSG_WM_INITDIALOG(OnInitDialog)
        MSG_WM_PAINT(OnPaint)
        COMMAND_ID_HANDLER(IDOK, OnOk)
    END_MSG_MAP()

public:
    CGdip2()
    {

    }
    ~CGdip2()
    {

    }

private:
    BOOL OnInitDialog(CWindow, LPARAM)
    {
        CenterWindow();
        return TRUE;
    }

    void OnPaint(CDCHandle dc)
    {
        PAINTSTRUCT  ps;
        HDC hdc = BeginPaint(&ps);
        {
            Graphics    graphics(hdc);
            SolidBrush  brush(Color(255, 0, 0, 255));
            FontFamily  fontFamily(L"����");
            Font        font(&fontFamily, 24, FontStyleRegular, UnitPixel);
            PointF      pointF(10.0f, 20.0f);
            graphics.DrawString(L"Hello World!", -1, &font, pointF, &brush);

            Gdiplus::StringFormat format;
            Gdiplus::RectF layoutRect1(100, 100, 200, 13);
            Gdiplus::RectF layoutRect2(100, 130, 200, 13);
            format.SetFormatFlags(Gdiplus::StringFormatFlagsLineLimit);
            format.SetLineAlignment(Gdiplus::StringAlignmentFar);
            graphics.DrawString(
                L"111111",
                -1,
                &font,
                layoutRect1,
                &format,
                &brush);
            format.SetLineAlignment(Gdiplus::StringAlignmentNear);
            graphics.DrawString(
                L"111111",
                -1,
                &font,
                layoutRect2,
                &format,
                &brush);
        }
        EndPaint(&ps);
    }

    LRESULT OnOk(WORD, UINT, HWND, BOOL&)
    {
        ::EndDialog(m_hWnd, IDOK);
        return 0;
    }
};

void gdip2()
{
    CGdip2 dlg;
    dlg.DoModal();
}