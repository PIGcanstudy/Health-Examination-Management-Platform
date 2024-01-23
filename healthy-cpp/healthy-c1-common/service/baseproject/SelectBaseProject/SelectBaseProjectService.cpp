
#include "stdafx.h"
#include "SelectBaseProjectService.h"
#include "../../../dao/baseproject/SelectBaseProject/SelectBaseProjectDAO.h"

SelectBaseProjectPageDTO::Wrapper SelectBaseProjectService::listAll(const SelectBaseProjectQuery::Wrapper& query)
{
	// �������ض���
	auto pages = SelectBaseProjectPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	SelectBaseProjectDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<SelectBaseProjectDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (SelectBaseProjectDO sub : result)
	{
		auto dto = SelectBaseProjectDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			id, Id,
			code, Code,
			name, Name,
			short_name, ShortName,
			order_num, OrderNum,
			office_id, OfficeId,
			office_name, OfficeName,
			unit_code, UnitCode,
			unit_name, UnitName,
			default_value, DefaultValue,
			result_type, ResultType,
			in_conclusion, InConclusion,
			in_report, InReport,
			relation_code, RelationCode,
			del_flag, DelFlag,
			create_id, CreateId,
			create_time, CreateTime,
			update_id, UpdateId,
			update_time, UpdateTime,
			delete_id, DeleteId,
			delete_time, DeleteTime,
			department_id, DepartmentId)

		pages->addData(dto);

	}
	return pages;
}

uint64_t SelectBaseProjectService::saveData(const SelectBaseProjectDTO::Wrapper& dto)
{
	// ��װDO����
	SelectBaseProjectDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		Id, id,
		Code, code,
		Name, name,
		ShortName, short_name,
		OrderNum, order_num,
		OfficeId, office_id,
		OfficeName, office_name,
		UnitCode, unit_code,
		UnitName, unit_name,
		DefaultValue, default_value,
		ResultType, result_type,
		InConclusion, in_conclusion,
		InReport, in_report,
		RelationCode, relation_code,
		DelFlag, del_flag,
		CreateId, create_id,
		CreateTime, create_time,
		UpdateId, update_id,
		UpdateTime, update_time,
		DeleteId, delete_id,
		DeleteTime, delete_time,
		DepartmentId, department_id)

		// ִ���������
		SelectBaseProjectDAO dao;
	return dao.insert(data);
}

bool SelectBaseProjectService::updateData(const SelectBaseProjectDTO::Wrapper& dto)
{
	// ��װDO����
	SelectBaseProjectDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		Id, id,
		Code, code,
		Name, name,
		ShortName, short_name,
		OrderNum, order_num,
		OfficeId, office_id,
		OfficeName, office_name,
		UnitCode, unit_code,
		UnitName, unit_name,
		DefaultValue, default_value,
		ResultType, result_type,
		InConclusion, in_conclusion,
		InReport, in_report,
		RelationCode, relation_code,
		DelFlag, del_flag,
		CreateId, create_id,
		CreateTime, create_time,
		UpdateId, update_id,
		UpdateTime, update_time,
		DeleteId, delete_id,
		DeleteTime, delete_time,
		DepartmentId, department_id)
		// ִ�������޸�
		SelectBaseProjectDAO dao;
	return dao.update(data) == 1;
}

bool SelectBaseProjectService::removeData(uint64_t id)
{
	SelectBaseProjectDAO dao;
	return dao.deleteById(id) == 1;
}
