#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/16 10:59:38

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
#ifndef _MEDEXAMPRINTREPORTDTO_H_
#define _MEDEXAMPRINTREPORTDTO_H_
#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 单位列表数据传输对象实体
 * 负责人：小智
 */
class MedExamPrintReportDTO : public oatpp::DTO
{
	DTO_INIT(MedExamPrintReportDTO, DTO);
	// 唯一编号
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("print.field.id"));
	// 姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("print.field.name"));
	// 年龄
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("print.field.age"));
	// 性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("print.field.sex"));
	// 审核
	API_DTO_FIELD_DEFAULT(Boolean, statu, ZH_WORDS_GETTER("print.field.statu"));
	// 打印
	API_DTO_FIELD_DEFAULT(Boolean,printState, ZH_WORDS_GETTER("print.field.printState"));

};

/**
 * 示例分页传输对象
 */
class MedExamPrintReportPageDTO : public PageDTO<MedExamPrintReportDTO::Wrapper>
{
	DTO_INIT(MedExamPrintReportPageDTO, PageDTO<MedExamPrintReportDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MEDEXAMPRINTREPORTDTO_H_