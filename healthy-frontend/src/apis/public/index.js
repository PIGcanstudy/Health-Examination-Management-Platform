import Request from '@/apis/request.js'
import { get } from 'echarts/lib/CoordinateSystem'
const baseUrl = ''

//获取字典数据名称列表（用于输入表单下拉列表）
export const  getDictnameListApi = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '/common/query-dictnamelist',
  )
}

//获取工种名称列表（分页＋条件）
export const  getJobnameListApi = (params) => {
  return Request.requestForm(
    Request.GET,
    baseUrl + '/common/query-jobnamelist',
    params
  )
}

//获取组合项目列表（条件＋分页）
export const getPackageProlistApi = (params) => {
  return Request.requestForm(
    Request.GET,
    baseUrl + '/common/query-packageprolist',
    params
  )
}

//获取组合项目名称列表（用于输入表单下拉列表）
export const getPackagePronamelistApi = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '/common/query-packagepronamelist',
  )
}

//获取套餐名称列表（条件+分页）
export const getPlannameListApi = (params) => {
  return Request.requestForm(
    Request.GET,
    baseUrl + '/common/query-plannamelist',
    params
  )
}

//获取套餐组合项目列表
export const getPlanProlistApi = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '/common/query-planprolist',
    params
  )
}

//科室名称列表
export const getSelectionnameListApi = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '/common/query-sectionnamelist',
  )
}


//获取术语名称列表（条件+分页）
export const getTermnameListApi = (params) => {
  return Request.requestForm(
    Request.GET,
    baseUrl + '/common/query-termnamelist',
    params
  )
}


//获取类型树
export const getTypeTreeApi = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '​/common​/query-typetree'
  )
}

//获取用户名称列表（用于输入表单下拉列表框）
export const getUesrnameListApi = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '/common/query-uesrnamelist',
    params
  )
}