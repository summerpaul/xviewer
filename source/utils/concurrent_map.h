/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-03 13:20:57
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 13:36:41
 */

#ifndef __CONCURRENT_MAP_H__
#define __CONCURRENT_MAP_H__
#include <map>
#include <mutex>
#include <vector>

namespace xviewer::utils
{
    template <typename Key, typename Value>
    class ConcurrentMap
    {
    public:
        using MapType = std::map<Key, Value>;
        using IteratorType = typename MapType::iterator;
        ConcurrentMap() {}
        ~ConcurrentMap() {}
        // 拷贝构造函数
        ConcurrentMap(const ConcurrentMap &other)
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            m_map = other.m_map;
        }

        void UpdateMapData(const MapType &data)
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            m_map = data;
        }

        Value &operator[](const Key &key)
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            return m_map[key];
        }

        Value &at(const Key &key)
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            return m_map.at(key);
        }

        bool HasElements() const
        {
            bool hasElements;
            std::lock_guard<std::mutex> lock(m_mutex);
            hasElements = (m_map.size() > 0);
            return hasElements;
        }

        bool Exists(const Key &key) const
        {
            bool exists;
            std::lock_guard<std::mutex> lock(m_mutex);

            exists = (m_map.find(key) != m_map.end());

            return exists;
        }

        void Insert(const Key &key, const Value &value)
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            m_map[key] = value;
        }

        bool Remove(const Key &key, Value &value)
        {
            bool exists;
            std::lock_guard<std::mutex> lock(m_mutex);
            auto iter = m_map.find(key);
            if (iter != m_map.end())
            {
                value = iter->second;
                m_map.erase(iter);
                exists = true;
            }
            else
            {
                exists = false;
            }
            return exists;
        }

        void RemoveAll()
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            m_map.clear();
        }

        void Lock() const
        {
            m_mutex.lock();
        }

        void Unlock() const
        {
            m_mutex.unlock();
        }

        void clear()
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            m_map.clear();
        }

        bool Get(const Key &key, Value &value) const
        {
            bool exists;
            std::lock_guard<std::mutex> lock(m_mutex);

            auto iter = m_map.find(key);
            if (iter != m_map.end())
            {
                value = iter->second;
                exists = true;
            }
            else
            {
                exists = false;
            }

            return exists;
        }

        void GatherKeyAll(std::vector<Key> &keys) const
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            if (m_map.size() > 0)
            {
                keys.resize(m_map.size());
                auto kiter = keys.begin();
                for (auto const &m : m_map)
                {
                    *kiter++ = m.first;
                }
            }
            else
            {
                keys.clear();
            }
        }

        std::vector<Key> GetAllKey() const
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            std::vector<Key> keys;
            if (m_map.size() > 0)
            {
                keys.resize(m_map.size());
                auto kiter = keys.begin();
                for (auto const &m : m_map)
                {
                    *kiter++ = m.first;
                }
            }
            else
            {
                keys.clear();
            }
            return keys;
        }

        std::vector<Value> GetAllValue() const
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            std::vector<Value> values;
            if (m_map.size() > 0)
            {
                values.resize(m_map.size());
                auto viter = values.begin();
                for (auto const &m : m_map)
                {
                    *viter++ = m.second;
                }
            }
            else
            {
                values.clear();
            }
            return values;
        }

        void GatherValueAll(std::vector<Value> &values) const
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            if (m_map.size() > 0)
            {
                values.resize(m_map.size());
                auto viter = values.begin();
                for (auto const &m : m_map)
                {
                    *viter++ = m.second;
                }
            }
            else
            {
                values.clear();
            }
        }

        IteratorType begin()
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            return m_map.begin();
        }

        IteratorType end()
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            return m_map.end();
        }

        bool empty() const
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            bool ret = m_map.empty();
            return ret;
        }

        size_t size() const
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            return m_map.size();
        }

    protected:
        std::map<Key, Value> m_map;
        mutable std::mutex m_mutex;
    };
}

#endif /* __CONCURRENT_MAP_H__ */
