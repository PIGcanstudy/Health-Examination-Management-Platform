#include "stdafx.h"
#include "ReviewService.h"
#include "../../dao/review/ReviewDAO.h"

// 分页查询所有数据
ReviewListPageDTO::Wrapper ReviewService::listAll(const ReviewQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ReviewListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ReviewDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ReviewDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ReviewDO sub : result)
	{
		auto dto = ReviewListDTO::createShared();
		// dto->name = sub.getName();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, personName, PersonName, checkProjectName, CheckProjectName, reviewExplain, ReviewExplain, reviewTime, ReviewTime, createTime, CreateTime, state, State, hazardFactorCode, HazardFactorCode)
			pages->addData(dto);
	}
	return pages;
}
//下面可删除？？？？？？？
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