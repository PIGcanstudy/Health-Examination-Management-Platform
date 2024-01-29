#pragma once
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
#ifndef _INQUIRYDETAIL_CONTROLLER_
#define _INQUIRYDETAIL_CONTROLLER_


#include "domain/vo/BaseJsonVO.h"
#include "../healthy-c7-common/domain/query/evalue/InquiryDetailQuery.h"
#include "../healthy-c7-common/domain/dto/evalue/InquiryDetailDTO.h"
#include "../healthy-c7-common/domain/vo/evalue/InquiryDetailVO.h"
#include "../../../arch-demo/controller/file/FileController.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 控制器，演示基础接口的使用
 */
class InquiryDetailController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(InquiryDetailController);
	// 3 定义接口
public:
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("InquiryDetail.put.summary"), modifyInquiryDetail, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/evalue/inquiry-detail", modifyInquiryDetail, BODY_DTO(InquiryDetailDTO::Wrapper, dto), execModifyInquiryDetail(dto));


private:
	Uint64JsonVO::Wrapper execModifyInquiryDetail(const InquiryDetailDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif  _INQUIRYDETAIL_CONTROLLER_