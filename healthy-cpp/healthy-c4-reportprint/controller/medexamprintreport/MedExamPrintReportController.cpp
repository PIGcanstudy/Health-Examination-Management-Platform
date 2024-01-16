/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/16 13:00:32

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
#include "MedExamPrintReportController.h"

MedExamPrintReportJsonVO::Wrapper MedExamPrintReportController::execQueryMedExamPrintReport(const MedExamPrintReportQuery::Wrapper& query)
{

	MedExamPrintReportJsonVO::Wrapper vo = MedExamPrintReportJsonVO::createShared();
	auto dto = MedExamPrintReportDTO::createShared();
	if (query->pageIndex == 1)
	{
		vo->success(dto);
	}
	else
	{
		vo->fail(dto);
	}
	return vo;
}