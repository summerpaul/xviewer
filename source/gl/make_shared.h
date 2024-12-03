/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-02 13:16:00
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-02 13:16:41
 */

#ifndef __MAKE_SHARED_H__
#define __MAKE_SHARED_H__

#include <memory>
#include <type_traits>
#include <Eigen/Core>

namespace xviewer::gl
{
    template <typename...>
    using void_t = void;

    template <typename, typename = void_t<>>
    struct needs_aligned_allocator : std::false_type
    {
    };

    template <typename T>
    struct needs_aligned_allocator<T, void_t<typename T::eigen_aligned_operator_new_marker_type>> : std::true_type
    {
    };

    template <typename T, typename... Args>
    std::enable_if_t<needs_aligned_allocator<T>::value, std::shared_ptr<T>> make_shared(Args &&...args)
    {
        return std::allocate_shared<T>(Eigen::aligned_allocator<T>(), std::forward<Args>(args)...);
    }

    template <typename T, typename... Args>
    std::enable_if_t<!needs_aligned_allocator<T>::value, std::shared_ptr<T>> make_shared(Args &&...args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}

#endif /* __MAKE_SHARED_H__ */
