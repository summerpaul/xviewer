/**
 * @Author: Xia Yunkai
 * @Date:   2024-06-29 15:07:19
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 13:31:20
 */
#ifndef __THREAD_H__
#define __THREAD_H__
#include <functional>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <limits>
#include <cassert>
#include <string>

namespace xviewer::utils
{
    class Thread
    {
    public:
        typedef std::function<void(void *arg)> ThreadFuncCallback;

        enum Status
        {
            kRunning = 1,
            kSuspend = 2,
            kStopping = 3,
            kStopped = 4,
        };

    public:
        Thread() : m_status(kStopped)
        {
        }

        Thread(const ThreadFuncCallback &cb) : m_threadCallback(cb),
                                               m_status(kStopped)
        {
        }

        ~Thread()
        {
            if (kStopped != m_status)
            {
                stop();
            }
        }

        bool assignTask(const ThreadFuncCallback &cb)
        {
            std::lock_guard<std::mutex> lock(m_mtx);

            assert(kStopped == m_status);

            m_threadCallback = cb;

            return true;
        }

        bool start()
        {
            std::lock_guard<std::mutex> lock(m_mtx);

            assert(kStopped == m_status);

            m_thread = std::thread(m_threadCallback, this);

            m_status = kRunning;

            return true;
        }

        void stop()
        {
            {
                std::unique_lock<std::mutex> lock(m_mtx);

                assert(kRunning == m_status || kSuspend == m_status);

                if (kSuspend == m_status)
                {
                    m_cond.notify_all();
                }

                m_status = kStopping;

                lock.unlock();
            }

            if (m_thread.joinable())
            {
                m_thread.join();

                if ((kStopping == m_status))
                {
                    m_status = kStopped;
                }
            }
        }

        bool suspend()
        {
            std::lock_guard<std::mutex> lock(m_mtx);

            assert(kRunning == m_status);

            m_status = kSuspend;

            return true;
        }

        bool resume()
        {
            std::unique_lock<std::mutex> lock(m_mtx);

            assert(kSuspend == m_status);

            m_status = kRunning;
            m_cond.notify_all();

            return true;
        }
        bool isExiting(unsigned long long timeouts = 0)
        {
            std::unique_lock<std::mutex> lock(m_mtx);

            bool isExiting = false;

            switch (m_status)
            {
            case kRunning:
                lock.unlock();

                if (timeouts > 0)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(timeouts));
                    if (kStopping == m_status)
                    {
                        m_status = kStopped;

                        isExiting = true;
                    }
                }
                break;
            case kSuspend:
            {
                m_cond.wait(lock, [&]() -> bool
                            { return (kRunning == m_status) || (kStopping == m_status); });
                if (kStopping == m_status)
                {
                    m_status = kStopped;

                    isExiting = true;
                }
            }
            break;
            case kStopping:
            {
                m_status = kStopped;

                isExiting = true;
            }
            break;
            case kStopped:
            {
                isExiting = true;
            }
            break;
            default:
                isExiting = true;
                break;
            }

            return isExiting;
        }

        void sleep(unsigned long long timeouts = 0)
        {
            if (timeouts > 0)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(timeouts));
            }
        }

        void setCallbackName(std::string name)
        {
            m_cbName = name;
        }

    private:
        ThreadFuncCallback m_threadCallback;

        std::thread m_thread;

        std::condition_variable m_cond;

        std::mutex m_mtx;

        Status m_status;

        std::string m_cbName;
    };
}
#endif /* __THREAD_H__ */
