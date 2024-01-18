#include "stdafx.h"
#include "QueryPeopleService.h"
#include "dao/checkpeople/QueryPeopleDAO.h"

UnitListPageDTO::Wrapper QueryPeopleService::listAll(const UnitQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = UnitListPageDTO::createShared();
	

	// 查询数据总条数
	QueryPeopleDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<QueryDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
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
