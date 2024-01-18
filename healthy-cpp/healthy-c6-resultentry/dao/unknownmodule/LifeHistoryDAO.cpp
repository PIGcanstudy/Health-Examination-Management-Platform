#include "stdafx.h"
#include "LifeHistoryDAO.h"
#include "LifeHistoryMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define GROUP_PERSON_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->person_id) { \
	sql << " AND `person_id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->person_id.getValue("")); \
} \

uint64_t LifeHistoryDAO::count(const LifeHistoryQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_interrogation";
	GROUP_PERSON_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<LifeHistoryDO> LifeHistoryDAO::selectWithPage(const LifeHistoryQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT person_id,job,work_year,work_month,exposure_start_date, education, family_address, marriage_date FROM t_interrogation";
	GROUP_PERSON_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	LifeHistoryMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<LifeHistoryDO, LifeHistoryMapper>(sqlStr, mapper, params);
}