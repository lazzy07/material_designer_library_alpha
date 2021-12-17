#include <napi.h>
#include "MatdV8.hpp"

Napi::Object InitMatDV8(Napi::Env env, Napi::Object exports) {
	exports.Set(Napi::String::New(env, "MatdV8"), MATD::V8::MatdV8::GetClass(env));
	return exports;
}

NODE_API_MODULE(matd, InitMatDV8);