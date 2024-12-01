/**
 * @Author: Xia Yunkai
 * @Date:   2024-06-30 21:49:59
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-09-06 23:47:12
 */
#include "component.h"




Component::Component() : m_pDocument(nullptr), m_initialized(false)
{
}

Component::~Component() = default;

Document *Component::GetDocument() const
{
    return m_pDocument;
}
