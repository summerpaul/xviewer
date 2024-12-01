/**
 * @Author: Xia Yunkai
 * @Date:   2024-09-06 23:35:28
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-01 22:12:20
 */
#include <stdint.h>

#ifndef __BASE_LAYER_H__
#define __BASE_LAYER_H__

#include <memory>
#include <string>
#include <vector>

namespace xviewer::ui
{
    class BaseLayer
    {
    public:
        typedef std::shared_ptr<BaseLayer> Ptr;
        BaseLayer(const std::string &name = "") : m_name(name) {}
        virtual ~BaseLayer() {}
        const std::string &GetName() const { return m_name; }
        virtual void Update(float deltaTime) {};
        virtual bool Init() { return false; }
        virtual void FilesDropCallback(int count, const char **paths) {}
        virtual void FilesOpenCallback(const std::vector<std::string> &paths) {}
        virtual void Shutdown() {};
        bool IsInitialized() const { return m_initialized; }

    protected:
        std::string m_name;
        bool m_initialized = false;
    };
}

#endif /* __BASE_LAYER_H__ */
