/**
 * @Author: Xia Yunkai
 * @Date:   2024-06-30 21:43:48
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-06-30 21:58:01
 */
#pragma once

#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <memory>
class Component;

template <typename T>
class ComponentTypeId
{
protected:
    static inline uint8_t m_dummy;

public:
    static uintptr_t Get()
    {
        return (uintptr_t)&m_dummy;
    }
};

class Document
{
protected:
    std::unordered_map<uintptr_t, Component *> m_componentMap;
    std::vector<std::unique_ptr<Component>> m_components;
    Document *m_pParent;
    std::unordered_set<Document *> m_children;

    template <typename T>
    T *Get(Document *prev)
    {
        T *component = static_cast<T *>(m_componentMap[ComponentTypeId<T>::Get()]);
        if (component)
        {
            if (!component->m_initialized)
            {
                component->Initialize();
                component->m_initialized = true;
            }
        }
        else
        {
            for (auto &document : m_children)
            {
                if (document == prev)
                {
                    continue;
                }

                component = document->Get<T>(this);
                if (component)
                {
                    return component;
                }
            }

            if (m_pParent && m_pParent != prev)
            {
                component = m_pParent->Get<T>(this);
            }
        }

        return component;
    }

public:
    Document();
    Document(const Document &document) = delete;
    Document(Document &&document);
    ~Document();

    template <typename T>
    void Add(std::unique_ptr<T> &&component)
    {
        component->m_pDocument = this;
        m_componentMap[ComponentTypeId<T>::Get()] = component.get();
        m_components.push_back(std::move(component));
    }

    template <typename T>
    T *Get()
    {
        return Get<T>(nullptr);
    }

    void SetParent(Document *document);

    void Initialize() const;

    void Update(float deltaTime) const;
};
