#pragma once

#ifndef _PERSONALREVIEW_CONTROLLER_
#define _PERSONALREVIEW_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/personalReview/PersonalReviewDTO.h"
//#include "../../healthy-cpp/lib-oatpp/include/ApiHelper.h"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class PersonalReviewController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PersonalReviewController);

public:

	// 3.1 �����޸Ľӿ�����
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("groupItemIgno.update.summary"), updateItem, Uint64JsonVO::Wrapper);
		// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(updateGroupPerson) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("personalReview.update.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("personalReview.field.personId"), "0000 <- failtest", true);
		API_DEF_ADD_QUERY_PARAMS(String, "updateId", ZH_WORDS_GETTER("personalReview.field.updateId"), "3478237482374", true);

	}



	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/personalReview", updateGroupPerson, BODY_DTO(PersonalReviewDTO::Wrapper, dto), execPersonalReview(dto));

private:

	// 3.3 ��ʾ�޸�����
	StringJsonVO::Wrapper execPersonalReview(const PersonalReviewDTO::Wrapper& dto);

};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_