// Copyright (c) 2018 Isara Technologies. All Rights Reserved.

#pragma once

#include "Modules/ModuleInterface.h"

class FGeometryToolkitModule : public IModuleInterface
{
public:

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};