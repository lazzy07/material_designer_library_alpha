#include <iostream>
#include <matd/core/MaterialDesigner.hpp>
#include <matd/core/Log.hpp>
#include <matd/types/DataTypes.hpp>
#include <matd/engine/WorkItem.hpp>
#include <matd/engine/Kernel.hpp>

int main() {
	MATD::CORE::MaterialDesigner* matd = new MATD::CORE::MaterialDesigner();
	MATD_INFO("APPLICATION::Started");
	MATD::Float* f = MATD::Argument::Float(0.3f);
	MATD::Int* i = MATD::Argument::Int(3);

	MATD::Kernel* k = MATD::Kernel::CreateKernel("test");
	MATD::WorkItem* wi = MATD::WorkItem::CreateWorkItem(k);
	std::cin.get();
	delete(matd);
}