#pragma once
#ifndef _IDVO_H_
#define _IDVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/id/IdDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*  ��ѯid����������ɾ�����޸�  ��ʾJsonVOʵ��
*/
class IdJsonVO : public JsonVO<IdDTO::Wrapper> {
	DTO_INIT(IdJsonVO, JsonVO<IdDTO::Wrapper>);
};

/**
 * ��ѯid����������ɾ�����޸�  ��ʾ��ҳJsonVO
 */
class IdPageJsonVO : public JsonVO<IdPageDTO::Wrapper> {
	DTO_INIT(IdPageJsonVO, JsonVO<IdPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_IDVO_H_