#include "stdafx.h"
#include "UnitPhysicalExaminationOrdersDAO.h"
#include "UnitPhysicalExaminationOrdersMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
}

list<UnitPhysicalExaminationOrdersDO> UnitPhysicalExaminationOrdersDAO::selectWithPage(const UnitPhysicalExaminationOrdersQuery::Wrapper& query)
{
	stringstream sql;

	return list<UnitPhysicalExaminationOrdersDO>();
}

list<UnitPhysicalExaminationOrdersDO> UnitPhysicalExaminationOrdersDAO::selectByName(const string& name, const string& beginTime, const string& endTime)
{

	return list<UnitPhysicalExaminationOrdersDO>();
}
