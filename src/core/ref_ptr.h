#pragma once

#include "core/scoped_ptr.h"

namespace sp
{
#if defined(NDEBUG)
    template<typename T>
    class ref_ptr
    {
    public:
        typedef std::remove_all_extents_t<T> element_type;

        ref_ptr() :ref_ptr(nullptr)
        {
        }

        ref_ptr(nullptr_t) : m_ptr(nullptr)
        {
        }

        template<typename T2, typename D>
        ref_ptr(const std::unique_ptr<T2,D>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            m_ptr = ptr.get();
        }

        template<typename T2>
        ref_ptr(const std::shared_ptr<T2>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            m_ptr = ptr.get();
        }

        template<typename T2>
        ref_ptr(const ref_ptr<T2>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            m_ptr = ptr.get();
        }

        template<typename T2, typename D>
        ref_ptr(std::unique_ptr<T2,D>&&) = delete;

        T& operator *() const
        {
            return (*get());
        }

        T* operator ->() const
        {
            return m_ptr;
        }

        explicit operator bool() const
        {
            return m_ptr != nullptr;
        }

        template<typename T2, typename D>
        bool operator ==(const std::unique_ptr<T2, D>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            return m_ptr == ptr.get();
        }

        template<typename T2>
        bool operator ==(const std::shared_ptr<T2>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            return m_ptr == ptr.get();
        }

        template<typename T2>
        bool operator ==(const sp::ref_ptr<T2>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            return m_ptr == ptr.m_ptr;
        }

        template<typename T2, typename D>
        bool operator !=(const std::unique_ptr<T2, D>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            return !(m_ptr == ptr.get());
        }

        template<typename T2>
        bool operator !=(const std::shared_ptr<T2>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            return (m_ptr == ptr.get());
        }

        template<typename T2>
        bool operator !=(const sp::ref_ptr<T2>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            return !(m_ptr == ptr.m_ptr);
        }

        template<typename T2, typename D>
        ref_ptr& operator =(const std::unique_ptr<T2,D>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            m_ptr = ptr.get();

            return *this;
        }

        template<typename T2>
        ref_ptr& operator =(const std::shared_ptr<T2>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            m_ptr = ptr.get();

            return *this;
        }

        template<typename T2>
        ref_ptr& operator =(const ref_ptr<T2>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            m_ptr = ptr.get();

            return *this;
        }

        T* get() const
        {
            return m_ptr;
        }

        ~ref_ptr()
        {
        }
    private:
        template<typename T2>
        void CheckValidDerivedType()
        {
            static_assert(std::is_base_of<T, T2>::value, "Invalid cast from T2 to T");
        }

    private:
        element_type* m_ptr;
    };
#else
    template<typename T>
    class ref_ptr
    {
    public:
        typedef std::remove_all_extents_t<T> element_type;

        ref_ptr() :ref_ptr(nullptr)
        {
        }

        ref_ptr(nullptr_t) : m_ptr(nullptr)
        {
        }

        template<typename T2, typename D>
        ref_ptr(const std::unique_ptr<T2,D>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            this->CheckValidUniquePtr(ptr);

            m_ptr = ptr.get();
            m_uniqueWeak = ptr.get_deleter().TrackingPtr;
        }

        template<typename T2>
        ref_ptr(const std::shared_ptr<T2>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            this->CheckValidSharedPtr(ptr);

            m_ptr = ptr.get();
            m_sharedWeak = ptr;
        }

        template<typename T2>
        ref_ptr(std::shared_ptr<T2>&& ptr)
        {
            this->CheckValidDerivedType<T2>();
            this->CheckValidSharedPtr(ptr);
            this->CheckSharedPtrIsAboutToExpire(ptr);

            m_ptr = ptr.get();
            m_sharedWeak = ptr;
        }

        template<typename T2>
        ref_ptr(const ref_ptr<T2>& ptr)
        {
            this->CheckValidDerivedType<T2>();

            m_ptr = ptr.get();
            m_sharedWeak = ptr.m_sharedWeak;
            m_uniqueWeak = ptr.m_uniqueWeak;
        }

        template<typename T2, typename D>
        ref_ptr(std::unique_ptr<T>&&) = delete;

        T& operator *() const
        {
            this->CheckValidPtr();

            return (*get());
        }

        T* operator ->() const
        {
            this->CheckValidPtr();

            return m_ptr;
        }

        explicit operator bool() const
        {
            return m_ptr != nullptr;
        }

        template<typename T2, typename D>
        bool operator ==(const std::unique_ptr<T2, D>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            return m_ptr == ptr.get();
        }

        template<typename T2>
        bool operator ==(const std::shared_ptr<T2>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            return m_ptr == ptr.get();
        }

        template<typename T2>
        bool operator ==(const sp::ref_ptr<T2>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            return m_ptr == ptr.m_ptr;
        }

        template<typename T2, typename D>
        bool operator !=(const std::unique_ptr<T2, D>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            return !(m_ptr == ptr.get());
        }

        template<typename T2>
        bool operator !=(const std::shared_ptr<T2>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            return (m_ptr == ptr.get());
        }

        template<typename T2>
        bool operator !=(const sp::ref_ptr<T2>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            return !(m_ptr == ptr.m_ptr);
        }

        template<typename T2, typename D>
        ref_ptr& operator =(const std::unique_ptr<T2,D>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            this->CheckValidUniquePtr(ptr);

            m_ptr = ptr.get();
            m_sharedWeak = std::weak_ptr<T>();
            m_uniqueWeak = ptr.get_deleter().TrackingPtr;

            return *this;
        }

        template<typename T2>
        ref_ptr& operator =(const std::shared_ptr<T2>& ptr)
        {
            this->CheckValidDerivedType<T2>();
            this->CheckValidSharedPtr(ptr);

            m_ptr = ptr.get();
            m_sharedWeak = ptr;

            return *this;
        }

        template<typename T2>
        ref_ptr& operator =(std::shared_ptr<T2>&& ptr)
        {
            this->CheckValidDerivedType<T2>();
            this->CheckValidSharedPtr(ptr);
            this->CheckSharedPtrIsAboutToExpire(ptr);
            
            m_ptr = ptr.get();
            m_sharedWeak = ptr;

            return *this;
        }

        template<typename T2>
        ref_ptr& operator =(const ref_ptr<T2>& ptr)
        {
            this->CheckValidDerivedType<T2>();

            m_ptr = ptr.get();
            m_sharedWeak = ptr.m_sharedWeak;
            m_uniqueWeak = ptr.m_uniqueWeak;

            return *this;
        }

        T* get() const
        {
            this->CheckValidPtr();

            return m_ptr;
        }

        ~ref_ptr()
        {
            // Do nothing here ^_^
        }

    private:
        void CheckValidPtr() const
        {
            SP_THROW_IF_FALSE(m_ptr != nullptr, "Trying to access nullptr from sp::ref_ptr is invalid !!!");
            using w = std::weak_ptr<T>;
            if (m_sharedWeak.owner_before(w{}) || w{}.owner_before(m_sharedWeak))
            {
                SP_THROW_IF_FALSE(m_sharedWeak.expired() == false, "Trying to access dangling std::shared_ptr from sp::ref_ptr is invalid !!!");
            }
            else
            {
                SP_THROW_IF_FALSE(m_uniqueWeak.expired() == false, "Trying to access dangling std::unique_ptr from sp::ref_ptr is invalid !!!");
            }
        }

        template<typename T2>
        void CheckValidSharedPtr(const std::shared_ptr<T2>& ptr)
        {
            SP_THROW_IF_FALSE(ptr.get() != nullptr, "Trying assign nullptr from std::shared_ptr to sp::ref_ptr is invalid !!!");
        }

        template<typename T2>
        void CheckSharedPtrIsAboutToExpire(const std::shared_ptr<T2>& ptr)
        {
            SP_THROW_IF_FALSE(ptr.use_count() != 1, "Trying assign pointer is about to expire from std::shared_ptr to sp::ref_ptr is invalid !!!");
        }

        template<typename T2,typename D>
        void CheckValidUniquePtr(const std::unique_ptr<T2,D>& ptr)
        {
            SP_THROW_IF_FALSE(ptr.get() != nullptr, "Trying assign nullptr from std::unique_ptr to sp::ref_ptr is invalid !!!");
        }

        template<typename T2>
        void CheckValidDerivedType()
        {
            static_assert(std::is_base_of<T, T2>::value, "Invalid cast from T2 to T, T2 must derive from T !!!");
        }

    private:
        element_type* m_ptr;
        std::weak_ptr<element_type> m_sharedWeak;
        std::weak_ptr<size_t> m_uniqueWeak;
    };
#endif
}