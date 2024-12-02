/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-01 22:14:45
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-02 11:23:47
 */

#ifndef __XCOLOR_H__
#define __XCOLOR_H__

namespace xviewer::basis
{
    struct Color
    {
        Color(unsigned char r = 0,
              unsigned char g = 0,
              unsigned char b = 0,
              unsigned char a = 255)
            : R(r), G(g), B(b), A(a)
        {
        }
        unsigned char R;
        unsigned char G;
        unsigned char B;
        unsigned char A;
    };

    const Color WHITE = Color(255, 255, 255, 255);
    const Color BLACK = Color(0, 0, 0, 255);

    const Color RED = Color(255, 0, 0, 255);
    const Color RED_DARK = Color(139, 0, 0, 255);
    const Color RED_LIGHT = Color(255, 165, 0, 255);
    const Color RED_LIGHTER = Color(255, 255, 127, 255);
    const Color RED_TRANSPARENT = Color(255, 0, 0, 100);

    const Color GREEN = Color(0, 255, 0, 255);
    const Color GREEN_DARK = Color(0, 100, 0, 255);
    const Color GREEN_LIGHT = Color(144, 238, 144, 255);
    const Color GREEN_LIGHTER = Color(152, 251, 152, 255);
    const Color GREEN_TRANSPARENT = Color(0, 255, 0, 100);

    const Color BLUE = Color(0, 0, 255, 255);
    const Color BLUE_DARK = Color(0, 0, 139, 255);
    const Color BLUE_LIGHT = Color(0, 191, 255, 255);
    const Color BLUE_LIGHTER = Color(173, 216, 230, 255);
    const Color BLUE_TRANSPARENT = Color(0, 0, 255, 100);

    const Color YELLOW = Color(255, 255, 0, 255);
    const Color YELLOW_DARK = Color(139, 139, 0, 255);
    const Color YELLOW_LIGHT = Color(255, 255, 191, 255);
    const Color YELLOW_LIGHTER = Color(255, 255, 205, 255);
    const Color YELLOW_TRANSPARENT = Color(255, 255, 0, 100);

    const Color ORANGE = Color(255, 165, 0, 255);
    const Color ORANGE_DARK = Color(139, 69, 19, 255);
    const Color ORANGE_LIGHT = Color(255, 239, 130, 255);
    const Color ORANGE_LIGHTER = Color(255, 235, 152, 255);
    const Color ORANGE_TRANSPARENT = Color(255, 165, 0, 100);

    const Color PURPLE = Color(128, 0, 128, 255);
    const Color PURPLE_DARK = Color(75, 0, 130, 255);
    const Color PURPLE_LIGHT = Color(216, 191, 216, 255);
    const Color PURPLE_LIGHTER = Color(238, 173, 173, 255);
    const Color PURPLE_TRANSPARENT = Color(128, 0, 128, 100);

    const Color PINK = Color(255, 192, 203, 255);
    const Color PINK_DARK = Color(139, 69, 19, 255);
    const Color PINK_LIGHT = Color(255, 228, 196, 255);
    const Color PINK_LIGHTER = Color(255, 218, 185, 255);
    const Color PINK_TRANSPARENT = Color(255, 192, 203, 100);

    const Color CYAN = Color(0, 255, 255, 255);
    const Color CYAN_DARK = Color(0, 139, 139, 255);
    const Color CYAN_LIGHT = Color(0, 238, 238, 255);
    const Color CYAN_LIGHTER = Color(0, 255, 255, 255);
    const Color CYAN_TRANSPARENT = Color(0, 255, 255, 100);

    const Color MAGENTA = Color(255, 0, 255, 255);
    const Color MAGENTA_DARK = Color(139, 0, 139, 255);
    const Color MAGENTA_LIGHT = Color(238, 130, 238, 255);
    const Color MAGENTA_LIGHTER = Color(255, 205, 210, 255);
    const Color MAGENTA_TRANSPARENT = Color(255, 0, 255, 100);

    const Color BROWN = Color(165, 42, 42, 255);
    const Color BROWN_LIGHT = Color(211, 159, 119, 255);
    const Color BROWN_LIGHTER = Color(184, 134, 112, 255);
    const Color BROWN_TRANSPARENT = Color(165, 42, 42, 100);

}

#endif /* __XCOLOR_H__ */
