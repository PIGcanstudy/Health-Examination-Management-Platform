#include "stdafx.h"
#include "InspectionDAO.h"
#include "InspectionMapper.h"
#include <sstream>


// 定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
if (query->test_num) { \
	sql << " AND `test_num`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->test_num.getValue("")); \
} \
if (query->id_card) { \
	sql << " AND id_card=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id_card.getValue("")); \
} \
if (query->person_name) { \
	sql << " AND person_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->person_name.getValue("")); \
} \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
} \
if (query->check_date) { \
	sql << " AND check_date=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->check_date.getValue("")); \
} \
if (query->physical_unit) { \
	sql << " AND physical_unit=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->physical_unit.getValue("")); \
} \
if (query->statu) { \
	sql << " AND statu=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->statu.getValue(0)); \
}

uint64_t ReportListDAO::count(const ReportListQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_group_person g,t_unit_report u WHERE g.order_id=u.order_id";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<ReportListDO> ReportListDAO::selectWithPage(const ReportListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT test_num,id_card,person_name,sex,age,check_date,check_result,physical_unit,statu FROM t_group_person g,t_unit_report u WHERE g.order_id=u.order_id";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ReportListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ReportListDO, ReportListMapper>(sqlStr, mapper, params);
}

list<ReportListDO> ReportListDAO::selectByTest_num(const string& test_num)
{
	string sql = "SELECT test_num,id_card,person_name,sex,age,check_date,check_result,physical_unit,statu FROM t_group_person g,t_unit_report u WHERE g.order_id=u.order_id AND `test_num` = ?";
	ReportListMapper mapper;
	return sqlSession->executeQuery<ReportListDO, ReportListMapper>(sql,mapper,"%s",test_num);
}

list<ReportListDO> ReportListDAO::selectByPhysical_unit(const string& physical_unit)
{
	string sql = "SELECT test_num,id_card,person_name,sex,age,check_date,check_result,physical_unit,statu FROM t_group_person g,t_unit_report u WHERE g.order_id=u.order_id WHERE `physical_unit` = ?";
	ReportListMapper mapper;
	return sqlSession->executeQuery<ReportListDO, ReportListMapper>(sql, mapper, "%s", physical_unit);
}

list<ReportListDO> ReportListDAO::selectById_card(const string& id_card)
{
	string sql = "SELECT test_num,id_card,person_name,sex,age,check_date,check_result,physical_unit,statu FROM t_group_person g,t_unit_report u WHERE g.order_id=u.order_id WHERE `id_card` = ?";
	ReportListMapper mapper;
	return sqlSession->executeQuery<ReportListDO, ReportListMapper>(sql, mapper, "%s", id_card);
}

list<ReportListDO> ReportListDAO::selectByCheck_date(const string& check_date)
{
	string sql = "SELECT test_num,id_card,person_name,sex,age,check_date,check_result,physical_unit,statu FROM t_group_person g,t_unit_report u WHERE g.order_id=u.order_id WHERE `check_date` = ?";
	ReportListMapper mapper;
	return sqlSession->executeQuery<ReportListDO, ReportListMapper>(sql, mapper, "%s", check_date);
}

list<ReportListDO> ReportListDAO::selectByStatu(const int& statu)
{
	string sql = "SELECT test_num,id_card,person_name,sex,age,check_date,check_result,physical_unit,statu FROM t_group_person g,t_unit_report u WHERE g.order_id=u.order_id WHERE `statu` = ?";
	ReportListMapper mapper;
	return sqlSession->executeQuery<ReportListDO, ReportListMapper>(sql, mapper, "%i", statu);
}

list<ReportListDO> ReportListDAO::selectByName(const string& name)
{
	string sql = "SELECT test_num,id_card,person_name,sex,age,check_date,check_result,physical_unit,statu FROM t_group_person g,t_unit_report u WHERE g.order_id=u.order_id WHERE `name` = ?";
	ReportListMapper mapper;
	return sqlSession->executeQuery<ReportListDO, ReportListMapper>(sql, mapper, "%s", name);
}

list<ReportListDO> ReportListDAO::selectBySex(const string& sex)
{
	string sql = "SELECT test_num,id_card,person_name,sex,age,check_date,check_result,physical_unit,statu FROM t_group_person g,t_unit_report u WHERE g.order_id=u.order_id WHERE `sex` = ?";
	ReportListMapper mapper;
	return sqlSession->executeQuery<ReportListDO, ReportListMapper>(sql, mapper, "%s", sex);
}

list<ReportListDO> ReportListDAO::selectByAge(const int& age)
{
	string sql = "SELECT test_num,id_card,person_name,sex,age,check_date,check_result,physical_unit,statu FROM t_group_person g,t_unit_report u WHERE g.order_id=u.order_id WHERE `age` = ?";
	ReportListMapper mapper;
	return sqlSession->executeQuery<ReportListDO, ReportListMapper>(sql, mapper, "%i", age);
}
