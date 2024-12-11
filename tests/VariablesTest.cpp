#include <gtest/gtest.h>
#include <matd/core/MaterialDesigner.hpp>
#include <matd/types/Int.hpp>
#include <matd/types/Float.hpp>

TEST(VariablesTest, CreatingIntVariable0) {
    const auto matd = new MATD::CORE::MaterialDesigner();
    matd->SelectDevice(0, 0);

    MATD::Int* integer0 = matd->CreateInt(0);
    EXPECT_EQ(0, integer0->GetVal());
}

TEST(VariablesTest, CreatingIntVariableMax) {
    const auto matd = new MATD::CORE::MaterialDesigner();
    matd->SelectDevice(0, 0);

    MATD::Int* integerMax = matd->CreateInt(std::numeric_limits<int>::max());
    EXPECT_EQ(std::numeric_limits<int>::max(), integerMax->GetVal());
}

TEST(VariablesTest, CreatingIntVariableMin) {
    const auto matd = new MATD::CORE::MaterialDesigner();
    matd->SelectDevice(0, 0);

    MATD::Int* integerMin = matd->CreateInt(std::numeric_limits<int>::min());
    EXPECT_EQ(std::numeric_limits<int>::min(), integerMin->GetVal());
}

TEST(VariableTest, CreatingVariableFloat0) {
    const auto matd = new MATD::CORE::MaterialDesigner();
    matd->SelectDevice(0, 0);
    
    MATD::Float* float0 = matd->CreateFloat(0.0f);

    EXPECT_NEAR(0.0f, float0->GetVal(), 0.0001f);
}

TEST(VariableTest, CreatingVariableFloatMax) {
    const auto matd = new MATD::CORE::MaterialDesigner();
    matd->SelectDevice(0, 0);

    MATD::Float* floatMin = matd->CreateFloat(std::numeric_limits<float>::min());

    EXPECT_NEAR(std::numeric_limits<float>::min(), floatMin->GetVal(), 0.0001f);
}