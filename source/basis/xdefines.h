/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-02 11:34:20
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-02 11:35:18
 */

#ifndef __XDEFINES_H__
#define __XDEFINES_H__

#define XMAX(a, b) (((a) > (b)) ? (a) : (b))                  // maximum
#define XMIN(a, b) (((a) < (b)) ? (a) : (b))                  // minimum
#define XCLAMP(v, min, max) (XVIZ_MAX(XVIZ_MIN(v, max), min)) // clamp
#define XPI (3.1415926f)                                      // pi
#define X2PI (6.2831853f)                                     // 2*pi
#define XPI2 (1.5707963f)                                     // pi/2
#define XPI4 (0.78539815f)                                    // pi/2
#define XRPI (0.31831f)                                       // 1/pi
#define XANG2RAD(x) ((x)*HATA_PI * 0.0055556f)                // 角度转弧度，转完后变成浮点型
#define XRAD2ANG(x) ((x)*HATA_RPI * 180)
#define XSIGN(x) (((0) < x) - (x < (0)))
#define XEPS 1e-6f

#define CHECK_RETURN(state) \
    if (state)              \
    {                       \
        return;             \
    }

#define CHECK_CONTINUE(state) \
    if (state)                \
    {                         \
        continue;             \
    }

#define CHECK_BREAK(state) \
    if (state)             \
    {                      \
        break;             \
    }

#define CHECK_RETURN_RET(state, ret) \
    if (state)                       \
    {                                \
        return ret;                  \
    }

#endif /* __XDEFINES_H__ */
