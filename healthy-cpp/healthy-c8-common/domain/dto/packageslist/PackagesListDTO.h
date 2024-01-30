#pragma once

#ifndef _COMMON_DTO_
#define _COMMON_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ�����Ŀ�б������
 */
class PackagesListDTO : public oatpp::DTO
{
	DTO_INIT(PackagesListDTO, DTO);
	// ���
	DTO_FIELD(String, keywords);
	DTO_FIELD_INFO(keywords) {
		info->description = ZH_WORDS_GETTER("common.field.keywords");
	}
};

/**
 * ��ȡ�����Ŀ�б��ҳ�������
 */
class PackagesListPageDTO : public PageDTO<PackagesListDTO::Wrapper>
{
	DTO_INIT(PackagesListPageDTO, PageDTO<PackagesListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif