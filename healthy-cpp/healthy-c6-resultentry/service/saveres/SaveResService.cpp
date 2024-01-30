#include "stdafx.h"
#include "SaveResService.h"
#include "../../dao/saveres/saveresDAO.h"
#include "../../../lib-common/include/SimpleDateTimeFormat.h"
#include "../../Macros.h"
#include "../../../lib-mysql/include/TransactionManager.h"


uint64_t SaveResService::saveData(const SaveResDTO::Wrapper& dto, const string createId)
{
	SnowFlake sf(1, 1);
	uint64_t uint_id = sf.nextId();
	string id = to_string(uint_id);

	SaveResDO data;
	data.setCreateId(createId);
	SimpleDateTimeFormat createDate;
	data.setId(id);
	data.setCreateDate(createDate.format());
	data.setCheck_num(1);
	data.setDelFlag(0);
	data.setState(0);
	data.setIsFile("no");
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personId, OfficeId, officeId, OfficeName, officeName, \
		CheckDoc, checkDoc, CheckDate, checkDate, DelFlag, delFlag, \
		GroupItemId, groupItemId, GroupItemName, groupItemName, DiagnoseSum, diagnoseSum, \
		IsCheck, isCheck, DiagnoseTip, diagnoseTip)
	// 执行数据添加;;
	SaveResDAO d1, d2;
	// 定义事务
	TransactionManager tm(&d1, &d2);
	
	int row = d1.insert(data);
	data.setDepartResId(id);
	data.setOrderNum(1);
	data.setPostive(0);
	for (int i = 0; i < dto->itemList->size(); i++)
	{
		auto &itemDto = dto->itemList[i];
		uint_id = sf.nextId();
		id = to_string(uint_id);
		data.setId(id);
		ZO_STAR_DOMAIN_DTO_TO_DO(data, itemDto, OrderGroupItemProjectId, orderGroupItemProjectId, \
			OrderGroupItemProjectName, orderGroupItemProjectName, \
			Result, result, UnitCode, unitCode, UnitName, unitName, CrisisDegree, crisisDegree)
		row = row + d2.insertItem(data);
	}
	if (row == 1 + dto->itemList->size())
	{
		cout << "tm commit" << endl;
		tm.commit();
	}
	else
	{
		cout << "tm rollback" << endl;
		tm.rollback();
	}

	return row == 1 + dto->itemList->size();
}

uint64_t SaveResService::saveDataItem(const SaveResDTO::Wrapper& dto, const string createId)
{	
	SaveResDO data;
	return {};
}
