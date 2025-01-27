# UThread
Threadmanage by unreal

[![UThread](https://img.youtube.com/vi/Zombenlk5VA/0.jpg)](https://www.youtube.com/watch?v=Zombenlk5VA)

-----

## ProxyManage
```c++
  UThread::GetThreadProxyMange().CreateRawNoSuspend(&ClassTarget, &Class::Function, Vars);
  UThread::GetThreadProxyMange().CreateSPNoSuspend(&SPClassTarget.ToSharedRef(), &SPClass::Function, Vars);
  UThread::GetThreadProxyMange().CreateUObjectNoSuspend(UObjectClassPointer, &UObject::Function, Vars);
  UThread::GetThreadProxyMange().CreateUFunctionNoSuspend(UFunctionClassPointer, TEXT("UFunctionClass MerberFunction Name"), Vars);
  UThread::GetThreadProxyMange().CreateLambdaNoSuspend(LambdaFunction, Vars);

  //··························································································································································

  TArray<FThreadHandle> ThreadHandleTArray;
  ThreadHandleTArray.SetNum(5);

  ThreadHandleTArray[0] = UThread::GetThreadProxyMange().CreateRawSuspend(&ClassTarget, &Class::Function, Vars);
  ThreadHandleTArray[1] = UThread::GetThreadProxyMange().CreateSPSuspend(&SPClassTarget.ToSharedRef(), &SPClass::Function, Vars);
  ThreadHandleTArray[2] = UThread::GetThreadProxyMange().CreateUObjectSuspend(UObjectClassPointer, &UObject::Function, Vars);
  ThreadHandleTArray[3] = UThread::GetThreadProxyMange().CreateUFunctionSuspend(UFunctionClassPointer, TEXT("UFunctionClass MerberFunction Name"), Vars);
  ThreadHandleTArray[4] = UThread::GetThreadProxyMange().CreateLambdaSuspend(LambdaFunction, Vars);

  for(FThreadHandle& TmpThreadHandle : ThreadHandleTArray)
	{
		UThread::GetThreadProxyMange().Detch(TmpThreadHandle);  // async
		UThread::GetThreadProxyMange().Join(TmpThreadHandle);   // sync
	}
```  
