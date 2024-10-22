﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZRND_GLIDE__DIB_H__VER0__
#define __ZRND_GLIDE__DIB_H__VER0__


  class CDIBSection16 {
  public:
    struct CDIBSection16Dummy0 {
      BITMAPINFO bmi;
      RGBQUAD more_bmiColors[256];
      LPVOID data;
    };

    RECT m_rect;
    HWND m_hwndParent;
    HPALETTE m_hpal;
    HDC m_hdc;
    HBITMAP m_hbm;
    HBITMAP m_oldhbm;
    CDIBSection16Dummy0 m_bitmap;

    CDIBSection16() {}
  };


#endif // __ZRND_GLIDE__DIB_H__VER0__