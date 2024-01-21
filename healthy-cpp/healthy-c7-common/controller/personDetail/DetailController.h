#pragma once
#ifndef _DETAILCONTROLLER_H_
#define _DETAILCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/personDetail/DetailVO.h"
#include "../../domain/query/personDetail/DetailQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class DetailController : public oatpp::web::server::api::ApiController
{
    // ����������������
    API_ACCESS_DECLARE(DetailController);
public: // ����ӿ�
    // �����ҳ��ѯ��λ�б�ӿ�����
    ENDPOINT_INFO(queryDetail) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.field.project"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(DetailJsonVO);
        // �����ҳ��ѯ��������
        //API_DEF_ADD_PAGE_PARAMS();
        // ����������ѯ��������
        //API_DEF_ADD_QUERY_PARAMS(String, "physicalExamNumber", ZH_WORDS_GETTER("unit.field.physicalExamNumber"), "13", true);
        //API_DEF_ADD_QUERY_PARAMS(String, "identityCardNumber", ZH_WORDS_GETTER("unit.field.identityCardNumber"), "18", false);
        API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("unit.field.name"), "xxx", false);
        API_DEF_ADD_QUERY_PARAMS(String, "gender", ZH_WORDS_GETTER("unit.field.gender"), "man", false);
        API_DEF_ADD_QUERY_PARAMS(UInt32, "age", ZH_WORDS_GETTER("unit.field.age"), 1, false);
        //API_DEF_ADD_QUERY_PARAMS(String, "phoneNumber", ZH_WORDS_GETTER("unit.field.phoneNumber"), "123456789", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "organizationName", ZH_WORDS_GETTER("unit.field.organizationName"), "xxx", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "registrationTime", ZH_WORDS_GETTER("unit.field.registrationTime"), "xx xx xx", false);
        
    }
    // �����ҳ��ѯ��λ�б�ӿ�
    ENDPOINT(API_M_GET, "/personDetail/query-detail", queryDetail, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
        // ������ѯ����ΪQuery����ģ��
        API_HANDLER_QUERY_PARAM(uq, DetailQuery, params);
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execQueryUnit(uq));
    }
private: // ����ӿ�ִ�к���
    DetailJsonVO::Wrapper execQueryUnit(const DetailQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_DETAILCONTROLLER_H_