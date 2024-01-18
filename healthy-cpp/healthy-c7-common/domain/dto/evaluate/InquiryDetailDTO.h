#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: lenya~
 @Date: 2024/1/18

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
#ifndef _USERDTO_H_
#define _USERDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  获取问诊明细传输数据
 */

class InquiryDetailDTO : public oatpp::DTO
{
	DTO_INIT(InquiryDetailDTO, DTO);
	// 工龄年段
	API_DTO_FIELD_DEFAULT(Int32, workYear, ZH_WORDS_GETTER("inquiry.field.workYear"));
	// 工龄月段
	API_DTO_FIELD_DEFAULT(Int32, workMonth, ZH_WORDS_GETTER("inquiry.field.workMonth"));
	// 结婚状况
	API_DTO_FIELD_DEFAULT(String, maritalStatus, ZH_WORDS_GETTER("inquiry.field.maritalStatus"));
	//按需年龄
	API_DTO_FIELD_DEFAULT(Int32, needYear, ZH_WORDS_GETTER("inquiry.field.needYear"));
	//按需月龄
	API_DTO_FIELD_DEFAULT(Int32, needmonth, ZH_WORDS_GETTER("inquiry.field.needmonth"));

	//非必须
	
	//文化程度
	API_DTO_FIELD_DEFAULT(String, culture, ZH_WORDS_GETTER("inquiry.field.culture"));
	//家庭地址
	API_DTO_FIELD_DEFAULT(String, homeAddress, ZH_WORDS_GETTER("inquiry.field.homeAddress"));
	//工种名称
	API_DTO_FIELD_DEFAULT(String, jobName, ZH_WORDS_GETTER("inquiry.field.jobName"));
	//工种其他名称
	API_DTO_FIELD_DEFAULT(String, jobOrderName, ZH_WORDS_GETTER("inquiry.field.jobOrderName"));
	//所属部门
	API_DTO_FIELD_DEFAULT(String, department, ZH_WORDS_GETTER("inquiry.field.department"));

};

/**
 * 定义一个问诊明细信息分页传输对象
 */
class InquiryDetailPageDTO : public PageDTO<InquiryDetailDTO::Wrapper>
{
	DTO_INIT(InquiryDetailPageDTO, PageDTO<InquiryDetailDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_