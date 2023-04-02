#pragma once

template <typename T>
class Path_Element
{
public:
    Path_Element() : node(T()), predecessor(nullptr) {}
    Path_Element(T node, Path_Element<T>* pred = nullptr) :
        node(node), predecessor(pred) {}

    T node;
    Path_Element<T>* predecessor;

    Path_Element<T>* get_predecessor() const
    {
        return predecessor;
    }


    ~Path_Element()
    {
        predecessor = nullptr;
    }
};