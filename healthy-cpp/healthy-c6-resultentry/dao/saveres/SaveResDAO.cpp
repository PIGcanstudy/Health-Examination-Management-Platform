#include "SaveResDAO.h"
#include "../../domain/do/saveres/saveresDO.h"

//string sql = "INSERT INTO `sample` (`id`, `project`, `degree`, `time`) VALUES(? , ? , ? , ? )";
//return sqlSession->executeInsert(sql, "%s%s%i", iObj.getId(), iObj.getProject(), iObj.getDegree(), iObj.getTime());

uint64_t SaveResDAO::insert(const SaveResDO& iObj)
{
	string sql = "INSERT INTO `t_depart_result` "
		"(`id`, `person_id`, `group_item_id`, `group_item_name`, `diagnose_tip`,"
		" `diagnose_sum`, `office_id`, `office_name`, `check_num`, `check_doc`, `check_date`, `del_flag`,"
		"`create_id`, `create_date`, `is_file`,`state`)"
		"VALUES(? , ? , ? , ?, ? , ? , ?, ? , ? , ?, ? , ? , ?, ? , ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%i%s%s%i%i%s%s%i",\
		iObj.getId(), iObj.getPersonId(), iObj.getGroupItemId(), iObj.getGroupItemName(),\
		iObj.getDiagnoseTip(), iObj.getDiagnoseSum(), iObj.getOfficeId(), iObj.getOfficeName(),\
		iObj.getCheck_num(), iObj.getCheckDoc(), iObj.getCheckDate(), iObj.getDelFlag(),\
		iObj.getCreateId(), iObj.getCreateDate(), iObj.getIsFile(), iObj.getState());
}

uint64_t SaveResDAO::insertItem(const SaveResDO& iObj)
{
	return {};
	
}
