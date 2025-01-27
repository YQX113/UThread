#include "CoreTypes.h"

#if PLATFORM_WINDOWS
struct UTHREADPLUGIN_API FWindowsPlatformThread
{
public:
	static void Create();

	static void Close();

	static bool IsWork();

public:
	static FSimpleDelegate RunDelegate;

	static FSimpleDelegate CompletedDelegate;
};
#endif