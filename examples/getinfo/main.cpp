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
	matd->SetKenelLibraryFolder("C:/Users/Lazzy07/Documents/material_designer/kernels/");
	matd->SelectDevice(0, 0);
	MATD_INFO("APPLICATION::Started");

	const size_t noOfElems = 8;

	int arr[8] = {1,2,3,4,5,6,7,8};
	int outArr[8] = {};
	int outArr2[8] = {};

	MATD::Buffer* buffer = matd->CreateBuffer(arr, noOfElems, sizeof(int), MATD::ARG_TYPE::DEVICE_READ);
	MATD::Buffer* outBuffer = matd->CreateBuffer(outArr, noOfElems, sizeof(int), MATD::ARG_TYPE::DEVICE_WRITE);
	MATD::Buffer* outBuffer2 = matd->CreateBuffer(outArr2, noOfElems, sizeof(int), MATD::ARG_TYPE::DEVICE_WRITE);
	MATD::Int* integer = matd->CreateInt(3);
	MATD::Int* integer2 = matd->CreateInt(2);

	MATD::WorkItem* wi = matd->CreateWorkItem("test");
	MATD::WorkItem* wi2 = matd->CreateWorkItem("test");

	MATD::Queue* queue1 = matd->CreateQueue();
	MATD::Queue* queue2 = matd->CreateQueue();

	wi->SetArgument(0, buffer);
	wi->SetArgument(1, integer);
	wi->SetOutput(outBuffer);
	wi->AddToQueue(queue1);

	wi2->SetArgument(0, buffer);
	wi2->SetArgument(1, integer2);
	wi2->SetOutput(outBuffer2);
	wi2->AddToQueue(queue2);

	std::cin.get();
	delete(matd);
}