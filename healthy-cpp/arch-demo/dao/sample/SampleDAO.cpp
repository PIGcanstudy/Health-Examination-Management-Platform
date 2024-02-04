#include "stdafx.h"
#include "SampleDAO.h"
#include "SampleMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->spec) { \
	sql << " AND spec=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->spec.getValue("")); \
} \
if (query->code) { \
	sql << " AND code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->code.getValue("")); \
}\
if (query->is_print) {\
	\
		sql << " AND `is_print`=?"; \
		SQLPARAMS_PUSH(params, "i",  int, query->is_print.getValue(0)); \
} \
if (query->capacity) {\
	\
		sql << " AND capacity=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->capacity.getValue("")); \
} \
if (query->barcode_num) {\
	\
		sql << " AND barcode_num=?"; \
		SQLPARAMS_PUSH(params, "i", int, query->barcode_num.getValue(0)); \
}\
if (query->need_take_blood) {\
	\
		sql << " AND `need_take_blood`=?"; \
		SQLPARAMS_PUSH(params, "i", int, query->need_take_blood.getValue(0)); \
} \
if (query->order_num) {\
	\
		sql << " AND order_num=?"; \
		SQLPARAMS_PUSH(params, "f",float, query->order_num.getValue(0)); \
} \
if (query->liscode) {\
	\
		sql << " AND liscode=?"; \
		SQLPARAMS_PUSH(params, "s",std::string, query->liscode.getValue("")); \
}



uint64_t SampleDAO::count(const SampleQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM sample";
	SqlParams params; sql << " WHERE 1=1"; if (query->name) {
		sql << " AND `name`=?"; params.emplace_back(SqlParam("s", std::make_shared<std::string>(query->name.getValue(""))));
	} if (query->sex) {
		sql << " AND sex=?"; params.emplace_back(SqlParam("s", std::make_shared<std::string>(query->sex.getValue(""))));
	} if (query->age) {
		sql << " AND age=?"; params.emplace_back(SqlParam("i", std::make_shared<int>(query->age.getValue(0))));
	};
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}



std::list<SampleDO> SampleDAO::selectWithPage(const SampleQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT id,name,sex,age FROM sample";
	SqlParams params; sql << " WHERE 1=1"; if (query->name) {
		sql << " AND `name`=?"; params.emplace_back(SqlParam("s", std::make_shared<std::string>(query->name.getValue(""))));
	} if (query->sex) {
		sql << " AND sex=?"; params.emplace_back(SqlParam("s", std::make_shared<std::string>(query->sex.getValue(""))));
	} if (query->age) {
		sql << " AND age=?"; params.emplace_back(SqlParam("i", std::make_shared<int>(query->age.getValue(0))));
	};
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	SampleMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<SampleDO, SampleMapper>(sqlStr, mapper, params);
}

std::list<SampleDO> SampleDAO::selectByName(const string& name)
{
	string sql = "SELECT id,name,sex,age FROM sample WHERE `name` LIKE CONCAT('%',?,'%')";
	SampleMapper mapper;
	return sqlSession->executeQuery<SampleDO, SampleMapper>(sql, mapper, "%s", name);
}

uint64_t SampleDAO::insert(const SampleDO& iObj)
{
	string sql = "INSERT INTO `sample` (`name`, `sex`, `age`) VALUES (?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getName(), iObj.getSex(), iObj.getAge());
}

int SampleDAO::update(const SampleDO& uObj)
{
	string sql = "UPDATE `sample` SET `name`=?, `sex`=?, `age`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getName(), uObj.getSex(), uObj.getAge(), uObj.getId());
}

int SampleDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `sample` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}