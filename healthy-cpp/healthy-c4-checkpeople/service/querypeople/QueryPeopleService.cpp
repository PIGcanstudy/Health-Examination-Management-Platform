#include "stdafx.h"
#include "QueryPeopleService.h"
#include "dao/checkpeople/QueryPeopleDAO.h"

UnitListPageDTO::Wrapper QueryPeopleService::listAll(const UnitQuery::Wrapper& query)
{
	// �������ض���
	auto pages = UnitListPageDTO::createShared();
	

	// ��ѯ����������
	QueryPeopleDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<QueryDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (QueryDO sub : result)
	{
		auto dto = UnitListDTO::createShared();
		dto->age = sub.getAge();
		dto->birth = sub.getBirth();
		dto->idCard = sub.getidCard();
		dto->isMarry = sub.getisMarry();
		dto->mobile = sub.getMobile();
		dto->sex = sub.getSex();
		dto->personName = sub.getpersonName();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, age, Age);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, birth, Birth);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, idCard, idCard);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, isMarry, isMarry);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, mobile, Mobile);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, sex, Sex);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, personName, personName);
		pages->addData(dto);

	}
	return pages;
}
