#pragma once

#include "CoreMinimal.h"
#include "Core/Manage/ThreadAbandonableManage.h"
#include "Core/Manage/ThreadProxyManage.h"
#include "Core/Manage/ThreadTaskManage.h"
#include "Core/Manage/CoroutinesManage.h"
#include "Core/Manage/ThreadGraphManage.h"
#include "Core/Manage/ResourceLoadingManage.h"
#include "Tickable.h"

namespace UThreadManage
{
	class UTHREADPLUGIN_API FThreadManagement
		: public TSharedFromThis<FThreadManagement>
		, public FTickableGameObject
	{
	public:
		FThreadManagement() = default;
		~FThreadManagement() = default;


	public:
		static TSharedRef<FThreadManagement> Get();
		static void Destory();


	public:
		static FThreadProxyMange& GetThreadProxyMange() {return FThreadManagement::Get()->ThreadProxyMange;}

		static FThreadTaskManagement& GetThreadTaskManagement() {return FThreadManagement::Get()->ThreadTaskManagement;}

		static FThreadAbandonableManage& GetThreadAbandonableManage() {return FThreadManagement::Get()->ThreadAbandonableManage;}

		static FCorotinesManage& GetThreadCorotinesManage() {return FThreadManagement::Get()->ThreadCorotinesManage;}

		static FThreadGraphManage& GetThreadGraphManage(){ return FThreadManagement::Get()->ThreadGraphManage; }

		static FResourceLoadingManage& GetResourceLoadingManage() { return FThreadManagement::Get()->ResourceLoadingManage; }


	protected:
		FThreadProxyMange ThreadProxyMange;

		FThreadTaskManagement ThreadTaskManagement;

		FThreadAbandonableManage ThreadAbandonableManage;

		FCorotinesManage ThreadCorotinesManage;

		FThreadGraphManage ThreadGraphManage;

		FResourceLoadingManage ResourceLoadingManage;

	private:
		virtual void Tick(float DeltaTime) override;

		virtual TStatId GetStatId() const override;


	private:
		static TSharedPtr<FThreadManagement> ThreadManagementPtr;
	};	
}
using namespace UThreadManage;