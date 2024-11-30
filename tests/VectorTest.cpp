#include <gtest/gtest.h>
#include <matd/core/MaterialDesigner.hpp>
#include <matd/types/Structs.hpp>
#include <matd/types/MatNumber2.hpp>

TEST(VectorTest, Number2) {
    const auto matd = new MATD::CORE::MaterialDesigner();
    matd->SelectDevice(0, 0);

    MATD::Number2 num2;

    num2.x = 0.0f;
    num2.y = 1.0f;

    MATD::MatNumber2* number2 = matd->CreateNumber2(num2);
    
    EXPECT_EQ(0.0f, number2->GetVal().x);
    EXPECT_EQ(1.0f, number2->GetVal().y);
}

TEST(VectorTest, ColorVec3) {
    const auto matd = new MATD::CORE::MaterialDesigner();
    matd->SelectDevice(0, 0);

    MATD::ColorVec3 colVec3;

    colVec3.r = 255.0f;
    colVec3.g = 0.0f;
    colVec3.b = 20.0f;

    MATD::MatColorVec3* colorVector3 = matd->CreateColorVec3(colVec3);

    EXPECT_EQ(255.0f, colVec3.r);
    EXPECT_EQ(0.0f, colVec3.g);
    EXPECT_EQ(20.0f, colVec3.b);
}