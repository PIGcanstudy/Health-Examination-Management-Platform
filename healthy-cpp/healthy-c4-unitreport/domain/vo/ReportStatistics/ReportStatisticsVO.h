#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

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
#ifndef _REPORTSTATISTICS_H_
#define _REPORTSTATISTICS_H_

#include "../../GlobalInclude.h"
#include "../../dto/ReportStatistics/ReportStatisticsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 体检人员汇总表示例显示JsonVO，用于响应给客户端的Json对象
 */
class PhysicalExaminationPersonnelJsonVO : public JsonVO<PhysicalExaminationPersonnelDTO::Wrapper>
{
	DTO_INIT(PhysicalExaminationPersonnelJsonVO, JsonVO<PhysicalExaminationPersonnelDTO::Wrapper>);
};

/**
 *复查人员汇总表示例显示JsonVO，用于响应给客户端的Json对象
 */
class ReviewPersonnelJsonVO : public JsonVO<ReviewPersonnelDTO::Wrapper>
{
	DTO_INIT(ReviewPersonnelJsonVO, JsonVO<ReviewPersonnelDTO::Wrapper>);
};

/**
 *  复查结果汇总表示例显示JsonVO，用于响应给客户端的Json对象
 */
class ReviewResultsJsonVO : public JsonVO<ReviewResultsDTO::Wrapper>
{
	DTO_INIT(ReviewResultsJsonVO, JsonVO<ReviewResultsDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)


#endif // !_SAMPLE_VO_
