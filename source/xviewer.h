/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-01 21:38:38
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-02 09:37:10
 */

#ifndef __XVIEWER_H__
#define __XVIEWER_H__
#include "basis/base_module.h"

namespace xviewer
{

    class XViewer : public BaseModule
    {
    public:
        virtual Status Init() override;

        virtual Status Start() override;

        virtual void Stop() override;
    };
}

#endif /* __XVIEWER_H__ */
