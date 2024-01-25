#include "UpdateTBPDAO.h"
#include "stdafx.h"
#include "SampleMapper.h"
#include <sstream>

int UpdateTBPDAO::UpdateTBP(const UpdateTBPDO& uObj)
{

    // ����ϵͳʱ�䴴��create_time
    std::time_t now = std::time(0); // ��ȡ����ʱ��
    std::tm* timeinfo = localtime(&now); // ת��Ϊ����ʱ���tm�ṹ��
    std::stringstream ss; // ����һ���ַ���������
    ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S"); // ��tm�ṹ���ʽ��Ϊ�ַ�����
    std::string create_time = ss.str(); // ���ַ������л�ȡ�ַ���


    string sql = "UPDATE `t_base_project` SET `office_id`=?, `code`=?, `name`=?,\
                   `short_name`=?, `order_num`=?, `result_type`=?,\
                   `unit_name`=?, `default_value`=?, `in_conclution`=?,\
                   `inreport`=?, `relation_code`=?, `create_id`=?,\
                  WHERE `code`=?";
    return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%dt",
        uObj.getOffice_id(), uObj.getCode(), uObj.getName(),
        uObj.getShort_name(),uObj.getOrder_num(), uObj.getResult_type(),
        uObj.getUnit_name(),uObj.getDefault_value(),uObj.getIn_conclution(),
        uObj.getInreport(), uObj.getRelation_code(), create_time);
}
