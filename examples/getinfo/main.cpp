#include <iostream>
#include <matd/core/MaterialDesigner.hpp>
#include <matd/core/Log.hpp>
#include <matd/types/DataTypes.hpp>
#include <matd/engine/WorkItem.hpp>
#include <matd/engine/Kernel.hpp>

int main() {
	////Create the material designer engine context
	//MATD::CORE::MaterialDesigner* matd = new MATD::CORE::MaterialDesigner();
	////Set library folder where kernel files been loaded
	//matd->SetKenelLibraryFolder("C:/Users/Lazzy07/Documents/material_designer/kernels/");
	//matd->SelectDevice(0, 0);
	//auto data = MATD::CORE::EngineManager::GetSupportedEngines();

	//MATD_INFO("APPLICATION::Started");

	//const size_t noOfElems = 8;

	//int arr[8] = {1,2,3,4,5,6,7,8};
	//int outArr[8] = {};

	//MATD::Buffer* buffer = matd->CreateBuffer(arr, noOfElems, sizeof(int), MATD::ARG_TYPE::DEVICE_READ);
	//MATD::Buffer* outBuffer = matd->CreateBuffer(outArr, noOfElems, sizeof(int), MATD::ARG_TYPE::DEVICE_WRITE);
	//MATD::Int* integer = matd->CreateInt(3);
	//
	//MATD::WorkItem* wi = matd->CreateWorkItem("test");
	//
	//MATD::Queue* queue = matd->CreateQueue();

	//wi->SetArgument(0, buffer);
	//wi->SetArgument(1, integer);
	//wi->SetOutput(outBuffer);
	//wi->AddToQueue(queue);

	//std::cin.get();

	MATD::CORE::MaterialDesigner* matd = new MATD::CORE::MaterialDesigner();

	matd->OpenProject("{\"id\":\"5d86f3a4-c204-43eb-90c1-dcd639dc9a27\",\"filePath\":\"\",\"fileName\":\"Untitled\",\"packages\":[],\"preview\":{\"shape\":\"cube\",\"subdivision\":100,\"wireframe\":false,\"exposure\":1},\"description\":\"\",\"textures\":[],\"isCloud\":false,\"isLocal\":true,\"createdAt\":1642745665712,\"modifiedAt\":1642745665713,\"savedAt\":1642745665713}");
	matd->UpdateProject("{\"id\":\"50241c2e-0c3c-4cb3-ab8c-bc78db8f0a9b\",\"filePath\":\"\",\"fileName\":\"Untitled\",\"packages\":[{\"id\":\"5bbc896c-1c61-4ca8-b12d-a62f31e60080\",\"contentType\":\"graph\",\"name\":\"Untitled\",\"children\":[],\"type\":\"dataGraph\",\"createdAt\":\"2022-01-21T06:05:27.021Z\",\"dataGraph\":{\"id\":\"952d7098-b6c4-4af5-9187-c7b50872b848\",\"data\":{\"id\":\"materialdesigner@0.0.1\",\"nodes\":{}},\"parentId\":\"5bbc896c-1c61-4ca8-b12d-a62f31e60080\",\"createdAt\":\"2022-01-21T06:05:27.021Z\"},\"kernelGraph\":{\"id\":\"f68dff71-fb45-4299-a725-8b513fc438e6\",\"data\":{\"id\":\"materialdesigner@0.0.1\",\"nodes\":{}},\"parentId\":\"5bbc896c-1c61-4ca8-b12d-a62f31e60080\",\"createdAt\":\"2022-01-21T06:05:27.021Z\"},\"shaderGraph\":{\"id\":\"b9c3776b-cae5-4f52-873c-7876146ccb06\",\"data\":{\"id\":\"materialdesigner0.0.1\",\"nodes\":{}},\"parentId\":\"5bbc896c-1c61-4ca8-b12d-a62f31e60080\",\"createdAt\":\"2022-01-21T06:05:27.021Z\"}}],\"preview\":{\"shape\":\"cube\",\"subdivision\":100,\"wireframe\":false,\"exposure\":1},\"description\":\"\",\"textures\":[],\"isCloud\":false,\"isLocal\":true,\"createdAt\":1642744811202,\"modifiedAt\":1642744811202,\"savedAt\":1642744811202}");
	matd->SetSelectedGraph("{ \"id\": \"5bbc896c-1c61-4ca8-b12d-a62f31e60080\", \"type\":\"dataGraph\"}");
	matd->CreateNode("{\"id\":1,\"data\":{\"id\":\"1\",\"name\":\"Number1 Input\",\"type\":\"dataGraph\",\"contentType\":\"graph\",\"children\":[],\"dataGraph\":{\"id\":\"11\",\"data\":[{\"id\":\"111\",\"name\":\"Default Value\",\"data\":0,\"dataType\":\"number\",\"groups\":{\"id\":\"1111\",\"name\":\"Default\"},\"inputType\":\"input\",\"type\":\"\"}],\"parentId\":\"1\",\"ioType\":\"generator\",\"operationType\":\"\"}},\"inputs\":{},\"outputs\":{\"out\":{\"connections\":[]}},\"position\":[500337.2000732422,500332.81872558594],\"name\":\"Number1 Input\"}");
	matd->CreateNode("{\"id\":2,\"data\":{\"id\":\"14\",\"name\":\"Add Number\",\"type\":\"dataGraph\",\"contentType\":\"graph\",\"children\":[],\"dataGraph\":{\"id\":\"141\",\"data\":[{\"id\":\"1411\",\"name\":\"Default Value 1\",\"data\":2,\"dataType\":\"number\",\"groups\":{\"id\":\"14111\",\"name\":\"Default\"},\"inputType\":\"input_and_slider\",\"type\":\"\"},{\"id\":\"1412\",\"name\":\"Default Value 2\",\"data\":2,\"dataType\":\"number\",\"groups\":{\"id\":\"14111\",\"name\":\"Default\"},\"inputType\":\"input_and_slider\",\"type\":\"\"}],\"parentId\":\"14\",\"ioType\":\"process\",\"operationType\":\"\"}},\"inputs\":{\"1\":{\"connections\":[]},\"2\":{\"connections\":[]}},\"outputs\":{\"out\":{\"connections\":[]}},\"position\":[500337.2000732422,500332.81872558594],\"name\":\"Add Number\"}\n");

	matd->AddConnection("{\"data\":{},\"id\":\"588d757a-4797-4c7e-aed0-7a1978428d86\",\"output\":{\"connections\":[{\"node\":2,\"input\":\"1\",\"data\":{},\"id\":\"588d757a-4797-4c7e-aed0-7a1978428d86\"}]},\"input\":{\"connections\":[{\"node\":1,\"output\":\"out\",\"data\":{},\"id\":\"588d757a-4797-4c7e-aed0-7a1978428d86\"}]}}");
	matd->RemoveConnection("{\"data\":{},\"id\":\"588d757a-4797-4c7e-aed0-7a1978428d86\",\"output\":{\"connections\":[]},\"input\":{\"connections\":[]}}");
	matd->AddConnection("{\"data\":{},\"id\":\"3ff480c1-ad58-46e6-96c3-84fc8b3c0178\",\"output\":{\"connections\":[{\"node\":2,\"input\":\"1\",\"data\":{},\"id\":\"3ff480c1-ad58-46e6-96c3-84fc8b3c0178\"}]},\"input\":{\"connections\":[{\"node\":1,\"output\":\"out\",\"data\":{},\"id\":\"3ff480c1-ad58-46e6-96c3-84fc8b3c0178\"}]}}");

	delete(matd);
}