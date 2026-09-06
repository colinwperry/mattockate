#include <cstddef>

template <size_t Capacity>
class StackAllocator
{
    private: 
        std::byte buffer_[Capacity];
        size_t offset_ {0};
};