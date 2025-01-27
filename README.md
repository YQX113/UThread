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

## Abandonable
```c++
  UThread::GetThreadAbandonableManage().CreateRawNoSuspend(&ClassTarget, &Class::Function, Vars);
  UThread::GetThreadAbandonableManage().CreateSPNoSuspend(&SPClassTarget.ToSharedRef(), &SPClass::Function, Vars);
  UThread::GetThreadAbandonableManage().CreateUObjectNoSuspend(UObjectClassPointer, &UObject::Function, Vars);
  UThread::GetThreadAbandonableManage().CreateUFunctionNoSuspend(UFunctionClassPointer, TEXT("UFunctionClass MerberFunction Name"), Vars);
  UThread::GetThreadAbandonableManage().CreateLambdaNoSuspend(LambdaFunction, Vars);

  ASYNCTASK_Raw(&ClassTarget, &Class::Function, Vars)
  ASYNCTASK_SP(&SPClassTarget.ToSharedRef(), &SPClass::Function, Vars)
  ASYNCTASK_UOBJECT(UObjectClassPointer, &UObject::Function, Vars)
  ASYNCTASK_UFunction(UFunctionClassPointer, TEXT("UFunctionClass MerberFunction Name"), Vars)
  ASYNCTASK_Lambda(LambdaFunction, Vars)

  //··························································································································································

  UThread::GetThreadAbandonableManage().CreateRawSuspend(&ClassTarget, &Class::Function, Vars);
  UThread::GetThreadAbandonableManage().CreateSPSuspend(&SPClassTarget.ToSharedRef(), &SPClass::Function, Vars);
  UThread::GetThreadAbandonableManage().CreateUObjectSuspend(UObjectClassPointer, &UObject::Function, Vars);
  UThread::GetThreadAbandonableManage().CreateUFunctionSuspend(UFunctionClassPointer, TEXT("UFunctionClass MerberFunction Name"), Vars);
  UThread::GetThreadAbandonableManage().CreateLambdaSuspend(LambdaFunction, Vars);

  SYNCTASK_Raw(&ClassTarget, &Class::Function, Vars)
  SYNCTASK_SP(&SPClassTarget.ToSharedRef(), &SPClass::Function, Vars)
  SYNCTASK_UOBJECT(UObjectClassPointer, &UObject::Function, Vars)
  SYNCTASK_UFunction(UFunctionClassPointer, TEXT("UFunctionClass MerberFunction Name"), Vars)
  SYNCTASK_Lambda(LambdaFunction, Vars)
```

## GraphManage
```c++
  // 【GameThread】
  UThread::GetThreadGraphManage().CreateRawOnGameThread(&ClassTarget, &Class::Function, Vars);// sync
  UThread::GetThreadGraphManage().CreateSPOnGameThread(&SPClassTarget.ToSharedRef(), &SPClass::Function, Vars);
  UThread::GetThreadGraphManage().CreateUObjectOnGameThread(UObjectClassPointer, &UObject::Function, Vars);
  UThread::GetThreadGraphManage().CreateUFunctionOnGameThread(UFunctionClassPointer, TEXT("UFunctionClass MerberFunction Name"), Vars);
  UThread::GetThreadGraphManage().CreateLambdaOnGameThrea(LambdaFunction, Vars);

  //··························································································································································

  // 【AnyThread】
  TArray<FGraphEventRef> FGraphEventRefTArray;
  FGraphEventRefTArray.SetNum(5);

  FGraphEventRefTArray[0] = UThread::GetThreadGraphManage().CreateRawOnAnyThread(&ClassTarget, &Class::Function, Vars);
  FGraphEventRefTArray[1] = UThread::GetThreadGraphManage().CreateSPOnAnyThread(&SPClassTarget.ToSharedRef(), &SPClass::Function, Vars);
  FGraphEventRefTArray[2] = UThread::GetThreadGraphManage().CreateUObjectOnAnyThread(UObjectClassPointer, &UObject::Function, Vars);
  FGraphEventRefTArray[3] = UThread::GetThreadGraphManage().CreateUFunctionOnAnyThread(UFunctionClassPointer, TEXT("UFunctionClass MerberFunction Name"), Vars);
  FGraphEventRefTArray[4] = UThread::GetThreadGraphManage().CreateLambdaOnAnyThread(LambdaFunction, Vars);

  FGraphEventArray EventArray;
  for (FGraphEventRef& tmp : FGraphEventRefTArray)
  {
	EventArray.Add(tmp);
  }
  GRAPHTASK_WAITING_THREADS_COMPLETED(EventArray)// EventArray
  
  //··························································································································································

  FGraphEventRef I = CREATE_GRAPHTASK_Raw(nullptr/*PreEventRef*/, ENamedThreads::XXXThread, &ClassTarget, &Class::Function, Vars);
  FGraphEventRef II = CREATE_GRAPHTASK_SP(I, ENamedThreads::XXXThread, &SPClassTarget.ToSharedRef(), &SPClass::Function, Vars);
  FGraphEventRef III = CREATE_GRAPHTASK_UObject(II, ENamedThreads::XXXThread, UObjectClassPointer, &UObject::Function, Vars);
  FGraphEventRef IV = CREATE_GRAPHTASK_UFunction(III, ENamedThreads::XXXThread, UFunctionClassPointer, TEXT("UFunctionClass MerberFunction Name"), Vars);
  FGraphEventRef V = CREATE_GRAPHTASK_Lambda(IV, ENamedThreads::XXXThread,LambdaFunction, Vars);

  GRAPHTASK_WAITING_THREAD_COMPLETED(V)// Event
```

## CorotinesManage
```c++
  TArray<FCoroutinesHandle> FCoroutinesHandleTArray;
  FCoroutinesHandleTArray.SetNum(10);
  
  FCoroutinesHandleTArray[0] = UThread::GetThreadCorotinesManage().CreateRawNoDelay(FloatDelayTime, &ClassTarget, &Class::Function, Vars);
  FCoroutinesHandleTArray[1] = UThread::GetThreadCorotinesManage().CreateSPNoDelay(FloatDelayTime, &SPClassTarget.ToSharedRef(), &SPClass::Function, Vars);
  FCoroutinesHandleTArray[2] = UThread::GetThreadCorotinesManage().CreateUObjectNoDelay(FloatDelayTime, UObjectClassPointer, &UObject::Function, Vars);
  FCoroutinesHandleTArray[3] = UThread::GetThreadCorotinesManage().CreateUFunctionNoDelay(FloatDelayTime, UFunctionClassPointer, TEXT("UFunctionClass MerberFunction Name"), Vars);
  FCoroutinesHandleTArray[4] = UThread::GetThreadCorotinesManage().CreateLambdaNoDelay(FloatDelayTime, LambdaFunction, Vars);

  FCoroutinesHandleTArray[5] = UThread::GetThreadCorotinesManage().CreateRawDelay(&ClassTarget, &Class::Function, Vars);
  FCoroutinesHandleTArray[6] = UThread::GetThreadCorotinesManage().CreateSPDelay(&SPClassTarget.ToSharedRef(), &SPClass::Function, Vars);
  FCoroutinesHandleTArray[7] = UThread::GetThreadCorotinesManage().CreateUObjectDelay(UObjectClassPointer, &UObject::Function, Vars);
  FCoroutinesHandleTArray[8] = UThread::GetThreadCorotinesManage().CreateUFunctionDelay(UFunctionClassPointer, TEXT("UFunctionClass MerberFunction Name"), Vars);
  FCoroutinesHandleTArray[9] = UThread::GetThreadCorotinesManage().CreateLambdaDelay(LambdaFunction, Vars);

  for(FCoroutinesHandle& tmp : FCoroutinesHandleTArray)
  {
	tmp.Pin()->Awaken();
  }
```

## Windows
```c++
  FWindowsPlatformThread::RunDelegate.BindRaw(xxx);
  // FWindowsPlatformThread::RunDelegate.BindSP(xxx);
  // FWindowsPlatformThread::RunDelegate.BindUObject(xxx);
  // FWindowsPlatformThread::RunDelegate.BindUFunction(xxx);
  // FWindowsPlatformThread::RunDelegate.BindLambda(xxx);
  
  FWindowsPlatformThread::CompletedDelegate.BindRaw(xxx);
  // FWindowsPlatformThread::CompletedDelegate.BindSP(xxx);
  // FWindowsPlatformThread::CompletedDelegate.BindUObject(xxx);
  // FWindowsPlatformThread::CompletedDelegate.BindUFunction(xxx);
  // FWindowsPlatformThread::CompletedDelegate.BindLambda(xxx);

  FWindowsPlatformThread::Create();
```

## ResourceLoadingManage
```c++
  if(_InHandlePtr.IsValid())
  {
     TArray<UObject*> LoadedAssets;

     _InHandlePtr->GetLoadedAssets(LoadedAssets);

     for (UObject* Asset : LoadedAssets){}
  }
  else{}

  UThread::GetResourceLoadingManage().SetSoftPathInterface(FilePath);

  TSharedPtr<FStreamableHandle> HandlePtr// async
  =
  UThread::GetResourceLoadingManage().asyncLoadingExecuteLambdaDelegate(LambdaFunction, Vars);
  // UThread::GetResourceLoadingManage().asyncLoadingExecuteRawDelegate(&ClassTarget, &Class::Function, Vars);
  // UThread::GetResourceLoadingManage().asyncLoadingExecuteSPDelegate(&SPClassTarget.ToSharedRef(), &SPClass::Function, Vars);
  // UThread::GetResourceLoadingManage().asyncLoadingExecuteUObjectDelegate(UObjectClassPointer, &UObject::Function, Vars);
  // UThread::GetResourceLoadingManage().asyncLoadingExecuteUFunctionDelegate(UFunctionClassPointer, TEXT("UFunctionClass MerberFunction Name"), Vars);
  
  TSharedPtr<FStreamableHandle> HandlePtr = UThread::GetResourceLoadingManage().syncLoading(this->UObjectPath);// sync
  lambda(HandlePtr);
  
```
