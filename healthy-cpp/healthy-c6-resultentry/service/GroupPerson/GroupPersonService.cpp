#include "stdafx.h"
#include "GroupPersonService.h"
#include "../../dao/GroupPerson/GroupPersonDAO.h"

GroupPersonPageDTO::Wrapper GroupPersonService::listAll(const GroupPersonQuery::Wrapper& query)
{
	// �������ض���
	auto pages = GroupPersonPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	GroupPersonDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<GroupPersonDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (GroupPersonDO sub : result)
	{
		auto dto = GroupPersonDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name)
			pages->addData(dto);

	}
	return pages;
}
