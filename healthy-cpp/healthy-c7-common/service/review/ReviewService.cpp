#include "stdafx.h"
#include "ReviewService.h"
#include "../../dao/review/ReviewDAO.h"

// ��ҳ��ѯ��������
ReviewListPageDTO::Wrapper ReviewService::listAll(const ReviewQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ReviewListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ReviewDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ReviewDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ReviewDO sub : result)
	{
		auto dto = ReviewListDTO::createShared();
		// dto->name = sub.getName();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, personName, PersonName, checkProjectName, CheckProjectName, reviewExplain, ReviewExplain, reviewTime, ReviewTime, createTime, CreateTime, state, State, hazardFactorCode, HazardFactorCode)
			pages->addData(dto);
	}
	return pages;
}
//�����ɾ����������������
uint64_t ReviewService::saveData(const ReviewListDTO::Wrapper& dto)
{
	return 0;
}

bool ReviewService::updateData(const ReviewListDTO::Wrapper& dto)
{
	return false;
}

bool ReviewService::removeData(uint64_t id)
{
	return false;
}