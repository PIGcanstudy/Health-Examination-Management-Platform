#include "stdafx.h"
#include "QueryPeopleDAO.h"
#include "QueryPeopleMapper.h"
#include<sstream>


//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->person_name) { \
	sql << " AND `person_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->person_name.getValue("")); \
} \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->id_card) { \
	sql << " AND id_card=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id_card.getValue("")); \
}\
if (query->birth ) { \
	sql << " AND birth=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->birth.getValue("")); \
} \
if (query->age ) { \
	sql << " AND age =?"; \
	SQLPARAMS_PUSH(params, "i", std::int, query->age .getValue(1)); \
} \
if (query->is_marry) { \
	sql << " AND is_marry=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_marry.getValue("")); \
} \
if (query->mobile) { \
	sql << " AND mobile=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->mobile.getValue("")); \
} \


uint64_t QueryPeopleDAO::count(const UnitQuery::Wrapper& query)
{
	return 0;
}

list<QueryDO> QueryPeopleDAO::selectWithPage(const UnitQuery::Wrapper& query)
{
	return list<QueryDO>();
}

list<QueryDO> QueryPeopleDAO::selectByIdCard(const string& id_card)
{
	string sql = "SELECT person_name, sex, id_card, birth, age, is_marry, mobile FROM t_group_person WHERE id_card LIKE CONCAT('%', ? , '%')";
	QueryPeopleMapper mapper;
	return sqlSession->executeQuery<QueryDO, QueryPeopleMapper>(sql, mapper, "%s", id_card);
}
