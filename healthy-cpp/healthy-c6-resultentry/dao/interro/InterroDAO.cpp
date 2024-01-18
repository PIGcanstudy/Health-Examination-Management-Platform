#include "stdafx.h"
#include "InterroDAO.h"
#include "InterroMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->id) { \
	sql << " AND `person_id`=?"; \
	SQLPARAMS_PUSH(params, "s",std::string, query->id.getValue("")); \
} \
if (query->project) { \
	sql << " AND code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->project.getValue("")); \
} 


list<InterroDO> InterroDAO::selectWith(const InterroQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT person_id,project_name,degree,course_time FROM t_symptom";
	SAMPLE_TERAM_PARSE(query, sql);
	InterroMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<InterroDO, InterroMapper>(sqlStr, mapper, params);
}
