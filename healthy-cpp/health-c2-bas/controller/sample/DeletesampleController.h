#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/sample/DeleteSampleQuery.h"
#include "domain/dto/sample/DeleteSampleDTO.h"
#include "domain/vo/sample/DeleteSampleVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class DeleteSampleController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DeleteSampleController);
	// 3 ����ӿ�
public:

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeSample) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("sample.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("sample.field.id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/sample/{id}", removeSample, PATH(UInt64, id), execRemoveSample(id));

	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemoveSample(const UInt64& id);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_