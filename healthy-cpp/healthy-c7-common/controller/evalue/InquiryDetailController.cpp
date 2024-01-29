/*
 Copyright Zero One Star. All rights reserved.

 @Author: lenyan~
 @Date: 2024/01/19

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
#include "InquiryDetailController.h"
#include "domain/dto/evalue/InquiryDetailDTO.h"
#include "../../service/evalue/InquiryDetailService.h"

// 这个结构体代表了查询细节的 JSON 响应的包装器。
// 它作为 execQueryInquiryDetail 函数的返回类型。

Uint64JsonVO::Wrapper InquiryDetailController::execModifyInquiryDetail(const InquiryDetailDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	InquiryDetailService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
	//return {};
}