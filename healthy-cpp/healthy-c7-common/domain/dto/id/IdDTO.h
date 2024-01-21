#pragma once
#ifndef _IDDTO_H_
#define _IDDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
*  ��ѯid����������ɾ�����޸� �������ݶ���ʵ��
*/
class IdDTO : public oatpp::DTO
{
	DTO_INIT(IdDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("id.field.id"));
};

/**
*  ��ѯid����������ɾ�����޸�   ��ҳ����ʵ��
*/
class IdPageDTO : public PageDTO<IdDTO::Wrapper> {
	DTO_INIT(IdPageDTO, PageDTO<IdDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_IDDTO_H_