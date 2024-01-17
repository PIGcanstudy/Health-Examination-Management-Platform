#pragma once
#ifndef _MODIFY_RESULT_CONTROLLER_H_
#define _MODIFY_RESULT_CONTROLLER_H_

#include "domain/dto/positive/ModifyResultDTO.h"
#include "domain/vo/positive/ModifyResultVO.h"
#include "../../domain/query/positive/ModifyResult.h"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ModifyResultController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
    //������������ʽӿ�
    API_ACCESS_DECLARE(ModifyResultController);
    //����ӿ�
public:
	//  �����޸Ľӿ�����
	ENDPOINT_INFO(modifyResult) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("deatil.get.summary"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ModifyResultJasonVO);
		// �����ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// �����ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt32, "id", ZH_WORDS_GETTER("deatil.field.id"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("deatil.field.name"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "namePinYin", ZH_WORDS_GETTER("deatil.field.namePinYin"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "degree", ZH_WORDS_GETTER("deatil.field.degree"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "positive", ZH_WORDS_GETTER("deatil.field.positive"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "section_name", ZH_WORDS_GETTER("deatil.field.section_name"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "advise", ZH_WORDS_GETTER("deatil.field.advise"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "healthKnowledge", ZH_WORDS_GETTER("deatil.field.healthKnowledge"), "N", false);
	}
	//�����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/positive/modify-resulot", modifyResult, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		//������ѯ���� 
		API_HANDLER_QUERY_PARAM(mr, ModifyResult, params);
		//����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execModifyResult(mr));
	}

	
private:
	ModifyResultJasonVO::Wrapper execModifyResult(const ModifyResult::Wrapper& modify);
};

    // 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MODIFYRESULTCONTROLLER_H_