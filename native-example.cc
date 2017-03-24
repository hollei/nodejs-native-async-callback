#include <node.h>
#include <v8.h>

#include <uv.h>

v8::Persistent<v8::Function> g_onCallFunction;

struct WorkData {
   v8::Persistent<v8::Function> callback; 
};

void asyncCallback(uv_work_t *handle)
{
    // nothing to do for worker thread here in this example
}

void asyncCallbackAfter(uv_work_t *handle, int state)
{
    v8::Isolate* pIsolate = v8::Isolate::GetCurrent();
    v8::HandleScope scope(pIsolate);

    WorkData* pData = (WorkData*)handle->data;
    v8::Local<v8::Function> onCallFunction = v8::Local<v8::Function>::New(pIsolate, pData->callback);

    if (onCallFunction->IsCallable()) {
        onCallFunction->Call(pIsolate->GetCurrentContext()->Global(), 0, nullptr);
    }

    delete pData;
    delete handle;
}

void TriggerAsyncCalback(const v8::FunctionCallbackInfo<v8::Value>& args) {
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::HandleScope scope(isolate);

    WorkData* pData = new WorkData();
    pData->callback.Reset(v8::Isolate::GetCurrent(), v8::Local<v8::Function>::Cast(args[0]));

    uv_work_t *pWorker = new uv_work_t(); 
    pWorker->data = (void*)pData;

    uv_queue_work(uv_default_loop(), pWorker, asyncCallback, asyncCallbackAfter);
}

void Init(v8::Local<v8::Object> exports, v8::Local<v8::Value> module)
{
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    exports->Set(v8::String::NewFromUtf8(isolate, "TriggerAsyncCalback"),
    v8::FunctionTemplate::New(isolate, TriggerAsyncCalback)->GetFunction());
}

NODE_MODULE(nativeexample, Init)