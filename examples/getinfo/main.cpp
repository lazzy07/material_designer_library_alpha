#include <iostream>
#include <matd/core/MaterialDesigner.hpp>
#include <matd/core/Log.hpp>
#include <matd/types/DataTypes.hpp>
#include <matd/engine/WorkItem.hpp>
#include <matd/engine/Kernel.hpp>

int main() {
	//Create the material designer engine context
	MATD::CORE::MaterialDesigner* matd = new MATD::CORE::MaterialDesigner();
	//Set library folder where kernel files been loaded
	matd->SelectDevice(0, 0);
	
	MATD_INFO("APPLICATION::Started");
	MATD::ColorTexture* ct = matd->CreateColorTexture(MATD::MATD_TEXTURE_BIT_TYPE::TEX_8BIT, 10, 10, MATD::ARG_TYPE::DEVICE_READ_WRITE);
	MATD::ColorTexture* out = matd->CreateColorTexture(MATD::MATD_TEXTURE_BIT_TYPE::TEX_8BIT, 10, 10, MATD::ARG_TYPE::DEVICE_READ_WRITE);
	std::string error;

	

	std::string kernelStr = R""""(
		__kernel void kernel_hello(read_only image2d_t empg,
                         write_only image2d_t ejpg){
		size_t x = get_global_id(0);
		size_t y = get_global_id(1);

		uint4 d;
		d.x = 0;
		d.y = 0;
		d.z = 0;

		write_imageui(ejpg,(int2)(x,y), d);
	}
	)"""";

	MATD::Kernel* kernel = MATD::Kernel::CreateKernelFromSource("hello", kernelStr, &error);
	MATD::WorkItem* wi = matd->CreateWorkItem(kernel);
	MATD::Queue* queue = matd->CreateQueue();
	
	wi->SetArgument(0, (MATD::DTYPES::Argument*)ct);
	wi->SetOutput(1, (MATD::DTYPES::Argument*)out);
	wi->AddToQueue(queue);
}