// Copyright 2012 Intel Corporation
//
// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
// 
//    http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "platform.h"

static BOOL event_on = TRUE;

BOOL is_back_button_event_enabled(void)
{
	return event_on;
}

static HRESULT platform_exec(BSTR callback_id, BSTR action, BSTR args, VARIANT *result)
{
	if (!wcscmp(action, L"backButtonEventOn"))
	{
		event_on = TRUE;
		return S_OK;
	}

	if (!wcscmp(action, L"backButtonEventOff"))
	{
		event_on = FALSE;
		return S_OK;
	}

	return DISP_E_MEMBERNOTFOUND;
}

DEFINE_CORDOVA_MODULE(Platform, L"Platform", platform_exec, NULL, NULL)