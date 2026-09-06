# mattockate

A small C++ stack-style allocator for fast, manual memory management from a fixed-size buffer.

## What It Does

`StackAllocator<Capacity>` stores `Capacity` bytes internally and hands out aligned memory blocks in allocation order. When the buffer is full, `alloc` returns `nullptr`.

## Purpose

It is useful when you need simple, predictable allocations with no per-allocation deallocation overhead. All allocated memory can be reclaimed at once with `reset()`.