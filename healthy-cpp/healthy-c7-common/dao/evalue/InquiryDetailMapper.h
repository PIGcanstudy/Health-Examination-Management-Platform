#pragma once
/*
Copyright Zero One Star. All rights reserved.

@Author: lenyan~
@Date: 2024/1/27

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
#ifndef _INQUIRYDETAIL_MAPPER
#define _INQUIRYDETAIL_MAPPER

#include "Mapper.h"
#include "../../domain/do/evalue/InquiryDetailDO.h"


// Œ ’Ô√˜œ∏±Ì◊÷∂Œ∆•≈‰”≥…‰
class InquiryDetailMapper : public Mapper<InquiryDetailDO> {
public:
	InquiryDetailDO mapper(ResultSet* resultSet) const override {
		InquiryDetailDO data;
		data.setId(resultSet->getString(1));
		data.setWorkYear(resultSet->getString(2));
		data.setWorkMonth(resultSet->getString(3));
		data.setIsMarry(resultSet->getString(4));
		data.setExposureWorkYear(resultSet->getString(5));
		data.setExposureWorkMonth(resultSet->getString(6));
		data.setEducation(resultSet->getString(7));
		data.setFamilyAddress(resultSet->getString(8));
		data.setWorkTypeText(resultSet->getString(9));
		data.setWorkName(resultSet->getString(10));
		data.setDepartment(resultSet->getString(11));
		return data;
	}
};
#endif // !_INQUIRYDETAIL_MAPPER