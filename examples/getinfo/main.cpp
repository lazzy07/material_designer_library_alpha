#include <iostream>
#include <matd/core/MaterialDesigner.hpp>
#include <matd/core/Log.hpp>
#include <matd/types/DataTypes.hpp>
#include <matd/engine/WorkItem.hpp>
#include <matd/engine/Kernel.hpp>

int main() {
	//Create the material designer engine
	MATD::CORE::MaterialDesigner* matd = new MATD::CORE::MaterialDesigner();
	auto e = MATD::CORE::EngineManager::GetEngineInstance();
	e->SelectPlatform(0);
	e->SelectDevice(0);

	MATD_INFO("APPLICATION::Started");
	const size_t noOfElems = 8;

	int arr[8] = {1,2,3,4,5,6,7,8};
	int outArr[8] = {};

	int arr2[8] = { 2,4,8,16,32,64,128,256 };
	int outArr2[8] = {};

	MATD::Buffer* buffer = MATD::Argument::Buffer(arr, noOfElems, sizeof(int), MATD::ARG_TYPE::DEVICE_READ);
	MATD::Buffer* outBuffer = MATD::Argument::Buffer(outArr, noOfElems, sizeof(int), MATD::ARG_TYPE::DEVICE_WRITE);
	MATD::Int* integer = MATD::Argument::Int(3);

	MATD::Kernel* kernel = MATD::Kernel::CreateKernelFromFile("test", "C:/Users/Lazzy07/Documents/material_designer/kernels/test.cl");
	MATD::WorkItem* wi = MATD::WorkItem::CreateWorkItem(kernel);

	wi->SetArgument(0, buffer);
	wi->SetArgument(1, integer);
	wi->OnComplete();
	wi->SetOutput(outBuffer);
	wi->AddToQueue();

	std::cin.get();
	delete(matd);
}