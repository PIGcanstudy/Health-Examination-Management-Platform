#include "stdafx.h"
#include "FileDAO.h"
#include <sstream>

//定义条件解析宏，减少重复代码
//#define SAMPLE_TERAM_PARSE(query, sql) \
//SqlParams params; \
//sql<<" WHERE 1=1"; \
//if (query->id) { \
//	sql << " AND `id`=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
//} \
//if (query->url) { \
//	sql << " AND url=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->url.getValue("")); \
//} 



int FileDAO::update(const FileDO& uObj)
{
	string sql = "UPDATE `t_depart_result` SET `url`=?  WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s", uObj.getUrl(), uObj.getId());
}
