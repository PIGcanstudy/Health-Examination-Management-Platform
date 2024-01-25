#include "stdafx.h"
#include "AddNewItemsService.h"
#include "../../dao/addNewItems/AddNewItemsDAO.h"

// ��ҳ��ѯ��������
AddNewItemsPageDTO::Wrapper AddNewItemsService::listAll(const AddNewItemsQuery::Wrapper& query)
{
	// �������ض���
	auto pages = AddNewItemsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	AddNewItemsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<AddNewItemsDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
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
	// ��װDO����
	AddNewItemsDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id ,CheckProjectId, checkProjectId, CheckProjectName, checkProjectName)
		// ִ���������
		AddNewItemsDAO dao; 
	return dao.insert(data);
}
//�����ɾ����������������
bool AddNewItemsService::updateData(const AddNewItemsDTO::Wrapper& dto)
{
	return false;
}

bool AddNewItemsService::removeData(uint64_t id)
{
	return false;
}