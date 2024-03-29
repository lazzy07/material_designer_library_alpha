# Material Designer Library

## What is Material Designer?

Material Desgner is a procedural texture generator software that runs on all platforms using electron.

## What is Material Designer Library?

Material Designer library which is written using C++ is the engine under the hood of material designer software. Thanks to V8 bindings, using N-API material designer library has been ported to electron

## How to use the library?

Use this library to build material designer engine and V8 bindings, you can customize the library using your own kernels to carry out image processing. Please refer to the doc.

### Debugging

To debug the library with electron bindings (v8 bindings using Visual Studio), select all the electron processes from Debug > Attach To Process

### Engine functionality

Engine functionality can be used without using any graph functionality

assume that the "hello.cl" file resides inside the folder C:/material_designer/kernels/ following is the implementation of hello.cl file

```c
__kernel void test(__global int* A, int B, __global int* out){
  int gid = get_global_id(0);
  out[gid] = A[gid]*B;
}
```

Once the kernel being implemented, you can use it to process data as follows

```cpp
//Create the material designer engine context
MATD::CORE::MaterialDesigner* matd = new MATD::CORE::MaterialDesigner();
//Set library folder where kernel files been loaded
matd->SetKenelLibraryFolder("C:/material_designer/kernels/");
matd->SelectDevice(0, 0);
MATD_INFO("APPLICATION::Started");

const size_t noOfElems = 8;

int arr[8] = {1,2,3,4,5,6,7,8}; // Array to be processed
int outArr[8] = {}; // where the output will be saved to

MATD::Buffer* buffer = matd->CreateBuffer(arr, noOfElems, sizeof(int), MATD::ARG_TYPE::DEVICE_READ);  //Creating Matd buffer from the array
MATD::Buffer* outBuffer = matd->CreateBuffer(outArr, noOfElems, sizeof(int), MATD::ARG_TYPE::DEVICE_WRITE); //Creating out buffer that processed data need to save to
MATD::Int* integer = matd->CreateInt(3); //Another argument which required by the kernel
MATD::WorkItem* wi = matd->CreateWorkItem("test"); // creating workitem from the kernel (test.cl)
MATD::Queue* queue = matd->CreateQueue(); //Creating a MATD queue where the workitems will be enqueued to be processed

wi->SetArgument(0, buffer); // Setting kernel arguments (Please check hello.cl)
wi->SetArgument(1, integer);
wi->SetOutput(outBuffer);
wi->AddToQueue(queue); //adding workitem to the created queue

```
