#include "stdafx.h"
#include "GroupPersonDAO.h"
#include "GroupPersonMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define GroupPerson_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \

uint64_t GroupPersonDAO::count(const GroupPersonQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM GroupPerson";
	GroupPerson_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<GroupPersonDO> GroupPersonDAO::selectWithPage(const GroupPersonQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT id,name,sex,age FROM GroupPerson";
	GroupPerson_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GroupPersonMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<GroupPersonDO, GroupPersonMapper>(sqlStr, mapper, params);
}

std::list<GroupPersonDO> GroupPersonDAO::selectByName(const string& name)
{
	string sql = "SELECT id,name,sex,age FROM GroupPerson WHERE `name` LIKE CONCAT('%',?,'%')";
	GroupPersonMapper mapper;
	return sqlSession->executeQuery<GroupPersonDO, GroupPersonMapper>(sql, mapper, "%s", name);
}