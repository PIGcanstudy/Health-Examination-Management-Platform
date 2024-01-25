#include "stdafx.h"
#include "AddNewItemsService.h"
#include "../../dao/addNewItems/AddNewItemsDAO.h"

// 分页查询所有数据
AddNewItemsPageDTO::Wrapper AddNewItemsService::listAll(const AddNewItemsQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = AddNewItemsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	AddNewItemsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<AddNewItemsDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (AddNewItemsDO sub : result)
	{
		auto dto = AddNewItemsDTO::createShared();
		// dto->name = sub.getName();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, checkProjectId, CheckProjectId, checkProjectName, CheckProjectName, portfolioProjectId, PortfolioProjectId, portfolioProjectName, PortfolioProjectName, reason, Reason)
			pages->addData(dto);
	}
	return pages;
}

uint64_t AddNewItemsService::saveData(const AddNewItemsDTO::Wrapper& dto)
{
	// 组装DO数据
	AddNewItemsDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id ,CheckProjectId, checkProjectId, CheckProjectName, checkProjectName)
		// 执行数据添加
		AddNewItemsDAO dao; 
	return dao.insert(data);
}
//下面可删除？？？？？？？
bool AddNewItemsService::updateData(const AddNewItemsDTO::Wrapper& dto)
{
	return false;
}

bool AddNewItemsService::removeData(uint64_t id)
{
	return false;
}