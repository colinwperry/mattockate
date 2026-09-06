#include <cstddef>

template <size_t Capacity>
class StackAllocator
{
private:
    alignas(std::max_align_t) std::byte buffer_[Capacity];
    size_t offset_{0};

public:
    void reset()
    {
        offset_ = 0;
    }
    void *alloc(size_t size, size_t alignment)
    {

        // calculates the aligned offset according to alignment padding
        size_t alignedOffset{offset_ + (alignment - (offset_ % alignment)) % alignment};

        // edge case for running out of memory
        if (alignedOffset + size > Capacity)
        {
            return nullptr;
        }
        else
        {
            // reassigns offset_ accordingly
            offset_ = alignedOffset;
            void *startingPoint{&buffer_[offset_]};
            offset_ += size;
            return startingPoint;
        }
    }
};