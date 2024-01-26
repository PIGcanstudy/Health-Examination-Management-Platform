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
//在AddNewItems中实现 增加功能，此处应删除
//uint64_t ReviewService::saveData(const ReviewListDTO::Wrapper& dto)
//{
	// 组装DO数据
	//ReviewDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CheckProjectId, checkProjectId, CheckProjectName, checkProjectName, ReviewExplain, reviewExplain)
		// 执行数据添加
		//ReviewDAO dao;
	//return dao.insert(data);
	//return 0;
//}
// 修改数据  下面代码不能同时修改多个表中的数据
bool ReviewService::updateData(const ReviewListDTO::Wrapper& dto)
{
	// 组装DO数据
	ReviewDO data;
	//person_name  hazard_factor_code不在该表，无法修改 swagger上显示的这两个字段，可以直接无视
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonName, personName, PersonId, personId, CheckProjectId, checkProjectId, CheckProjectName, checkProjectName, ReviewExplain, reviewExplain, ReviewTime, reviewTime, CreateTime, createTime, State, state, HazardFactorCode, hazardFactorCode, Id, id)
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personId, CheckProjectId, checkProjectId, CheckProjectName, checkProjectName, ReviewExplain, reviewExplain, ReviewTime, reviewTime, CreateTime, createTime, State, state, Id, id)
	// 执行数据修改
	ReviewDAO dao;
	return dao.update(data) == 1;
}
// 通过ID删除数据
bool ReviewService::removeData(string id)
{
	ReviewDAO dao;
	return dao.deleteById(id) == 1;
}