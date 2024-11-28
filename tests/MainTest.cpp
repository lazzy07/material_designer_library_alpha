#include <gtest/gtest.h>
#include <matd/core/MaterialDesigner.hpp>

#ifndef IS_TESTING
    #define IS_TESTING
#endif

TEST(MainTest, IsSelectedPlatformAndDeviceCorrect) {
    const auto matd = new MATD::CORE::MaterialDesigner();

    std::vector<size_t> selectedPlatformAndDevice = matd->SelectDevice(0, 0);

    EXPECT_EQ(0, selectedPlatformAndDevice.at(0));

    EXPECT_EQ(0, selectedPlatformAndDevice.at(1));
}