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
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryInquiryDetail) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("inquiry.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(InquiryDetailPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//必须
		API_DEF_ADD_QUERY_PARAMS(UInt32, "workYear", ZH_WORDS_GETTER("inquiry.field.workYear"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "workMonth", ZH_WORDS_GETTER("inquiry.field.workMonth"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(String, "maritalStatus", ZH_WORDS_GETTER("inquiry.field.maritalStatus"), u8"已婚", true);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "needYear", ZH_WORDS_GETTER("inquiry.field.needYear"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "needmonth", ZH_WORDS_GETTER("inquiry.field.needMonth"), 1, true);
		//非必须
		API_DEF_ADD_QUERY_PARAMS(String, "culture", ZH_WORDS_GETTER("inquiry.field.culture"), u8"大学", false);
		API_DEF_ADD_QUERY_PARAMS(String, "homeAddress", ZH_WORDS_GETTER("inquiry.field.homeAddress"), u8"广州", false);
		API_DEF_ADD_QUERY_PARAMS(String, "jobName", ZH_WORDS_GETTER("inquiry.field.jobName"), u8"学生", false);
		API_DEF_ADD_QUERY_PARAMS(String, "jobOrderName", ZH_WORDS_GETTER("inquiry.field.jobOrderName"), u8"教师", false);
		API_DEF_ADD_QUERY_PARAMS(String, "department", ZH_WORDS_GETTER("inquiry.field.department"), u8"学术部", false);

	} 
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/evalue/inquiry-detail", queryInquiryDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(idq, InquiryDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryInquiryDetail(idq));
	}


private:
	InquiryDetailJsonVO::Wrapper execQueryInquiryDetail(const InquiryDetailQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif  _SAMPLE_CONTROLLER_