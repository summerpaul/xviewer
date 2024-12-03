/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-03 09:32:25
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 09:37:42
 */
#include <stdint.h>

#ifndef __COLORMAP_H__
#define __COLORMAP_H__

#include "basis/data_types.h"
namespace xviewer::gl
{
    using namespace basis;
    enum class COLORMAP
    {
        TURBO = 0,
        JET,
        CIVIDIS,
        OCEAN,
        SPRING,
        SUMMER,
        AUTUMN,
        WINTER,
        GREAN_YELLOW,
        BLUE_RED,
        PUBUGN,
        TURBID,
        PASTEL,
        HELIX,
        PHASE,
        VEGETATION,
        CURL,
        COOL_WARM,
        NUM_COLORMAPS
    };

    Vec4i colormap(COLORMAP type, int x);
    Vec4f colormapf(COLORMAP type, float x);
    Vec4i colormap_categorical(COLORMAP type, int x, int num_categories);
    Vec4f colormap_categoricalf(COLORMAP type, int x, int num_categories);

    std::vector<const char *> colormap_names();
    std::array<std::array<unsigned char, 3>, 256> colormap_table(COLORMAP type);

}

#endif /* __COLORMAP_H__ */
