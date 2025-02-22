#pragma once

#include <memory>

#include "strategies.h"

class Shape
{
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

class Circle : public Shape
{
public:
    explicit Circle(double, std::unique_ptr<DrawStrategy<Circle>> drawer)
        : drawer(std::move(drawer))
    {
    }
    void draw() const override { drawer->draw(*this); }

private:
    std::unique_ptr<DrawStrategy<Circle>> drawer;
};

class Square : public Shape
{
public:
    explicit Square(double, std::unique_ptr<DrawStrategy<Square>> drawer)
        : drawer(std::move(drawer))
    {
    }
    void draw() const override { drawer->draw(*this); }

private:
    std::unique_ptr<DrawStrategy<Square>> drawer;
};
