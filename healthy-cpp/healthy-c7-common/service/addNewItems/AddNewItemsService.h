#pragma once
#ifndef _ADDNEWITEMS_SERVICE_
#define _ADDNEWITEMS_SERVICE_
#include <list>
#include "domain/vo/addNewItems/AddNewItemsVO.h"
#include "domain/query/addNewItems/AddNewItemsQuery.h"
#include "domain/dto/addNewItems/AddNewItemsDTO.h"

/**
 * 基础的新增复查记录服务实现
 */
class AddNewItemsService
{
public:
	//查询在Review中进行，此处应删除
	// 分页查询所有数据
	//AddNewItemsPageDTO::Wrapper listAll(const AddNewItemsQuery::Wrapper& query);
	// 保存数据  增加
	uint64_t saveData(const AddNewItemsDTO::Wrapper& dto);
	//下面可删除？？？？？？？
	// 修改数据
	//bool updateData(const AddNewItemsDTO::Wrapper& dto);
	// 通过ID删除数据
	//bool removeData(uint64_t id);
};

#endif // !_ADDNEWITEMS_SERVICE_