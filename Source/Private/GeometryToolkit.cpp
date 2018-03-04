// Copyright (c) 2018 Isara Technologies. All Rights Reserved.

#include "GeometryToolkit.h"

#include "GeometryToolkitPrivatePCH.h"

#define LOCTEXT_NAMESPACE "FGeometryToolkitModule"

DEFINE_LOG_CATEGORY(GeometryToolkit);

void FGeometryToolkitModule::StartupModule()
{
}

void FGeometryToolkitModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGeometryToolkitModule, GeometryToolkit)