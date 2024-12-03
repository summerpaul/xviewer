/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-03 13:16:30
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 13:35:49
 */

#ifndef __CONCURRENT_QUEUE_H__
#define __CONCURRENT_QUEUE_H__

#include <deque>
#include <mutex>

// 线程安全队列
namespace xviewer::utils
{
    template <typename T>
    class ConcurrentQueue
    {
    public:
        virtual ~ConcurrentQueue() {}

        virtual size_t size() const = 0;
        virtual void push(const T &item) = 0;
        virtual std::vector<T> try_pop(int max_num_items) = 0;
    };

    template <typename T>
    class StdConcurrentQueue : public ConcurrentQueue<T>
    {
    public:
        StdConcurrentQueue() {}
        virtual ~StdConcurrentQueue() override {}

        virtual size_t size() const override
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            return m_queue.size();
        }

        virtual void push(const T &item) override
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            m_queue.push_back(item);
        }

        virtual std::vector<T> try_pop(int max_num_items) override
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            if (m_queue.empty())
            {
                return {};
            }

            if (m_queue.size() <= max_num_items)
            {
                std::vector<T> items(m_queue.begin(), m_queue.end());
                m_queue.clear();
                return items;
            }

            std::vector<T> items(m_queue.begin(), m_queue.begin() + max_num_items);
            m_queue.erase(m_queue.begin(), m_queue.begin() + max_num_items);
            return items;
        }

    private:
        mutable std::mutex m_mutex;
        std::deque<T> m_queue;
    };
}
#endif /* __CONCURRENT_QUEUE_H__ */
