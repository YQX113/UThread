# UThread
Threadmanage by unreal

-----

<iframe width="560" height="315" src="https://www.youtube.com/watch?v=Zombenlk5VA" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

## UBTMake_API
```c++
  UThread::GetThreadProxyMange().CreateRawNoSuspend(&ClassTarget, &Class::Function, Vars);
  UThread::GetThreadProxyMange().CreateSPNoSuspend(&SPClassTarget.ToSharedRef(), &SPClass::Function, Vars);
  UThread::GetThreadProxyMange().CreateUObjectNoSuspend(UObjectClassPointer, &UObject::Function, Vars);
  UThread::GetThreadProxyMange().CreateUFunctionNoSuspend(UFunctionClassPointer, TEXT("UFunctionClass MerberFunction Name"), Vars);
  UThread::GetThreadProxyMange().CreateLambdaNoSuspend(LambdaFunction, Vars);
```  
