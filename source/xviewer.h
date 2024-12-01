/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-01 21:38:38
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-02 11:25:58
 */

#ifndef __XVIEWER_H__
#define __XVIEWER_H__
#include "basis/base_module.h"

namespace xviewer
{

    class XViewer : public basis::BaseModule
    {
    public:
        XViewer();

        ~XViewer();

        virtual basis::Status Init() override;

        virtual basis::Status Start() override;

        virtual void Stop() override;
    };
}

#endif /* __XVIEWER_H__ */
