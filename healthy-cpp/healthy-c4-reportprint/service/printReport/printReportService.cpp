/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "printReportService.h"
#include "../../dao/printReport/printReportDAO.h"

bool printReportService::updateData(const printReportDTO::Wrapper& dto)
{
	// 组装DO数据
	printReportDO data;
	data.setId(dto->id.getValue(""));
	data.setReportPrintingNum(dto->reportPrintingNum.getValue(1));
	data.setPrintState(dto->printState.getValue(1));

	// 执行数据修改
	printReportDAO dao;
	return dao.update(data) == 1;
}


