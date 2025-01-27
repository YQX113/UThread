# UThread
Threadmanage by unreal

-----

[UThread](https://www.youtube.com/watch?v=dQw4w9WgXcQ)

## UBTMake_API
```c++
  UThread::GetThreadProxyMange().CreateRawNoSuspend(&ClassTarget, &Class::Function, Vars);
  UThread::GetThreadProxyMange().CreateSPNoSuspend(&SPClassTarget.ToSharedRef(), &SPClass::Function, Vars);
  UThread::GetThreadProxyMange().CreateUObjectNoSuspend(UObjectClassPointer, &UObject::Function, Vars);
  UThread::GetThreadProxyMange().CreateUFunctionNoSuspend(UFunctionClassPointer, TEXT("UFunctionClass MerberFunction Name"), Vars);
  UThread::GetThreadProxyMange().CreateLambdaNoSuspend(LambdaFunction, Vars);
```  
