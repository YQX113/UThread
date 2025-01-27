# UThread
UNREAL THREADMANAGE

[![UThread](https://img.youtube.com/vi/Zombenlk5VA/0.jpg)](https://www.youtube.com/watch?v=Zombenlk5VA)

-----

## ProxyManage
```c++
  UThread::GetThreadProxyMange().CreateRawNoSuspend(&ClassTarget, &Class::Function, Vars);						// Raw
  UThread::GetThreadProxyMange().CreateSPNoSuspend(&SPClassTarget.ToSharedRef(), &SPClass::Function, Vars);				// SP
  UThread::GetThreadProxyMange().CreateUObjectNoSuspend(UObjectClassPointer, &UObject::Function, Vars);					// UObject
  UThread::GetThreadProxyMange().CreateUFunctionNoSuspend(UFunctionClassPointer, TEXT("UFunctionClass MerberFunction Name"), Vars);	// UFunction
  UThread::GetThreadProxyMange().CreateLambdaNoSuspend(LambdaFunction, Vars);								// Lambda

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

## TaskManage
```c++
  UThread::GetThreadTaskManagement().CreateRawNoSuspend(&ClassTarget, &Class::Function, Vars);
  UThread::GetThreadTaskManagement().CreateSPNoSuspend(&SPClassTarget.ToSharedRef(), &SPClass::Function, Vars);
  UThread::GetThreadTaskManagement().CreateUObjectNoSuspend(UObjectClassPointer, &UObject::Function, Vars);
  UThread::GetThreadTaskManagement().CreateUFunctionNoSuspend(UFunctionClassPointer, TEXT("UFunctionClass MerberFunction Name"), Vars);
  UThread::GetThreadTaskManagement().CreateLambdaNoSuspend(LambdaFunction, Vars);

  //··························································································································································

  UThread::GetThreadTaskManagement().CreateRawSuspend(&ClassTarget, &Class::Function, Vars);
  UThread::GetThreadTaskManagement().CreateSPSuspend(&SPClassTarget.ToSharedRef(), &SPClass::Function, Vars);
  UThread::GetThreadTaskManagement().CreateUObjectSuspend(UObjectClassPointer, &UObject::Function, Vars);
  UThread::GetThreadTaskManagement().CreateUFunctionSuspend(UFunctionClassPointer, TEXT("UFunctionClass MerberFunction Name"), Vars);
  UThread::GetThreadTaskManagement().CreateLambdaSuspend(LambdaFunction, Vars);
```
