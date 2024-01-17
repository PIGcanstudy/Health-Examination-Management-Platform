#pragma once

#ifndef _BASEPROJECTCONTROLLER_H_
#define _BASEPROJECTCONTROLLER_H_

#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/baseproject/AddBaseProjectVO.h"
#include "domain/vo/baseproject/SelectBaseProjectVO.h"
#include "domain/vo/baseproject/SelectBaseProjectListVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class BaseProjectController :public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(BaseProjectController);
public:// ����ӿ�
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addBaseProject) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("baseproject.post.addBaseProject"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/baseproject/add-baseproject", addBaseProject, BODY_DTO(AddBaseProjectDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddBaseProject(dto));
	}

	ENDPOINT_INFO(selectBaseProject) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("baseproject.post.selectBaseProject"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/baseproject/select-baseproject", selectBaseProject, BODY_DTO(SelectBaseProjectDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execSelectBaseProject(dto));
	}

private:// ����ӿ�ִ�к���
	//��������
	Uint64JsonVO::Wrapper execAddBaseProject(const AddBaseProjectDTO::Wrapper& dto);
	//ɾ������
	Uint64JsonVO::Wrapper execSelectBaseProject(const SelectBaseProjectDTO::Wrapper& dto);
	//�޸�����
	//Uint64JsonVO::Wrapper execSelectBaseProjectList(const SelectBaseProjectListDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_BASEPROJECTCONTROLLER_H_