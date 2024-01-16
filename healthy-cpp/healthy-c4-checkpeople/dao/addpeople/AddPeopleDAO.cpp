/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "AddPeopleDAO.h"
#include "AddPeopleMapper.h"
#include <sstream>

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
	SQLPARAMS_PUSH(params, "i", std::string, query->age .getValue(1)); \
} \
if (query->is_marry) { \
	sql << " AND is_marry=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_marry.getValue("")); \
} \
if (query->mobile) { \
	sql << " AND mobile=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->mobile.getValue("")); \
} \


uint64_t AddPeopleDAO::insert(const AddDO& iObj)
{
	string sql = "INSERT INTO `t_group_person` (`person_name`, `sex`, `id_card`,`birth`, `age`, `is_marry`,`mobile`) VALUES (?, ?, ?,?,?,?,?)";
	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getpersonName(), iObj.getSex(), iObj.getidCard(), iObj.getBirth(), iObj.getAge(),
		iObj.getAge(), iObj.getisMarry(), iObj.getMobile());
}

