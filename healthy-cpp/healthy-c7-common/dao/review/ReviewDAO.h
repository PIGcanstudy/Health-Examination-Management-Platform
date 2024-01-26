#pragma once
#ifndef _REVIEW_DAO_
#define _REVIEW_DAO_
#include "BaseDAO.h"
#include "../../domain/do/review/ReviewDO.h"
#include "../../domain/query/review/ReviewQuery.h"

/**
 * 复查记录表数据库操作实现
 */
class ReviewDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ReviewQuery::Wrapper& query);
	// 分页查询数据
	list<ReviewDO> selectWithPage(const ReviewQuery::Wrapper& query);
	// 通过姓名查询数据
	//list<ReviewDO> selectByName(const string& name);
	//此处不需要下面的东西吧？？？？？？？？？？？？？？？？？？？？
	// 插入数据    在AddNewItems中实现 增加功能，此处应删除
	//uint64_t insert(const ReviewDO& iObj);
	// 修改数据
	//int update(const ReviewDO& uObj);
	// 通过ID删除数据
	//int deleteById(uint64_t id);//id是string类型??????????????????????
};
#endif // !_REVIEW_DAO_