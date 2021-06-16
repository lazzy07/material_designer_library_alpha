# Material Designer Library

## What is Material Designer?

Material Desgner is a procedural texture generator software that runs on all platforms using electron.

## What is Material Designer Library?

Material Designer library which is written using C++ is the engine under the hood of material designer software. Thanks to V8 bindings, using N-API material designer library has been ported to electron

### How to use?

Use this library to build material designer engine and V8 bindings, you can customize the library using your own kernels to carry out image processing. Please refer to the doc.

#### Engine functionality
Engine functionality can be used without using any graph functionality

```c++
MATD::CORE::MaterialDesigner* matd = new MATD::CORE::MaterialDesigner();
MATD::Float* f = MATD::Argument::Float(0.3f);
MATD::Int* i = MATD::Argument::Int(3);

MATD::Kernel* k = MATD::Kernel::CreateKernel("test");
MATD::WorkItem* wi = MATD::WorkItem::CreateWorkItem(k);
```