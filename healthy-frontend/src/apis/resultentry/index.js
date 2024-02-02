import Request from '@/apis/request.js'
const baseUrl = 'http://localhost:10100/api'

/**
 * c++
 * 结果录入-c6 
 * API接口服务 
 * zlw
 */

// 新增诊台结果
export const addDepartRes = (params) => {
  return Request.requestJson(
    Request.POST,
    baseUrl + '/addDepartRes',
    params
  )
}

// 到检确认
export const addRPProCheck = (params) => {
  return Request.requestJson(
    Request.POST,
    baseUrl + '/addRPProCheck',
    params
  )
}

// 弃检项目
export const waiveCheck = (params) => {
    return Request.requestJson(
      Request.PUT,
      baseUrl + '/waiveCheck',
      params
    )
  }

  
//查询体检人员列表
export const queryList = (params) => {
    return Request.requestForm(
      Request.GET,
      baseUrl + '/groupPerson/query/list',
      params
    )
  }


//取消弃检
export const clAbanProj = (params) => {
    return Request.requestJson(
      Request.PUT,
      baseUrl + '/result-entry/cl-aban-proj',
      params
    )
  }

//基本信息查询
export const queryBasicInfoMation = (params) => {
    return Request.requestForm(
      Request.GET,
      baseUrl + '/unknownmodulebasicinformation/queryBasicInfoMation',
      params
    )
  }

//生活史查询
export const queryLifeHistory = (params) => {
    return Request.requestForm(
      Request.GET,
      baseUrl + '/unknownmodulelifehistory/queryLifeHistory',
      params
    )
  }

//既往病史查询
export const queryPastMedicalHistory = (params) => {
    return Request.requestForm(
      Request.GET,
      baseUrl + '/unknownmodulepastmedicalhistory/queryPastMedicalHistory' + params
    )
  }

//职业史查询
export const queryProfessionalHistory = (params) => {
    return Request.requestForm(
      Request.GET,
      baseUrl + '/unknownmoduleprofessionalhistory/queryProfessionalHistory',
      params
    )
  }

//保存症状询问
export const Interro = (params) => {
    return Request.requestJson(
      Request.POST,
      baseUrl + '/c6-resultentry/Interro',
      params
    )
  }

//样本条码查看
export const barcod = (params) => {
    return Request.requestJson(
      Request.POST,
      baseUrl + '/healthy-c6-resultentry/barcod' + params,
    )
  }

//报告预览
export const report = (params) => {
    return Request.requestJson(
      Request.POST,
      baseUrl + '/healthy-c6-resultentry/report' + params,
    )
  }


//查询组合项目的基础项目体检效果数据
export const baseproject = (params) => {
    return Request.requestForm(
      Request.GET,
      baseUrl + '/checkitem/query-baseproject' + params,
    )
  }

//查询人员的体检组合项目
export const queryPerson = (params) => {
    return Request.requestForm(
      Request.GET,
      baseUrl + '/checkitem/query-person' + params,
    )
  }

    //查询组合项目的基础项目体检效果数据
export const uploadxxx = (params) => {
    return Request.requestForm(
      Request.PUT,
      baseUrl + '/filexxx/uploadxxx' + params,
    )
  }


