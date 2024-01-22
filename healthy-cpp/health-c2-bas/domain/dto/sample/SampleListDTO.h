#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _SAMPLE_DTO_
#define _SAMPLE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 样本列表传输数据对象实例
 */
class SampleDTO : public oatpp::DTO
{
	DTO_INIT(SampleDTO, DTO);
	
	// 编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("sample.field.id"));
	
	//名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("sample.field.name"));
	
	// 条码份数
	API_DTO_FIELD_DEFAULT(UInt32, barcode_num, ZH_WORDS_GETTER("sample.field.barcode_num"));

	//规格
	API_DTO_FIELD_DEFAULT(String, spec, ZH_WORDS_GETTER("sample.field.spec"));

	//是否采血
	API_DTO_FIELD_DEFAULT(UInt32, need_take_blood, ZH_WORDS_GETTER("sample.field.need_take_blood"));

	//样本代码
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("sample.field.code"));
	
	//排序
	API_DTO_FIELD_DEFAULT(Float32, order_num, ZH_WORDS_GETTER("sample.field.order_num"));

	//是否打印
	API_DTO_FIELD_DEFAULT(UInt32, is_print, ZH_WORDS_GETTER("sample.field.is_print"));
	
	//关联码
	API_DTO_FIELD_DEFAULT(String, liscode, ZH_WORDS_GETTER("sample.field.liscode"));
	
	//容量
	API_DTO_FIELD_DEFAULT(String, capacity, ZH_WORDS_GETTER("sample.field.capacity"));

};

/**
 * 分页传输对象
 */
class SamplePageDTO : public PageDTO<SampleDTO::Wrapper>
{
	DTO_INIT(SamplePageDTO, PageDTO<SampleDTO::Wrapper>);
};

/*
* 
*/
/**/

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_