#include "stdafx.h"
#include "SaveResService.h"
#include "../../dao/saveres/saveresDAO.h"
#include "../../../lib-common/include/SimpleDateTimeFormat.h"
#include "../../Macros.h"


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
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personId, OfficeId, officeId, OfficeName, officeName,\
		CheckDoc, checkDoc, CheckDate, checkDate, DelFlag, delFlag,\
		GroupItemId, groupItemId, GroupItemName, groupItemName, DiagnoseSum, diagnoseSum,\
		IsCheck, isCheck, DiagnoseTip, diagnoseTip)
		// 执行数据添加;;
	SaveResDAO dao;
	return dao.insert(data);
}

uint64_t SaveResService::saveDataItem(const SaveResDTO::Wrapper& dto, const string createId)
{	
	SaveResDO data;
	return {};
}
