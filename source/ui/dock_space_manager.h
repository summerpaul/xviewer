/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-03 21:37:51
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 21:55:01
 */

#ifndef __DOCK_SPACE_MANAGER_H__
#define __DOCK_SPACE_MANAGER_H__
#include <future>
#include <unordered_map>
#include "component/component.h"
#include "base_layer.h"
#include "spdlog_sink.h"

struct GLFWwindow;
namespace xviewer::ui
{
    typedef std::function<void()> VOID_CALLBACK;

    class DockSpaceManager final : public Component
    {
    public:
        DockSpaceManager();
        ~DockSpaceManager();
        void Initialize() override;
        void Update(float deltaTime) override;

        void RegisterUiCallback(const std::string &name,
                                const VOID_CALLBACK &callback);

    private:
        static void DropCallback(GLFWwindow *window, int count, const char **paths);
        void InitializeDocks();
        void DrawMenuBar();

        void UpdateSublayers(float deltaTime);
        void UpdateCallbacks();

    private:
        Document m_dockSpaceDocument;
        static std::vector<BaseLayer::Ptr> s_layers;
        std::shared_ptr<spdlog::sinks::ringbuffer_sink_mt> m_pRingbufferSink;
        std::unordered_map<std::string, VOID_CALLBACK> m_uiCallbacks;
    };
}
#endif /* __DOCK_SPACE_MANAGER_H__ */
