#include <iostream>
#include <matd/core/MaterialDesigner.hpp>
#include <matd/core/Log.hpp>

int main() {
	MATD::CORE::MaterialDesigner* matd = new MATD::CORE::MaterialDesigner();

	std::cin.get();

	free(matd);
}