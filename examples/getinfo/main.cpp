#include <iostream>
#include <matd/core/MaterialDesigner.hpp>
#include <matd/core/Log.hpp>
#include <matd/types/DataTypes.hpp>

int main() {
	MATD::CORE::MaterialDesigner* matd = new MATD::CORE::MaterialDesigner();
	MATD::Int* f = MATD::Argument::Int(3);
	
	MATD_INFO("APPLICATION::Started");
	std::cin.get();
	delete(matd);
}