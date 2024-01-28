#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/16 11:34:14

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
#ifndef _MEDEXAMPRINTREPORT_VO_
#define _MEDEXAMPRINTREPORT_VO_

#include "../GlobalInclude.h"
#include "../dto/MedExamPrintReportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 单位列表显示JsonVO实体
 * 负责人：小智
 */
class MedExamPrintReportJsonVO : public JsonVO<MedExamPrintReportDTO::Wrapper> {
	DTO_INIT(MedExamPrintReportJsonVO, JsonVO<MedExamPrintReportDTO::Wrapper>);
};

/**
 * 单位分页列表显示JsonVO实体
 * 负责人：小智
 */

class MedExamPrintReportPageJsonVO : public JsonVO<MedExamPrintReportPageDTO::Wrapper> {
	DTO_INIT(MedExamPrintReportPageJsonVO, JsonVO<MedExamPrintReportPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MEDEXAMPRINTREPORT_VO_