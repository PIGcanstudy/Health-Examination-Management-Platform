#pragma once
#ifndef _ADDNEWITEMS_DAO_
#define _ADDNEWITEMS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/addNewItems/AddNewItemsDO.h"
#include "../../domain/query/addNewItems/AddNewItemsQuery.h"

/**
 * 新增复查记录表数据库操作实现
 */
class AddNewItemsDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const AddNewItemsQuery::Wrapper& query);
	// 分页查询数据
	list<AddNewItemsDO> selectWithPage(const AddNewItemsQuery::Wrapper& query);
	// 通过姓名查询数据
	list<AddNewItemsDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const AddNewItemsDO& iObj);
	// 修改数据
	//int update(const AddNewItemsDO& uObj);
	// 通过ID删除数据
	//int deleteById(uint64_t id);//id是string类型??????????????????????
};
#endif // !_ADDNEWITEMS_DAO_