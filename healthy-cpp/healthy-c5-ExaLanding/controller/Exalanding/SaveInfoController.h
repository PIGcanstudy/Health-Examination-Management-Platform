#pragma once
#ifndef _SAVE_INFO_CONTROLLER_H_
#define _SAVE_INFO_CONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/Exalanding/SaveInfoQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/Exalanding/SaveInfoVO.h"
#include "domain/dto/Exalanding/SaveInfoDTO.h"
//#include "domain/vo/user/MenuVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class SaveInfoController : public oatpp::web::server::api::ApiController
{
	// 2 ����������������
	API_ACCESS_DECLARE(SaveInfoController);
	// 3 ����ӿ�
public:
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addUserInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("exalanding.saveinfo.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/exalanding", addUserInfo, BODY_DTO(SaveInfoDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddUserInfo(dto));
	}
	
private:
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddUserInfo(const SaveInfoDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _SAVE_INFO_CONTROLLER_H_