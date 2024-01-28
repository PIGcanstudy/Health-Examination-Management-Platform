#pragma once
#ifndef _UNITPHYSICALEXAMINATIONORDERS_MAPPER_
#define _UNITPHYSICALEXAMINATIONORDERS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/unitreportlist/UnitPhysicalExaminationOrdersDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class UnitPhysicalExaminationOrdersMapper : public Mapper<UnitPhysicalExaminationOrdersDO>
{
public:
	UnitPhysicalExaminationOrdersDO mapper(ResultSet* resultSet) const override
	{
		UnitPhysicalExaminationOrdersDO data;
		data.setName(resultSet->getString(1));
		data.setCode(resultSet->getString(2));
		data.setSigningTime(resultSet->getString(3));
		cout <<"***" << resultSet->getInt(4)<<"\n";
		if (resultSet->getInt(4) == 1)//����1��ʾ���ݴ����δ��
		{
			cout << "&&&";
			data.setEscalation(ZH_WORDS_GETTER("unitreport.order.unreported"));
			cout << data.getEscalation();
		}
		else if (resultSet->getInt(4) == 2)//����2�������ѱ�
		{
			data.setEscalation(ZH_WORDS_GETTER("unitreport.order.reported"));
		}

		if (resultSet->getInt(5) == 0)//����0�������ż�
		{
			data.setDetectionType(ZH_WORDS_GETTER("unitreport.order.groupInspection"));
		}
		else if(resultSet->getInt(5) == 1) //����1��ʾ���������
		{
			data.setDetectionType(ZH_WORDS_GETTER("unitreport.order.sporadic"));
		}
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_