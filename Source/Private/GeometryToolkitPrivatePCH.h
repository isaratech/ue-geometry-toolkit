// Copyright (c) 2017 Isara Technologies. All Rights Reserved.

#pragma once

#include "Runtime/Launch/Resources/Version.h"

#if ENGINE_MINOR_VERSION >= 15
#include "CoreMinimal.h"
#include "EngineDefines.h"
#include "Engine/Engine.h"
#include "UObject/Object.h"
#include "UObject/ScriptMacros.h"
#else
#include "CoreUObject.h"
#include "Engine.h"
#endif

#include "Engine.h"
#include "RunnableThread.h"

#include <string>
#include <map>
#include <ctime>
#include <iostream>
#include <string>
#include <map>
#include <sstream>

DECLARE_LOG_CATEGORY_EXTERN(GeometryToolkit, Log, All);
#include "ModuleManager.h"
