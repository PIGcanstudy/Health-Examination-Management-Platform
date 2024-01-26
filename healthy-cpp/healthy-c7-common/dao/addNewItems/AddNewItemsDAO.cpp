#include "stdafx.h"
#include "AddNewItemsDAO.h"
#include "AddNewItemsMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define ADDNEWITEMS_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->checkProjectId) { \
	sql << " AND check_project_id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->checkProjectId.getValue("")); \
} \
if (query->checkProjectName) { \
	sql << " AND check_project_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->checkProjectName.getValue("")); \
} \
if (query->portfolioProjectId) { \
	sql << " AND portfolio_project_id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->portfolioProjectId.getValue("")); \
} \
if (query->portfolioProjectName) { \
	sql << " AND portfolio_project_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->portfolioProjectName.getValue("")); \
} \
if (query->reason) { \
	sql << " AND reason=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->reason.getValue("")); \
}
//查询在Review中进行，此处应删除
// 统计数据条数
//uint64_t AddNewItemsDAO::count(const AddNewItemsQuery::Wrapper& query)
//{
//	stringstream sql;
//	sql << "SELECT COUNT(*) FROM (SELECT a.check_project_id,a.check_project_name,b.portfolio_project_id,b.portfolio_project_name,b.reason FROM t_review_record AS a JOIN t_review_project AS b ON a.person_id = b.person_id) AS result_set";
//	ADDNEWITEMS_TERAM_PARSE(query, sql);
//	string sqlStr = sql.str();
//	return sqlSession->executeQueryNumerical(sqlStr, params);
//}
//// 分页查询数据
//list<AddNewItemsDO> AddNewItemsDAO::selectWithPage(const AddNewItemsQuery::Wrapper& query)
//{
//	stringstream sql;
//	sql << "SELECT a.check_project_id,a.check_project_name,b.portfolio_project_id,b.portfolio_project_name,b.reason FROM t_review_record AS a JOIN t_review_project AS b ON a.person_id = b.person_id;";
//	ADDNEWITEMS_TERAM_PARSE(query, sql);
//	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
//	AddNewItemsMapper mapper;
//	string sqlStr = sql.str();
//	return sqlSession->executeQuery<AddNewItemsDO, AddNewItemsMapper>(sqlStr, mapper, params);
//}
//// 通过姓名查询数据
//list<AddNewItemsDO> AddNewItemsDAO::selectByName(const string& name)
//{
//	string sql = "SELECT b.person_name,a.check_project_name,a.review_explain,a.review_time,a.create_time,a.state,b.hazard_factor_code FROM t_review_record AS a JOIN t_review_person AS b ON a.person_id = b.id WHERE b.person_name LIKE CONCAT('%', ? ,'%');";
//	//string sql = "SELECT id,person_id,check_project_id,check_project_name,review_explain,review_time,create_time,state FROM t_review_record WHERE `name` LIKE CONCAT('%',?,'%')";
//	AddNewItemsMapper mapper;
//	return sqlSession->executeQuery<AddNewItemsDO, AddNewItemsMapper>(sql, mapper, "%s", name);
//}
// 插入数据
uint64_t AddNewItemsDAO::insert(const AddNewItemsDO& iObj)
{
	string sql = "INSERT INTO `t_review_record` (`id`, `check_project_id`, `check_project_name`) VALUES (?, ?, ?)";
	sqlSession->executeInsert(sql, "%s%s%s", iObj.getId(), iObj.getCheckProjectId(), iObj.getCheckProjectName());
	const string sql1 = "SELECT COUNT(*) FROM t_review_record WHERE id="+iObj.getId();
	return sqlSession->executeQueryNumerical(sql1);
}
//uint64_t ReviewDAO::insert(const ReviewDO& iObj)
//{
//	string sql = "INSERT INTO `t_review_record` (`check_project_id`, `check_project_name`, `review_explain`) VALUES (?, ?, ?)";
//	//string sql = "INSERT INTO `t_review_record` (`name`, `sex`, `age`) VALUES (?, ?, ?)";
//	return sqlSession->executeInsert(sql, "%s%s%s", iObj.getCheckProjectId(), iObj.getCheckProjectName(), iObj.getReviewExplain());
//}
//此处不需要下面的东西吧？？？？？？？？？？？？
//// 修改数据
//int ReviewDAO::update(const ReviewDO& uObj)
//{
//	string sql = "UPDATE `t_review_record` SET `name`=?, `sex`=?, `age`=? WHERE `id`=?";
//	return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getName(), uObj.getSex(), uObj.getAge(), uObj.getId());
//}
//// 通过ID删除数据
//int ReviewDAO::deleteById(uint64_t id)
//{
//	string sql = "DELETE FROM `t_review_record` WHERE `id`=?";
//	return sqlSession->executeUpdate(sql, "%ull", id);
//}