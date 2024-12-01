/**
 * @Author: Xia Yunkai
 * @Date:   2024-06-30 21:49:59
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-06-30 21:59:17
 */
#include "document.h"
#include "component.h"

Document::Document() : m_pParent(nullptr)
{
}

Document::Document(Document &&document) : m_pParent(nullptr)
{
    m_componentMap = std::move(document.m_componentMap);
    m_components = std::move(document.m_components);

    for (auto &component : m_components)
    {
        component->m_pDocument = this;
    }

    SetParent(document.m_pParent);
    document.SetParent(nullptr);

    m_children = std::move(document.m_children);

    for (auto &child : m_children)
    {
        child->m_pParent = this;
    }
}

Document::~Document()
{
    m_components.clear();

    if (m_pParent)
    {
        m_pParent->m_children.erase(this);
    }

    for (auto &child : m_children)
    {
        child->m_pParent = nullptr;
    }
}

void Document::SetParent(Document *document)
{
    if (m_pParent)
    {
        m_pParent->m_children.erase(this);
    }

    m_pParent = document;

    if (m_pParent)
    {
        m_pParent->m_children.insert(this);
    }
}

void Document::Initialize() const
{
    for (auto &component : m_components)
    {
        if (component->m_initialized)
        {
            continue;
        }

        component->Initialize();
        component->m_initialized = true;
    }
}

void Document::Update(const float deltaTime) const
{
    for (auto &component : m_components)
    {
        component->Update(deltaTime);
    }
}
