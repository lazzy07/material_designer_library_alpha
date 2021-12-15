#include <napi.h>

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	exports.Set(Napi::String::New(env, "hello"), Napi::String::New(env, "Hello World"));
	return exports;
}

NODE_API_MODULE(matd, Init);