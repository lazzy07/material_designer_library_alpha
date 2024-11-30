#include <gtest/gtest.h>
#include <matd/core/MaterialDesigner.hpp>
#include <matd/types/GrayscaleTexture.hpp>
#include <matd/types/ColorTexture.hpp>

TEST(TextureTest, ColorTexture) {
    const auto matd = new MATD::CORE::MaterialDesigner();
    matd->SelectDevice(0, 0);

    MATD::ColorTexture* texColor = matd->CreateColorTexture(MATD::MATD_TEXTURE_BIT_TYPE::TEX_8BIT, 10, 10);
    //Textures have 4 channels, RGBA
    EXPECT_EQ(10*10*8*4, texColor->GetByteSize());
}

TEST(TextureTest, GrayscaleTexture) {
    const auto matd = new MATD::CORE::MaterialDesigner();
    matd->SelectDevice(0, 0);

    MATD::GrayscaleTexture* texGrayscale = matd->CreateGrayscaleTexture(MATD::MATD_TEXTURE_BIT_TYPE::TEX_8BIT, 10, 10);

    EXPECT_EQ(10 * 10 * 8, texGrayscale->GetByteSize());
}
