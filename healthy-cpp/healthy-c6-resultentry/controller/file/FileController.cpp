/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 11:37:57

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "FileController.h"
#include "../../service/file/FileService.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper FileController::execModifySample(const FileDTO::Wrapper& dto, const PayloadDTO& payload)
{
	
	//return Uint64JsonVO::Wrapper();
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	FileService service;
	// 执行数据修改
	if (service.updateData(dto, payload)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(2);
	}
	// 响应结果
	return jvo;
}
