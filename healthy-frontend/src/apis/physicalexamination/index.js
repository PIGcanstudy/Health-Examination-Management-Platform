import Request from '@/apis/request.js'
const baseUrl = ''

// 修改基础数据中指定项目的指定参考值
export const modifyreference = (params) => {
    return Request.requestJson(Request.PUT, baseUrl + '/base/modifyReference', params)
  }
  // 删除基础数据中指定项目的指定参考值
  export const removereference = (params) => {
    return Request.requestJson(Request.DELETE, baseUrl + '/base/removereRerence', params)
  }
//   基础项目-配置指定项目-规则-获取指定规则列表（获取一个）
  export const queryall = (params) => {
    return Request.requestForm(Request.GET, baseUrl + '/rules/query-all', params)
  }
//   基础项目-配置指定项目-规则-获取指定规则列表（获取所有）
  export const queryrules = (params) => {
    return Request.requestForm(Request.GET, baseUrl + '/rules/query-rules', params)
  }
//   基础项目-配置指定项目-规则-修改指定规则列表
  export const modifyrules = (params) => {
    return Request.requestJson(Request.PUT, baseUrl + '/rules/modify-rules', params)
  }
//   获取指定项目危机值列表详情
  export const getlistdetails = (params) => {
    return Request.requestForm(Request.GET, baseUrl + '/database', params)
  }
//   新增指定项目危机值
  export const addlistdetails = (params) => {
    return Request.requestJson(Request.POST, baseUrl + '/database', params)
  }
// 基础项目-新增项目
  export const addproject = (params) => {
    return Request.requestJson(Request.POST, baseUrl + '/commen/baseproject/add -baseproject', params)
  }

  export const selectproject = (params) => {
    return Request.requestForm(Request.GET, baseUrl + '/commen/baseproject/select-baseproject', params)
  }
// 基础数据-获取项目列表
export const getproject = (params) => {
    return Request.requestForm(Request.GET, baseUrl + '/commen/baseproject/select-baseprojectlist', params)
  }
//   新增指定项目参考值
export const addvalue = (params) => {
    return Request.requestJson(Request.POST, baseUrl + '/commen/relationProject/AddReferenceValue', params)
  }
// 获取指定项目指定参考值详情
export const getvalue = (params) => {
    return Request.requestForm(Request.GET, baseUrl + '/commen/relationProject/QueryReferenceValue', params)
  }
//   基础项目-新增套餐
export const newpackage = (params) => {
    return Request.requestJson(Request.POST, baseUrl + '/combo/add-pack', params)
  } 
//   基础项目-删除套餐
export const deletepackage = (params) => {
    return Request.requestJson(Request.DELETE, baseUrl + '/combo/del-pack', params)
  } 
//   基础项目-修改套餐
export const modifypackage = (params) => {
    return Request.requestJson(Request.POST, baseUrl + '/combo/update-pack', params)
  } 
// 体检套餐-获取职业禁忌证术语列表
  export const getlist = (params) => {
    return Request.requestForm(Request.GET, baseUrl + '/basis/query-contraindications', params)
  } 
//   体检套餐-获取套餐名称列表
  export const getpackagelist = (params) => {
    return Request.requestForm(Request.GET, baseUrl + '/basis/query-package', params)
  } 
//   del-TBP
export const deltbp = (params) => {
    return Request.requestJson(Request.DELETE, baseUrl + '/combo/del-TBP', params)
  } 

  export const updatetbp = (params) => {
    return Request.requestJson(Request.POSTE, baseUrl + '/combo/update-TBP', params)
  } 
//   基础项目-配置指定项目-危机值-删除指定项目指定危机值
  export const deletepackagerisis = (params) => {
    return Request.requestJson(Request.DELETE, baseUrl + '/critical/query-delete-critical', params)
  } 
  //   基础项目-配置指定项目-危机值-修改指定项目指定危机值
  export const modifypackagerisis = (params) => {
    return Request.requestJson(Request.PUT, baseUrl + '/critical', params)
  } 
  