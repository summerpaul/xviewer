/**
 * @Author: Xia Yunkai
 * @Date:   2024-09-06 23:35:28
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-02 11:40:37
 */
#include <stdint.h>

#ifndef __BASE_LAYER_H__
#define __BASE_LAYER_H__

#include <memory>
#include <string>
#include <vector>
#include "basis/base_module.h"

namespace xviewer::ui
{
    class BaseLayer : public basis::BaseModule
    {
    public:
        typedef std::shared_ptr<BaseLayer> Ptr;

        BaseLayer(const std::string &name = "") : basis::BaseModule(name) {}

        virtual ~BaseLayer() {}

        virtual void Update(float deltaTime){};

        virtual void FilesDropCallback(int count, const char **paths) {}

        virtual void FilesOpenCallback(const std::vector<std::string> &paths) {}
    };
}

#endif /* __BASE_LAYER_H__ */
