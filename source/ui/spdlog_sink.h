/**
 * @Author: Xia Yunkai
 * @Date:   2024-10-27 00:04:35
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 21:42:22
 */

#ifndef __SPDLOG_SINK_H__
#define __SPDLOG_SINK_H__

#include <deque>
#include <imgui.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/ringbuffer_sink.h>
#include <array>

#if SPDLOG_VERSION >= 10600
#include <spdlog/pattern_formatter.h>
#else
#include <spdlog/details/pattern_formatter.h>
#endif

namespace xviewer::ui
{
    template <typename RingBufferSink>
    std::function<void()> create_logger_ui(const std::shared_ptr<RingBufferSink> &sink, double bg_alpha = 1.0)
    {
        auto enabled = std::make_shared<bool>(true);
        return [=]
        {
            if (!(*enabled))
            {
                return;
            }

            const auto log_messages = sink->last_raw();

            ImGui::SetNextWindowSize(ImVec2(660, 400), ImGuiCond_FirstUseEver);
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, bg_alpha));
            ImGui::Begin("logging", enabled.get());

            const char *items[] = {"trace", "debug", "info", "warn", "error", "critical"};
            static int item_index = 0;
            ImGui::SetNextItemWidth(100);
            if (ImGui::Combo("log level", &item_index, items, IM_ARRAYSIZE(items)))
            {
                if (item_index == 0)
                {
                    spdlog::default_logger()->set_level(spdlog::level::trace);
                }
                else if (item_index == 1)
                {
                    spdlog::default_logger()->set_level(spdlog::level::debug);
                }
                else if (item_index == 2)
                {
                    spdlog::default_logger()->set_level(spdlog::level::info);
                }
                else if (item_index == 3)
                {
                    spdlog::default_logger()->set_level(spdlog::level::warn);
                }
                else if (item_index == 4)
                {
                    spdlog::default_logger()->set_level(spdlog::level::err);
                }
                else if (item_index == 5)
                {
                    spdlog::default_logger()->set_level(spdlog::level::critical);
                }
            }

            ImGui::PopStyleColor();

            if (ImGui::BeginChild("scrolling", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar))
            {
                std::array<ImVec4, 6> colors;
                colors[static_cast<int>(spdlog::level::trace)] = ImVec4(0.7f, 0.7f, 0.7f, 0.5f);
                colors[static_cast<int>(spdlog::level::debug)] = ImVec4(0.6f, 0.9f, 1.0f, 0.7f);
                colors[static_cast<int>(spdlog::level::info)] = ImVec4(0.9f, 1.0f, 0.9f, 1.0f);
                colors[static_cast<int>(spdlog::level::warn)] = ImVec4(1.0f, 1.0f, 0.0f, 1.0f);
                colors[static_cast<int>(spdlog::level::err)] = ImVec4(1.0f, 0.5f, 0.0f, 1.0f);
                colors[static_cast<int>(spdlog::level::critical)] = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);

                spdlog::pattern_formatter formatter;

                for (const auto &log : log_messages)
                {
                    const auto &level = log.level;

                    spdlog::memory_buf_t formatted;
                    formatter.format(log, formatted);
                    std::string text = fmt::to_string(formatted);

                    const auto &color = colors[static_cast<int>(level)];
                    ImGui::TextColored(color, "%s", text.c_str());
                }

                if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
                {
                    ImGui::SetScrollHereY(1.0f);
                }
            }

            ImGui::EndChild();
            ImGui::End();
        };
    }
}

#endif /* __SPDLOG_SINK_H__ */
