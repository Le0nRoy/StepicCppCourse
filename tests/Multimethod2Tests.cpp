//
// Created by lap on 10/16/20.
//

#include "gtest/gtest.h"
#include "headers/Multimethod2.h"

#define SUITE_NAME Multimethod2Tests

// базовый класс фигуры (полиморфный)
struct Shape {
    virtual int square() = 0;
};

// прямоугольник
struct Rectangle : Shape {
    int square() override {
        return 0;
    }
};

// треугольник
struct Triangle : Shape {
    int square() override {
        return 1;
    }
};

// функция для проверки пересечения двух прямоугольников
bool is_intersect_r_r(Shape *a, Shape *b) {
    int res = a->square() + b->square();
    if (res == 0) {
        return true;
    }
    else {
        return false;
    }
}

// функция для проверки пересечения прямоугольника и треугольника
bool is_intersect_r_t(Shape *a, Shape *b) {
    int res = a->square() + b->square();
    if (res == 1 && a->square() == 0) {
        return true;
    }
    else {
        return false;
    }
}

// функция для проверки пересечения треугольника и прямоугольника
bool is_intersect_t_r(Shape *a, Shape *b) {
    int res = a->square() + b->square();
    if (res == 1 && a->square() == 1) {
        return true;
    }
    else {
        return false;
    }
}

// функция для проверки пересечения треугольника и треугольника
bool is_intersect_t_t(Shape *a, Shape *b) {
    int res = a->square() + b->square();
    if (res == 2) {
        return true;
    }
    else {
        return false;
    }
}

TEST(SUITE_NAME, MultimethodCommutativeTest) {
    Multimethod2<Shape, bool, true> is_intersect;
    Shape *pTriangle = new Triangle();
    Shape *pRectangle = new Rectangle();

    is_intersect.addImpl(typeid(Rectangle), typeid(Rectangle), is_intersect_r_r);
    is_intersect.addImpl(typeid(Rectangle), typeid(Triangle), is_intersect_r_t);
    is_intersect.addImpl(typeid(Rectangle), typeid(Triangle), is_intersect_r_t);

    EXPECT_TRUE(is_intersect.hasImpl(pTriangle, pRectangle));
    EXPECT_TRUE(is_intersect.hasImpl(pRectangle, pTriangle));
    EXPECT_TRUE(is_intersect.hasImpl(pRectangle, pRectangle));
    EXPECT_FALSE(is_intersect.hasImpl(pTriangle, pTriangle));

    ASSERT_NO_THROW(is_intersect.call(pTriangle, pRectangle));
    ASSERT_NO_THROW(is_intersect.call(pRectangle, pTriangle));
    ASSERT_NO_THROW(is_intersect.call(pRectangle, pRectangle));
    ASSERT_ANY_THROW(is_intersect.call(pTriangle, pTriangle));

    EXPECT_TRUE(is_intersect.call(pTriangle, pRectangle));
    EXPECT_TRUE(is_intersect.call(pRectangle, pTriangle));
    EXPECT_TRUE(is_intersect.call(pRectangle, pRectangle));
//    EXPECT_FALSE(is_intersect.call(pTriangle, pTriangle));

    is_intersect.addImpl(typeid(Triangle), typeid(Rectangle), is_intersect_t_r);
    EXPECT_TRUE(is_intersect.hasImpl(pTriangle, pRectangle));
    ASSERT_NO_THROW(is_intersect.call(pTriangle, pRectangle));
    EXPECT_TRUE(is_intersect.call(pTriangle, pRectangle));
}

TEST(SUITE_NAME, MultimethodNonCommutativeTest) {
    Multimethod2<Shape, bool, false> is_intersect;
    Shape *pTriangle = new Triangle();
    Shape *pRectangle = new Rectangle();

    is_intersect.addImpl(typeid(Rectangle), typeid(Rectangle), is_intersect_r_r);
    is_intersect.addImpl(typeid(Rectangle), typeid(Triangle), is_intersect_r_t);

    EXPECT_FALSE(is_intersect.hasImpl(pTriangle, pRectangle));
    EXPECT_TRUE(is_intersect.hasImpl(pRectangle, pTriangle));
    EXPECT_TRUE(is_intersect.hasImpl(pRectangle, pRectangle));
    EXPECT_FALSE(is_intersect.hasImpl(pTriangle, pTriangle));

    ASSERT_ANY_THROW(is_intersect.call(pTriangle, pRectangle));
    ASSERT_NO_THROW(is_intersect.call(pRectangle, pTriangle));
    ASSERT_NO_THROW(is_intersect.call(pRectangle, pRectangle));
    ASSERT_ANY_THROW(is_intersect.call(pTriangle, pTriangle));

//    EXPECT_FALSE(is_intersect.call(pTriangle, pRectangle));
    EXPECT_TRUE(is_intersect.call(pRectangle, pTriangle));
    EXPECT_TRUE(is_intersect.call(pRectangle, pRectangle));
//    EXPECT_FALSE(is_intersect.call(pTriangle, pTriangle));

    is_intersect.addImpl(typeid(Triangle), typeid(Rectangle), is_intersect_t_r);
    EXPECT_TRUE(is_intersect.hasImpl(pTriangle, pRectangle));
    ASSERT_NO_THROW(is_intersect.call(pTriangle, pRectangle));
    EXPECT_TRUE(is_intersect.call(pTriangle, pRectangle));
}
