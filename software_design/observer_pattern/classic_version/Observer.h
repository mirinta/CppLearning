#pragma once

template <typename Subject, typename StateTag>
class Observer
{
public:
    virtual ~Observer() = default;

    virtual void update(const Subject& subject, StateTag property) const = 0;
};
