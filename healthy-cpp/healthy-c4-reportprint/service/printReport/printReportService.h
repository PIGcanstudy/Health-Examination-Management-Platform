#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _PRINTREPORT_SERVICE_
#define _PRINTREPORT_SERVICE_
#include <list>
#include "domain/vo/printReport/printReportVO.h"
#include "domain/query/printReport/printReportQuery.h"
#include "domain/dto/printReport/printReportDTO.h"

/**
 * 下载PDF
 * 负责人：晚风
 */
class printReportService
{
public:
	// 分页查询所有数据
	printReportPageDTO::Wrapper listAll(const printReportQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const printReportDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const printReportDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_PRINTREPORT_SERVICE_

