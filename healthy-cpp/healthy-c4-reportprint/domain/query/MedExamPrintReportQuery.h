#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/16 11:36:29

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
#ifndef _MEDEXAMPRINTREPORT_H_
#define _MEDEXAMPRINTREPORT_H_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 报告打印分页查询体检人员
 * 负责人：小智
 */
class MedExamPrintReportQuery : public PageQuery
{
	DTO_INIT(MedExamPrintReportQuery, PageQuery);
	// 查询类型
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("print.field.type"));
	// 姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("print.field.name"));
	// 订单编号
	API_DTO_FIELD_DEFAULT(String, orderId, ZH_WORDS_GETTER("print.field.orderId"));
	// 体检编号
	API_DTO_FIELD_DEFAULT(String, testNum, ZH_WORDS_GETTER("print.field.testNum"));
	// 单位名称
	API_DTO_FIELD_DEFAULT(String, dept, ZH_WORDS_GETTER("print.field.dept"));
	// 体检日期
	API_DTO_FIELD_DEFAULT(String, checkDate, ZH_WORDS_GETTER("print.field.checkDate"));
	// 是否复查
	API_DTO_FIELD_DEFAULT(Boolean, isRecheck, ZH_WORDS_GETTER("print.field.isRecheck"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MEDEXAMPRINTREPORT_H_