#include <iostream>
#include <matd/core/MaterialDesigner.hpp>
#include <matd/core/Log.hpp>
#include <matd/types/DataTypes.hpp>
#include <matd/engine/WorkItem.hpp>
#include <matd/engine/Kernel.hpp>

int main() {
	MATD::CORE::MaterialDesigner* matd = new MATD::CORE::MaterialDesigner();
	auto e = MATD::CORE::EngineManager::GetEngineInstance();
	e->SelectPlatform(0);
	e->SelectDevice(0);

	MATD_INFO("APPLICATION::Started");
	int arr[] = { 1,2,3,4,5,6,7,8 };
	MATD::Buffer<int>* buf = MATD::Argument::Buffer<int>(arr, 8);
	MATD::Int* i = MATD::Argument::Int(3);

	MATD::Kernel* k = MATD::Kernel::CreateKernelFromFile("test", "C:/Users/Lazzy07/Documents/material_designer/kernels/test.cl");
	MATD::WorkItem* wi = MATD::WorkItem::CreateWorkItem(k);
	wi->SetArgument(0, buf);
	wi->SetArgument(1, i);

	std::cin.get();
	delete(matd);
}