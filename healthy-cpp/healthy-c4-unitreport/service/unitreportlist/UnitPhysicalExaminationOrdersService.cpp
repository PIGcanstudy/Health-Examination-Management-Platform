#include "stdafx.h"
#include "UnitPhysicalExaminationOrdersService.h"
#include "../../dao/unitreportlist/UnitPhysicalExaminationOrdersDAO.h"

UnitListPageDTO::Wrapper UnitPhysicalExaminationOrdersService::listAll(const UnitPhysicalExaminationOrdersQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = UnitListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	UnitPhysicalExaminationOrdersDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<UnitPhysicalExaminationOrdersDO> result = dao.selectWithPage(query);

	// 将DO转换成DTO
	for (UnitPhysicalExaminationOrdersDO sub : result)
	{
		auto dto = UnitListDTO::createShared();
 		dto->name = sub.getName();
 		dto->code = sub.getCode();
 		dto->signingTime = sub.getSigningTime();
 		dto->Escalation = sub.getEscalation();
		dto->detectionType = sub.getDetectionType();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, code, Code, signingTime, SigningTime, Escalation, Escalation, detectionType, DetectionType)
	    pages->addData(dto);

	}
	return pages;
}
