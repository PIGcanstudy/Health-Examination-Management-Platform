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
#include "downloadReportService.h"
#include "../../dao/downloadReport/downloadReportDAO.h"

downloadReportPageDTO::Wrapper downloadReportService::listAll(const downloadReportQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = downloadReportPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	downloadReportDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<downloadReportDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (downloadReportDO sub : result)
	{
		auto dto = downloadReportDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)
			pages->addData(dto);

	}
	return pages;
}

uint64_t downloadReportService::saveData(const downloadReportDTO::Wrapper& dto)
{
	// 组装DO数据
	downloadReportDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
		// 执行数据添加
		downloadReportDAO dao;
	return dao.insert(data);
}

bool downloadReportService::updateData(const downloadReportDTO::Wrapper& dto)
{
	// 组装DO数据
	downloadReportDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id)
		// 执行数据修改
		downloadReportDAO dao;
	return dao.update(data) == 1;
}

bool downloadReportService::removeData(uint64_t id)
{
	downloadReportDAO dao;
	return dao.deleteById(id) == 1;
}
