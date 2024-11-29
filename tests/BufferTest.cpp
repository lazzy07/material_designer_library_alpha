#include <gtest/gtest.h>
#include <matd/core/MaterialDesigner.hpp>
#include <matd/types/Buffer.hpp>

TEST(BufferTest, CreateBuffer) {
    const auto matd = new MATD::CORE::MaterialDesigner();
    matd->SelectDevice(0, 0);

    MATD::Buffer* buffer = matd->CreateBuffer(nullptr, 10, 4);

    EXPECT_EQ(40, buffer->GetByteSize());
}