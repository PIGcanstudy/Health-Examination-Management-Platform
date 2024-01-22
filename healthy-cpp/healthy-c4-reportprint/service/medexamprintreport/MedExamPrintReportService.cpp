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
#include "MedExamPrintReportService.h"
#include "../../dao/medexamprintreport/MedExamPrintReportDAO.h"



MedExamPrintReportPageDTO::Wrapper MedExamPrintReportService::listAll(const MedExamPrintReportQuery::Wrapper& query)
{
	// �������ض���
	auto pages = MedExamPrintReportPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	MedExamPrintReportDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<MedExamPrintReportDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (MedExamPrintReportDO sub : result)
	{
		auto dto = MedExamPrintReportDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age, statu, Statu, printState, PrintState, sporadicPhysical, SporadicPhysical)
			pages->addData(dto);

	}
	return pages;
}

