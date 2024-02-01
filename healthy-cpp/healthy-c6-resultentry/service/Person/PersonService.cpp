#include "stdafx.h"
#include "PersonService.h"
#include "../../dao/Person/PersonDAO.h"

PersonPageDTO::Wrapper PersonService::listAll(const PersonQuery::Wrapper& query)
{
	// �������ض���
	auto pages = PersonPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	PersonDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<PersonDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (PersonDO sub : result)
	{
		auto dto = PersonDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, sex, Sex, age, Age, physical_type, Physical_type, sporadic_physical, Sporadic_physical)
			pages->addData(dto);

	}
	return pages;
}
