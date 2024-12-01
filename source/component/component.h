/**
 * @Author: Xia Yunkai
 * @Date:   2024-06-30 21:49:59
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-09-06 23:47:16
 */
#pragma once

#include "document.h"

class Document;

class Component
{
    friend class Document;

protected:
    Document* m_pDocument;
    bool m_initialized;

    template<typename T>
    T* Get()
    {
        return m_pDocument->Get<T>();
    }

public:
    Component();
    virtual ~Component();

    Document* GetDocument() const;

    virtual void Initialize() {}
    virtual void Update(float deltaTime) {}
};