#pragma once
#ifndef _SAVE_INF_DTO_H_
#define _SAVE_INF_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个修改用户信息的数据传输模型
 */
class SaveInfoDTO : public oatpp::DTO
{
	DTO_INIT(SaveInfoDTO, DTO);
	// 身份证号
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("exalanding.saveinfo.field.id_card"));
	//姓名
	API_DTO_FIELD_DEFAULT(String, person_name, ZH_WORDS_GETTER("exalanding.saveinfo.field.person_name"));
	//性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("exalanding.saveinfo.field.sex"));
	//年龄
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("exalanding.saveinfo.field.age"));
	//联系电话
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("exalanding.saveinfo.field.mobile"));
	//婚姻状态
	API_DTO_FIELD_DEFAULT(String, is_marry, ZH_WORDS_GETTER("exalanding.saveinfo.field.is_marry"));
};

/**
 * 定义一个用户信息分页传输对象
 */
class SaveInfoPageDTO : public PageDTO<SaveInfoDTO::Wrapper>
{
	DTO_INIT(SaveInfoPageDTO, PageDTO<SaveInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _SAVE_INF_DTO_H_