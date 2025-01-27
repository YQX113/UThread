#pragma once

#include "CoreMinimal.h"
#include "Async/AsyncWork.h"

struct UTHREADPLUGIN_API FUTreadAbandonable : FNonAbandonableTask
{
public:
	FUTreadAbandonable(const FSimpleDelegate& _InThreadDelegate);

	void DoWork();


#if 1
	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FUTreadAbandonable, STATGROUP_ThreadPoolAsyncTasks);
	}
#endif

protected:
	FSimpleDelegate ThreadDelegate;
};