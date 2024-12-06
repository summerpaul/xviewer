/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-02 09:10:27
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 21:47:38
 */

#ifndef __BASE_MODULE_H__
#define __BASE_MODULE_H__
#include <string>
#include "status.h"
#include "logger.h"
namespace xviewer::basis
{
    class BaseModule
    {
    public:
        BaseModule(const std::string &name = "") : m_name(name) {}

        virtual ~BaseModule() {}

        const std::string &Name() const { return m_name; }

        bool IsStarted() const { return m_started; }

        bool IsInitialized() const { return m_initialized; }

        virtual Status Init() = 0;

        virtual Status Start() = 0;

        virtual void Shutdown() = 0;

        Status Run();

    protected:
        // 对应模块的名字
        std::string m_name;
        bool m_started = false;
        bool m_initialized = false;
    };
}

#endif /* __BASE_MODULE_H__ */
