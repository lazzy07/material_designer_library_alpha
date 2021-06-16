#include <iostream>
#include <matd/core/MaterialDesigner.hpp>
#include <matd/core/Log.hpp>
#include <matd/types/DataTypes.hpp>

int main() {
	MATD::CORE::MaterialDesigner* matd = new MATD::CORE::MaterialDesigner();
	MATD_INFO("APPLICATION::Started");
	MATD::Float* f = MATD::Argument::Float(0.3f);
	MATD::Int* i = MATD::Argument::Int(3);
	std::cout << i->GetVal();
	std::cin.get();
	delete(matd);
}