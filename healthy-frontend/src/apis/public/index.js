import Request from '@/apis/request.js'
const baseUrl = ''

//获取字典数据名称列表（用于输入表单下拉列表）
export const queryDictnameListApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/common/query-dictnamelist')
}

//获取工种名称列表（分页＋条件）
export const queryJobnameListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/common/query-jobnamelist', params)
}

//获取组合项目列表（条件＋分页）
export const queryPackageProlistApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/common/query-packageprolist', params)
}

//获取组合项目名称列表（用于输入表单下拉列表）
export const queryPackagePronamelistApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/common/query-packagepronamelist')
}

//获取套餐名称列表（条件+分页）
export const queryPlannameListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/common/query-plannamelist', params)
}

//获取套餐组合项目列表
export const queryPlanProlistApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/', params)
}

//科室名称列表
export const querySelectionnameListApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/common/query-planprolist')
}

//获取术语名称列表（条件+分页）
export const queryTermnameListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/common/query-sectionnamelist', params)
}

//获取类型树
export const queryTypeTreeApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/common/query-typetree')
}

//获取用户名称列表（用于输入表单下拉列表框）
export const queryUesrnameListApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/common/query-uesrnamelist', params)
}
